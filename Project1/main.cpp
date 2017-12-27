#include "Filesystem.h"
#include <iostream>
#include "Exception.h"
using namespace std;
int main() {
	/*	vector <bool> astral;
		astral.push_back(1);
		astral.push_back(1);
		astral.push_back(1);
		astral.push_back(1);
		astral.push_back(1);
		vector <bool> astral2;
		astral2.push_back(1);
		astral2.push_back(1);
		astral2.push_back(1);
		vector <bool> astral3;
		astral3.push_back(1);
		astral3.push_back(1);

		Folder *F1 = new Folder("F1");
		Folder *F2= new Folder("F2");
		File *F = new File("F");
		F->write(astral);
		File *L = new File("L");
		L->write(astral2);
		File *O = new File("O");
		O->write(astral);
		O->write(astral2);
		File *L1 = new File("L1");
		L1->write(astral2);
		File *L2 = new File("L2");
		L2->write(astral2);
		Folder *F3 = new Folder("F3");
		Folder *F4 = new Folder("F4");
		Folder *F5 = new Folder("F5");
		Folder *F6 = new Folder("F6");
		Folder *F7 = new Folder("F7");
		Folder *F8 = new Folder("F8");
		Folder *F10 = new Folder("F11");
		Folder *F11= new Folder("F11");
		F6->add(F7);
		F6->add(F8);
		F6->add(F);
		F2->add(F4);
		F2->add(F5);
		F2->add(F6);
		F10->add(L);
		F10->add(L1);
		F10->add(L2);
		F3->add(F10);
		F1->add(F2);
		F1->add(O);
		F1->add(F3);
		F1->add(F11);

		FSObject *Fxy = F1->copy();*/

		//cout << F1->size();
		//delete F1;
		//cout << Fxy->getName();
		/*vector <int *>a;
		int o = 1, r = 2, s = 3;
		a.push_back(&o);
		a.push_back(&r);
		a.push_back(&s);
		a.erase(a.begin());
		cout << *a[0];
		cout << a.size();
		/*Folder *F1 = new Folder("F1");
		Folder *F2 = new Folder("F2");
		File *F = new File("F");
		delete F1;*/


		/*SearchVisitor v("F11");
		Fxy->accept(v);
		for (int i = 0; i < v.getObjects().size(); i++)
			cout << v.getObjects()[i]->getName();

		system("pause");
	}*/
	Filesystem *filesystem=Filesystem::getInstance();
	Folder *f = new Folder("Rakoon jezgro");
	try {
	
		filesystem->getInstance()->createFolder("Slaki", f);
		system("pause");


	}
	catch (AccessException &ad) {
		
		cout<<ad.what();
		f->getAccessDescriptor()->add("createFolder");
		filesystem->getInstance()->createFolder("Slaki", f);
		cout << "uspeh";
	}
}