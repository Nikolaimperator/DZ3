#include "operation.h"
#include "FSObject.h"
#include "Exception.h"
void ReadFile::execute() {
	for (int i = 0; i < file->read().size(); i++) {
		information.push_back(file->read()[i]);
	}

}

void WriteFile::execute() {
	file->write(*information);
}
void CreateDirectory::execute() {
	Folder *x = new Folder(fname);
	x->parent=parent;
	final = x;
};
void CreateFile::execute() {
	File *x = new File(fname);
	x->parent = parent;
	final = x;
};
void ListDirectory::excecute() {
	x = &fol->getObjects();
};

void CopyPaste::excecute() { x = x->copy(); };

bool ProtectedOperation::checkPrecondition() {
	cout << "dadada\n\n\n\n";
	if (wrappedOperation->getName() == "createFolder") {
		if (!check[0]->getAccessDescriptor()->checkAccess("createFolder"))
			throw AccessException("don't have permission to createFolder");
	}
	return true;

}
