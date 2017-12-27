#include "fsobject.h"
#include "visitor.h"
#include <queue>
using namespace std;
void SearchVisitor::visit(Folder *t) {
if(t->getName() == fileName) final.push_back(t);
	for (int i = 0; i < t->getObjects().size(); i++)
		t->getObjects()[i]->accept(*this);
}



void SearchVisitor::visit(File *t) {
	File *snake = t;
	if (t->getName() == fileName) final.push_back(t);
}


