#pragma once
class FSObject;
#include <string>
#include <vector>
using namespace std;
typedef string Text;
class AccessDescriptor {
	FSObject *ProtectedObject;
	vector <Text> allowedOperations;
public:
	void add(Text operationName) { allowedOperations.push_back(operationName); }
	void remove(Text &operationName) 
	{
		int i = 0;
		while (operationName != allowedOperations[i]) i++;
		if (i != allowedOperations.size()) allowedOperations.erase(i + allowedOperations.begin());

	}
	vector <Text> getAllowedOperations() { return allowedOperations; }
	
	/*AccessDescriptor(AccessDescriptor &c) {
		for (int i = 0; i < c.getAllowedOperations.size(); i++)
			allowedOperations.push_back(c.getAllowedOperations[i]);
	}*///copy constructor
	AccessDescriptor(FSObject *x) {
		ProtectedObject = x;
	}
	bool checkAccess(Text operationName) {
		if (allowedOperations.size() == 0) return false;
		int i = 0;
		while (operationName != allowedOperations[i]&&i<allowedOperations.size()) i++;
		if (i != allowedOperations.size()) return true;
		else return false;
}


};