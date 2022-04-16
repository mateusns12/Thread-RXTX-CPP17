# Testing threads using std::thread of CPP17 

![Language](https://img.shields.io/badge/Language-C++17-1AFFFF?style=for-the-badge&logo=cplusplus)
![System](https://img.shields.io/badge/System-Android_TERMUX-47D147?style=for-the-badge&logo=android)

Testing standart thread library, using C++17. This code simulates the process of generating data, send and receive data between two devices (C based microcontrolers). 

This code complements the [Union-RXTX-Packet](https://github.com/mateusns12/CPP-Union-RXTX-Packet-Structure) project, being used exclusively to test threading. Union-RXTX-Packet will use std::thread from C++20, to test jthread.

# Notes

	- Automatic lock/unlock not used, since variables never goes out of scope.
	- Using pooling method to verify state of data.

# To-do

- [ ] Test 'std::condition_variable' to implement events, instead of pooling.
- [ ] Test thread call by lambda function
- [ ] Implement thread Handling
