# Testing threads using std::thread of CPP17 

![Language]
![System]

Testing standart thread library, using C++17. This code simulates the process of generating data, send and receive data between two devices (C based microcontrolers). 

Threads are not the most performatic way to run such small tasks. It could be done with std::async, but the purpose is to simulate independent processes, as they would be different devices in reality. It is the best way using only Standart C++. Process can be created using POSIX fork(), or QT processes.

This code complements the [Union-RXTX-Packet](https://github.com/mateusns12/CPP-Union-RXTX-Packet-Structure) project, being used exclusively to test threading. Union-RXTX-Packet will use std::thread from C++20, to test jthread.

# Notes

	- Automatic lock/unlock not used, since variables never goes out of scope.
	- Using pooling method to verify state of data.
	- 'rand()' is not recomended and will be changed by functions in the <random> module.

# To-do

- [ ] Test 'std::condition_variable' to implement events, instead of pooling.
- [ ] Test thread call by lambda function
- [ ] Implement thread Handling
- [ ] Change rand() by uniform_int_distribution. 

[Language]: <https://img.shields.io/badge/Language-C++17-1AFFFF?style=for-the-badge&logo=cplusplus>

[System]: <https://img.shields.io/badge/System-Android_TERMUX-47D147?style=for-the-badge&logo=android>