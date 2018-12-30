#include "list.h"
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

list<int> ilist;

int main () {
	for (int i = 0; i < 80; i++)
		cout << "*";
	cout << "0.exit." << endl;
	cout << "1.list." << endl;
	cout << "2.search." << endl;
	cout << "3.add." << endl;
	cout << "4.delete." << endl;
	cout << "5.empty." << endl;
	cout << "you choose:";
	int choice;
	cin >> choice;
	while (cin.fail()) {
		cin.clear();
		cout << "please enter a number:";
		cin >> choice;
	}
	switch (choice) {
	case 0:
		exit(0);
		break;
	case 1:
		list<int>::iterator iter = ilist.begin();
		for (int i = 0; i < ilist.size(); i++) {
			cout << "list[" << i << "]: " << *iter << " " << endl;
		}
		if (ilist.size() == 0) {
			cout << "the list is empty." << endl;
		}
		else {
			cout << "the size of the list is " << ilist.size() << endl;
		}
		break;
	}
	return 0;
}
