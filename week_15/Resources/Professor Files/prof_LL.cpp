#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <list>

using namespace std;

template <class T>
class LList; //Pre-Definition to make Friend work in LListNode

template <class T>
class LListNode {
	T data;
	LListNode<T>* next;
	LListNode<T>* prev;
public:
	LListNode(const T& newdata = T(), LListNode<T>* newnext = nullptr, LListNode<T>* newprev = nullptr) :data(newdata), next(newnext), prev(newprev) {}
	friend class LList<T>;
};

template <class T>
class LList {
	LListNode<T>* head;
	LListNode<T>* tail;
	
public:
	LList();
	~LList();
	LList(const LList<T>& rhs);
	LList<T>& operator=(const LList<T>& rhs);

	void clear() { while (!isEmpty()) pop_front(); }
	void push_back(const T& data) { tail->prev = new LListNode(data, tail, tail->prev); tail->prev->prev->next = tail->prev; }
	void push_front(const T& data) { head->next = new LListNode(data, head->next, head);  head->next->next->prev = head->next; }
	T pop_back();
	T pop_front();
	int size();
	bool isEmpty() { return head->next == tail; }
};
template <class T>
LList<T>& LList<T>::operator=(const LList<T>& rhs) {
	if (this == &rhs)
		return *this;
	clear();
	LListNode<T>* ptr = rhs.head->next;
	while (ptr != rhs.tail) {
		push_back(ptr->data);
	}
	return *this;
}
template <class T>
int LList<T>::size() {
	LListNode<T>* ptr = head->next;
	int count = 0;
	while (ptr != tail) {
		count++;
		ptr = ptr->next;
	}
	return count;
}
template <class T>
T LList<T>::pop_back() {
	if (tail->prev == head) //empty list!
		return T(); //not sure what to do here?  User did something dumb.
	T retval = tail->prev->data;
	LListNode<T>* nodeToDelete = tail->prev;
	tail->prev = nodeToDelete->prev;
	nodeToDelete->prev->next = nodeToDelete->next;
	delete nodeToDelete;
	return retval;
}
template <class T>
T LList<T>::pop_front() {
	if (tail->prev == head) //empty list!
		return T(); //not sure what to do here?  User did something dumb.
	T retval = head->next->data;
	LListNode<T>* nodeToDelete = head->next;
	head->next = nodeToDelete->next;
	head->next->prev = head;
	delete nodeToDelete;
	return retval;
}
template <class T>
LList<T>::~LList() {
	clear();
	delete head;
	delete tail;
}
template <class T>
LList<T>::LList(const LList<T>& rhs) {
	head = new LListNode();
	tail = new LListNode();
	head->next = tail;
	tail->prev = head;
	*this = rhs; //call to the assignment operator!!!
}
template <class T>
LList<T>::LList() { //build two nodes, as "Dummies" for teh sake of making things easier
	head = new LListNode();
	tail = new LListNode();
	head->next = tail;
	tail->prev = head;
}

void func(ostream& outs) {
	outs << "Hello world!" << endl;
}

void openInputFile(ifstream& inFile) {
	string filename;
	cout << "What filename would you like to open: ";
	cin >> filename;
	inFile.open(filename);
	while (!inFile) {
		cout << "Bad filename!" << endl;
		cout << "What filename would you like to open: ";
		cin >> filename;
		inFile.clear(); //release all flags!
		inFile.open(filename);
	}
}

template <class T, class S>
class Pair {
public:
	T first;
	S second;
};

int main() {
	list<int> myList;
	myList.push_back(100);
	myList.push_back(1000);
	//cout << myList[0] << endl; //NO such [] operator!!!!
	for (list<int>::iterator i = myList.begin(); i != myList.end(); i++) // i++ is not incrementing an integer, it's advancing an iterator!!!
		cout << *i << endl; //i is NOT a pointer, it's an iterator!!!

	ofstream outFile("output.txt");
	func(outFile);
	func(cout);
	ifstream inFile;
	openInputFile(inFile);
	int sum=0;
	int count=0;
	int temp;
	string line;
	vector<int> values;
	
	Pair<string, int> item;
	item.first = "Daniel";
	item.second = 100;

	Pair<int, double> item2;
	item2.first = 100;
	item2.second = 5.5;

	Pair<Pair<string, int>, Pair<double, char>> what; //WHAT??????????? Yep, you can do that!
	what.first.first = "Daniel";
	what.first.second = 100;
	what.second.first = 5.5;
	what.second.second = 'A';


	while (inFile >> temp) {
		sum+=temp;
		count++;
		cout<<temp<<"\t";
		inFile.ignore(1, ' ');
		getline(inFile, line);
		cout << line << endl;
		values.push_back(temp);
	}
	cout << "The average is: " << sum / count << endl;
	system("pause");
	return 0;
}
