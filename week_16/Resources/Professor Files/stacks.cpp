#include <iostream>
#include <string>
#include <stack>
#include <vector>


using namespace std;

template <class T>
class LList;

template <class T>
class LListItr;

template <class T>
class LListNode{
	T data;
	LListNode<T>* next;
public:
	LListNode(const T& newdata = T(), LListNode<T>* newnext = nullptr) :data(newdata), next(newnext){}
	friend class LList < T > ;
	friend class LListItr < T > ;
};

template <class T>
class LList{
	LListNode<T>* head;
public:
	LList() :head(nullptr){}
	~LList(){ clear(); }
	LList(const LList<T>& rhs) :head(nullptr){*this = rhs; }
	LList& operator=(const LList<T>& rhs);

	void clear(){ while (!isEmpty()) removeFromHead(); }
	T removeFromHead(){ return head->data; }
	void insertAtHead(const T& toInsert){ head = new LListNode<T>(toInsert, head); }
	void insertAfter(const T& toInsert, LListItr<T> pointToInsert);
	bool isEmpty(){ return head == nullptr; }
	LListItr<T> begin(){ return head; }
	LListItr<T> end(){ return nullptr; }
};



template <class T>
void LList<T>::insertAfter(const T& toInsert, LListItr<T> pointToInsert){
	if (pointToInsert.currentNode != nullptr){ //just in case!
		pointToInsert.currentNode->next = new LListNode<T>(toInsert, pointToInsert.currentNode->next);
	}
}

template <class T>
class LListItr{
	LListNode<T>* currentNode;
public:
	LListItr(LListNode<T>* newcurrentNode = nullptr) :currentNode(newcurrentNode){}
	T& operator*(){ return currentNode->data; }
	T operator*()const { return currentNode->data; }
	LListItr<T>& operator++(); //preincrement
	LListItr<T> operator++(int); //postincrement
	bool operator==(const LListItr<T>& rhs)const { return currentNode == rhs.currentNode; }
	bool operator!=(const LListItr<T>& rhs)const { return !(*this == rhs); }
	friend class LList < T > ;
};

template <class T>
LListItr<T>& LListItr<T>::operator++(){
	if (currentNode != nullptr){
		currentNode = currentNode->next;
	}
	return *this;
}

template <class T>
LListItr<T> LListItr<T>::operator++(int){
	LListItr<T> temp = *this;
	if (currentNode != nullptr){
		currentNode = currentNode->next;
	}
	return temp;
}



class Stuff{
public:
	Stuff(string newa = "", int newb = 0) :a(newa), b(newb){}
	string a;
	int b;
};

int main(){

	vector<int> v;
	v.resize(100);
	v.resize(0);
	
	for (int i = 0; i < 100; i++){
		v.push_back(i);
		cout << "v.size()=" << v.size() << "\tv.capacity()=" << v.capacity() << endl;
	}
	return 0;

	LList<Stuff> l;
	Stuff s("daniel", 100);
	l.insertAtHead(s);
	LListItr<Stuff> li = l.begin();
	cout << (*li).a;
	for (LListItr<Stuff> i = l.begin(); i != l.end(); i++)
		cout << (*i).a << endl;
	

	int x = 5;
	int y;
	y = ++x;
	cout << x << endl;
	cout << y << endl;

}
