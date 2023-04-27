#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <list>
using namespace std;

void openInputFile(ifstream& inFile) {
	string fileName;
	cout << "What filename? ";
	cin >> fileName;
	inFile.open(fileName);
	while (!inFile) {
		cout << "FILE FAILED TO OPEN! " << endl;
		cout << "What filename? ";
		cin >> fileName;
		inFile.clear();
		inFile.open(fileName);
	}
}

/*template <class T, class S>
class Pair {
public:
	T first;
	S second;
};*/

class Student {
public:
	int id;
	double testScore;
	string name;
};
void printHello(ostream& outs) {
	outs << "Hello world!" << endl;
}
class Demo {
public:
	string operator*() {
		return "Hello from Dereference operator!!!!";
	}
};

LList<T>& LList<T>::operator=(const LList<T>& rhs) {
	if (this == &rhs)
		return *this;
	clear();
	head = recursiveCopy(rhs.head);
	return *this;
}

int main() {
	Demo d1;
	cout<< *d1 <<endl;
	list<int> l1;
	for (int i = 0; i < 100; i ++ ) {
		l1.push_back(i * 10);
	}
	//cout << l1[0] << endl; // Doesn't work!

	for (int i : l1) {//one for of list traversal
		cout << i << endl;
	}

	for (list<int>::iterator i = l1.begin(); i != l1.end(); i++) {
		cout << *i << endl;
		*i += 2;
	}

	/*list<int>::iterator rev = l1.end();

	while ((--rev) != l1.begin())
		cout << *rev << endl;
	cout << *rev << endl;
	*/
	for (list<int>::reverse_iterator rev = l1.rbegin(); rev != l1.rend(); rev++) {
		cout << *rev << endl;
	}

	pair<string, int> p1;
	
	pair<string, pair<int, float>> p2;
	p2.first = "John";
	p2.second.first = 99;
	p2.second.second = 5.5;

	p1.first = "Daniel";
	p1.second = 100;

	ofstream outfile("out.txt");
	printHello(outfile);
	printHello(cout);
/*	ifstream inFile;
	openInputFile(inFile);
	vector<Student> vs;
	Student temp;

	while (inFile >> temp.id) {
		inFile >> temp.testScore;
		inFile.ignore(9999, '\t');
		getline(inFile, temp.name);
		vs.push_back(temp);
	}

	cout << " Students with test scores over 90: " << endl;

	for (Student s : vs) {
		if (s.testScore > 90) {
			cout << s.name << endl;
		}
	}


	return 0;
	*/
}