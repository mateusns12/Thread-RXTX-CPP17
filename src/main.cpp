#include <thread>
#include <iostream>
#include <utility>
#include <chrono>
#include <cstdlib>
#include <mutex>

std::mutex data_mutex;
//not using std::lock_guard<std::mutex> guard(data_mutex) because the variables never goes out of scope. so it is necessary to manually lock and unlock

void Send(int& n,int& send){
	std::cout << "Sending TX packet ..." << std::endl;
	data_mutex.lock();
	int last_send = n;
	data_mutex.unlock();
	while(true){
		if(send != last_send){
			std::cout << "Sent " << send << " value " << std::endl;
		}
		last_send = send;
		data_mutex.lock();
		send = n;
		data_mutex.unlock();
		std::this_thread::sleep_for(std::chrono::milliseconds(50));
	}
}

void Receive(int& sent, int& recv){
	std::cout << "Reveiving RX packet .." << std::endl;
	data_mutex.lock();
	int last_recv = sent;
	data_mutex.unlock();
	while(true){
		if(recv != last_recv){
			std::cout << "updated: "<< recv  << std::endl;
		}
		last_recv = recv;
		data_mutex.lock();
		recv = sent;		
		data_mutex.unlock();
		//std::this_thread::sleep_for(std::chrono::milliseconds(50));
	}
}

//updating values every 5 seconds
void Device(int& n){
	for (int i = 0; i < 30; i++){
		data_mutex.lock();
		n = (rand()%11);
		data_mutex.unlock();
		std::this_thread::sleep_for(std::chrono::milliseconds(3000));
	}
}

int main(){
	int data = 0;
	int received = 0;
	int sent = 0;
	std::thread handle1(Send,std::ref(data),std::ref(sent));
	std::thread handle2(Receive,std::ref(sent),std::ref(received));
	std::thread handle3(Device,std::ref(data));
	handle1.join();
	handle2.join();
	handle3.join();
	return 0;
}

