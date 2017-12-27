#pragma once
#include <string>
#include <vector>
#include "accessdescriptor.h"
using namespace std;
typedef string Text;
typedef vector<bool> Byte;
class AccessDescriptor;
class FilesystemVisitor;
class Folder;
class FSObject {
protected:
	Text name;
	AccessDescriptor *book;
public:
	Folder *parent;
	void changeName(string c) { name = c; }
	string getName() { return name; }
	virtual void accept(FilesystemVisitor &) = 0;
	AccessDescriptor * getAccessDescriptor() { return book; }
	virtual long int size() = 0;
	virtual FSObject* copy() = 0;
	FSObject() {};
	virtual ~FSObject() { };
};
class File :public FSObject {
	Byte content;
public:
	Byte read() { return content; }
	void write(Byte &c) { for (int i = 0; i < c.size(); i++) content.push_back(c[i]); }
	long int size() { return content.size(); }
	~File();
	FSObject *copy();
	File(Text Name) {
		name = Name;
		book = new AccessDescriptor(this);
	}
	void accept(FilesystemVisitor &);

};
class Folder :public FSObject {
	vector <FSObject*> containedObjects;
	
public:

	Folder(Text Name) { name = Name; book = new AccessDescriptor(this); }
	void  accept(FilesystemVisitor &);
	vector<FSObject*>& getObjects() { return containedObjects; }
	void add(FSObject *a) { containedObjects.push_back(a); }
	void remove(FSObject *a)
	{ 
    int i = 0;
	while (a->getName() != containedObjects[i]->getName())i++; 
	if (i != containedObjects.size()) containedObjects.erase(containedObjects.begin() + i);
	}
	FSObject* copy();
	long int size();
	~Folder();
};
