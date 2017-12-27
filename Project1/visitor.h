#pragma once
#include <string>
using namespace std;
class Folder;
class File;
typedef string Text;
class FilesystemVisitor {
public:
	virtual void visit(File *v) = 0;
	virtual void visit(Folder *v) = 0;
};
class SearchVisitor :public FilesystemVisitor {

private:
	vector <FSObject*> final;
	Text fileName;
public:
	SearchVisitor(string c) {fileName = c;};
	void visit(File *t);
	void visit(Folder *t) ;
	vector <FSObject*>& getObjects() { return final; }

};

