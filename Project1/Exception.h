#pragma once
#include <exception>
#include <string>
#include <iostream>
using namespace std;
class FSException :public exception {
protected:
	string message;
public:
	FSException *causedBy;
	FSException(string msg) { message = msg; causedBy = nullptr; }
	FSException(string msg, FSException& c) { message = msg; causedBy = &c; }
	const char* what() {
		char *x = new char[message.size() + 1];
		memcpy(x, message.c_str(), message.size() + 1);
		return x;
	}
};
class AccessException :public FSException {
public:
	AccessException(string msg) :FSException(msg){}
	AccessException(string msg, FSException& c):FSException(msg,c) {}

};
class OperationFailedException :public FSException {
public:
	OperationFailedException(string msg) :FSException(msg) {}
	OperationFailedException(string msg, FSException& c) :FSException(msg, c) { }

};
class NameCollisionException :public OperationFailedException {
	NameCollisionException(string msg) :OperationFailedException(msg) {}
	NameCollisionException(string msg, FSException& c) :OperationFailedException(msg, c) { message = msg; causedBy = &c; }

};
class WriteFailedException :public OperationFailedException {
	WriteFailedException(string msg) :OperationFailedException(msg) {}
	WriteFailedException(string msg, FSException& c) :OperationFailedException(msg, c) { }

};