#include "list.hpp"
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

list<int> ilist;

int main () {
	do {
		for (int i = 0; i < 40; i++)
			cout << "*";
		cout << endl;
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
		case 0: {
			exit(0);
			break;
		}
		case 1: {
			list<int>::iterator iter = ilist.begin();
			for (int i = 0; i < ilist.size(); i++) {
				cout << "list[" << i << "]: " << *iter << " " << endl;
				iter++;
			}
			if (ilist.size() == 0) {
				cout << "the list is empty." << endl;
			}
			else {
				cout << "the size of the list is " << ilist.size() << endl;
			}
			break;
		}
		case 2: {
			cout << "data:";
			int data;
			cin >> data;
			while (cin.fail()) {
				cin.clear();
				cout << "please enter a number:";
				cin >> choice;
			}
			cout << "searching...";

			int i = 0;
			bool isSearched = false;
			for (list<int>::iterator iter = ilist.begin(); iter != ilist.end(); iter++) {
				if (*iter == data) {
					cout << "list[" << i << "] ";
					isSearched = true;
				}
				i++;
			}
			if (!isSearched)
				cout << "have not searched data:" << data << endl;
			break;
		}
		case 3: {
			cout << "pos:";
			int pos;
			while (true) {
				cin >> pos;
				if (cin.fail()) {
					cin.clear();
					cout << "please enter a number:";
				}
				else if (pos > ilist.size()) {
					cout << "please enter a number under " << ilist.size() << ":";
				}
				else
					break;
			}

			cout << "data:";
			int data;
			cin >> data;
			while (cin.fail()) {
				cin.clear();
				cout << "please enter a number:";
				cin >> data;
			}

			list<int>::iterator iter = ilist.begin();
			for (int _pos = 0; _pos < pos; _pos++) {
				iter++;
			}
			ilist.insert(iter, data);
			break;
		}
		case 4: {
			cout << "pos:";
			int pos;
			while (true) {
				cin >> pos;
				if (cin.fail()) {
					cin.clear();
					cout << "please enter a number:";
				}
				else if (pos > ilist.size()) {
					cout << "please enter a number under " << ilist.size() - 1 << ":";
				}
				else
					break;
			}

			list<int>::iterator iter = ilist.begin();
			for (int _pos = 0; _pos < pos; _pos++) {
				iter++;
			}
			ilist.erase(iter);
			break;
		}
		case 5: {
			ilist.erase(ilist.begin(), ilist.end());
			break;
		}
		default:
			break;
		}
	} while (true);
	return 0;
}
