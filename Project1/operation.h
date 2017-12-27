#pragma once
#include <string>
#include <vector>
class FSObject;
using namespace std;
typedef string Text;
typedef vector <bool> Byte;
class File;
class Folder;
class FSOperation {
private:
	Text opName;
public:
	Text getName() { return opName; };
	virtual void execute()=0;
	FSOperation(Text op) { opName = op; }
};
class ReadFile:public FSOperation {
private:
	File *file;
	vector <bool> information;
public:
	ReadFile(File *f):FSOperation("createFolder") { file = f; };
	void execute();
	vector <bool>& getInformation() {
		return information;
	}
};
class WriteFile :public FSOperation {
private:
	File *file;
	vector <bool> *information;
public:
	WriteFile(File *f, Byte a) :FSOperation("createFolder") {
		file = f; 
		information = &a;
	};
	void execute();

};
class CreateDirectory:public FSOperation {
	Text fname;
	Folder *parent;
	Folder *final;
public:
	CreateDirectory(Text fName, Folder *p):FSOperation("createFolder") { fname = fName; parent = p; }
	void execute();
	Folder *getFolder() { return final; }
};
class CreateFile:public FSOperation {
	Text fname;
	Folder *parent;
	File *final;
public:
	CreateFile(Text &fName, Folder *p):FSOperation("createFolder") { fname = fName; parent = p; }
	void execute();
	File *getFolder() { return final; }
};

class DeleteObject :public FSOperation {
	DeleteObject(FSObject *f):FSOperation("createFolder") {
		delete f;
	}
	void excecute() {};
};
class ListDirectory :public FSOperation {
	vector<FSObject* >*x;
	Folder *fol;
public:
	ListDirectory(Folder *f):FSOperation("createFolder") {
		fol = f;
	}
	vector<FSObject* >& getObjects() { return *x; }
	void excecute();
};
class CopyPaste {
	FSObject *x;
public:
	CopyPaste(FSObject *a) { }
	FSObject& getObject() { return *x; }
	void excecute();
};
class Search {
	Text name;
	FSObject *log;

public:
	Search(Text a, FSObject *f) { name = a; }
	void execute(){}

};
class ProtectedOperation:public FSOperation {
public:
	bool checkPrecondition();
	FSOperation *wrappedOperation;
	vector<FSObject*> check;
public:
	ProtectedOperation(FSOperation *wrappedOp,vector <FSObject*>&c):FSOperation("createFolder") {
		for(int i=0;i<c.size();i++)
			check.push_back(c[i]);
		wrappedOperation = wrappedOp;
	}
	void execute() {
		if (checkPrecondition()) wrappedOperation->execute();
	}

};
