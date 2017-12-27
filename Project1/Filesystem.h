#pragma once
#include "FSObject.h"
#include "operation.h"
#include <iostream>
using namespace std;
class Filesystem {
private:
	static Filesystem *instance;
	Folder *root;
	long int size;
	Filesystem() {
		root = new Folder("rootFolder");
		size = 100;
	}
public:

	Folder *createFolder(Text fName, Folder *parentFolder) {
		CreateDirectory c(fName,parentFolder);
		vector <FSObject*> x;
		x.push_back(parentFolder);
		ProtectedOperation a(&c, x);
		a.execute();
		return c.getFolder();
}
	static Filesystem* getInstance() {
		if (instance == nullptr)
			instance = new Filesystem();
		
		return instance;
}
	 

};

Filesystem* Filesystem::instance = nullptr;