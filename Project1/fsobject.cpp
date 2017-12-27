#include "fsobject.h"
#include "visitor.h"
#include "accessdescriptor.h"
#include <stack>
#include <queue>
#include <iostream>
using namespace std;
File::~File(){
	delete book;
	cout << name << "\n";
}

FSObject* File::copy(){
	File *x = new File(name);
	x->write(content);
	return x;
	/*for (int i = 0; i < book->getAllowedOperations().size(); i++)
		x->getAccessDescriptor()->add(book->getAllowedOperations()[i]);*/
}

FSObject* Folder::copy() {

	if (containedObjects.size() == 0) {
		Folder *x = new Folder(name);
		return x;
	}
	else {
		Folder *x = new Folder(name);
		for (int i = 0; i < containedObjects.size(); i++)
		{
			
			x->add(containedObjects[i]->copy());
		}
		return x;
	}
}
Folder::~Folder() {

	delete book;
	for (int i = 0; i < containedObjects.size(); i++)
	{
    delete containedObjects[i];
	}

}



void File::accept(FilesystemVisitor &v) {
	v.visit(this);
};
void Folder::accept(FilesystemVisitor &v) {
	v.visit(this);
}

long int Folder::size() {
	long int x = 0;
	for (int i = 0; i < containedObjects.size(); i++) { 
		x+= containedObjects[i]->size();
}
	return x;
};