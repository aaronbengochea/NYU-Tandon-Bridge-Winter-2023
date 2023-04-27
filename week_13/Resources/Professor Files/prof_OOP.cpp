#include <iostream>
#include <string>
#include <vector>
#include "class.h"

using namespace std;
class Person;

class Pet {
	Person* owner;
};
class Cat :public Pet {

};

class Base {
	int* ptr;
public:
	Base(int newval = 0) :ptr(new int(newval)) { cout << "Called Base's constructor!" << endl; }
	virtual ~Base() { delete ptr; cout << "Called Base's destructor!"<<endl; }
};
class Derived : public Base {
	double * d;
public:
	Derived(double newd = 0, int newint = 0) :Base(newint), d(new double(newd)) { cout << "Called Derived's constructor!" << endl;}
	virtual ~Derived() { delete d; cout << "Called Derived's destructor!" << endl; }
};


class DynArray {
	int* data;
	int size;
	int capacity;

	void resize(int newsize);
public:
	DynArray() :size(0), capacity(5) { data = new int[capacity]; }
	~DynArray() { delete[] data; }
	DynArray(const DynArray& rhs) : size(0), capacity(5), data(new int[capacity]) { *this = rhs; } //Copy constructor calls assignment operator
	DynArray& operator=(const DynArray& rhs);
	void push_back(int newval);
	void clear() { size = 0; }
	int pop_back();
	//1 - No Scope Resolution operator here

};
void DynArray::resize(int newsize) { //2 - Scope resolution operator required!
	int* temp = new int[newsize];
	int limit = (size<newsize)?size:newsize; //ternary (or conditional) operator
	/*if (size < newsize)
		limit = size;
	else
		limit = newsize;*/
	for (int i = 0; i < limit; i++)
		temp[i] = data[i];
	delete[] data;
	data=temp;
	if (size < newsize)
		capacity = newsize;
	else
		size = capacity = newsize; //the array was shrunk and now has less items in it
}
int DynArray::pop_back() {
	if (size >= 1)
		return data[--size];
	else
		return INT_MIN; //???? Ask a stupid question, get a stupid answer!
}
void DynArray::push_back(int newval) {
	if (size == capacity)
		resize(size * 2+1);
	data[size++] = newval;
}

DynArray& DynArray::operator=(const DynArray& rhs) {
	if (this == &rhs) //Test for self-assignment
		return *this;
	delete[] data;
	size = rhs.size;
	capacity = rhs.capacity;
	data = new int[capacity];
	for (int i = 0; i < size; i++)
		data[i] = rhs.data[size];
	return *this;
}


class Measurement {
	int feet;
	int inches;
	void normalize();
public:
	Measurement(int newInches = 0, int newFeet = 0) :feet(newFeet), inches(newInches) { normalize(); }
	int getFeet() const { return feet; }
	int getInches() const { return inches; }
	int getTotalInches()const { return 12 * feet + inches; }
	void setFeet(int newFeet) { feet = newFeet; }
	void setInches(int newInches);
	Measurement operator+(const Measurement& rhs)const;
	Measurement& operator-=(const Measurement& rhs);

	Measurement operator++(int); //PostIncrement
	Measurement& operator++();   //PreIncrement
};
Measurement Measurement::operator++(int) {
	Measurement temp = *this;
	inches++;
	normalize();
	return temp;
}
Measurement& Measurement::operator++() {
	inches++;
	normalize();
	return *this;
}
Measurement& Measurement::operator-=(const Measurement& rhs) {
	feet -= rhs.feet;
	inches -= rhs.feet;
	normalize();
	return *this;
}

Measurement operator-(const Measurement& lhs, const Measurement& rhs) {
	Measurement temp(lhs.getTotalInches()+rhs.getTotalInches()); //This function doesn't have access to private!!!!
	return temp;
}
Measurement Measurement::operator+(const Measurement& rhs)const {
	Measurement temp;
	temp.feet = feet + rhs.feet;
	temp.inches = inches + rhs.inches;
	temp.normalize();
	return temp;
}

void Measurement::normalize() {
	if (inches >= 12) {
		feet += inches / 12;
		inches = inches % 12;
	}
	else if (inches < 0) { //Debug this, unchecked
		feet += inches / 12;
		feet--;
		inches = 12-(inches % 12);
	}
}

void Measurement::setInches(int newInches) {
	inches = newInches;
	normalize();
}

class Person {
	string name;
	Person* spouse;
	vector<Pet*> pets;
public:
	Person(string newName) : name(newName), spouse(nullptr) { }
	string getName() const { return name; }
	void changeName(string newname) { name = newname; }
	bool marry(Person& other);
};

bool Person::marry(Person& other) {
	if (spouse != nullptr || other.spouse != nullptr)
		return false;
	spouse = &other;
	other.spouse = this; //ok because marry has access to ALL spouses!
}


class Thing {
	int item;
public:
	Thing() { cout << "Thank you for using my class!" << endl; }
	void setItem(int newItem) { item = newItem; }
	int getItem() const { return item; }
	int* getPointer() { return &item; }
};

void func1(const Thing& t) {
	cout << t.getItem() << endl;
	//t.setItem(100); //Not allowed, because t is const and setItem is non-const!
}

void func2(Thing& t) {
	cout << t.getItem() << endl;
	t.setItem(100);
}

void func3(Thing t) {
	cout << t.getItem() << endl;
}
void func4(int x = 100) {
	cout << x << endl;
}


void func() {
	//Derived d(100);
	Base * bptr = new Derived();
	delete bptr;
}

int main() {
	for (int i = 0; i < 1; i++)
		func();
/*	MyClass m;
	m.myfunc();
	system("Pause");
	Measurement one(5);
	Measurement two(20);
	Measurement three(two); //Copy-Constructor
	Measurement result;
	Measurement four = one; //Copy-Constructor
	result = one; //Assignment operator

	result = one + two;
	result = result - two;
	result = one + 5; //C++ will construct and object for me!
	result = one - 5;
	//result = 5 + one; //Doesn't work, because operator+ is a member!
	result = 5 - one; //Works because operator- is non-member!
	result -= one;

	int x = 5;
	int y = ++x; // int y = (x.operator++());
	x = 5;
	int z = x++; //int z = (x.operator++(int));
	cout << x; //6
	cout << y; //6
	cout << z; //5
	*/
	/*
	func4();
	func4(20);
	Thing one;
	one.setItem(100); //3 - No scope resolution operator!
	Thing two;
	two.setItem(500);
	cout << one.getItem() << endl; //100
	cout << two.getItem() << endl; //500

	Thing* tptr = &one;

	cout << (*tptr).getItem() << endl;
	//cout << *tptr.getItem() << endl; //Doesn't work because of precedence
	cout << tptr->getItem() << endl; //Equivalent to two lines above
	cout << *one.getPointer() << endl;  //same as *(one.getPointer())
	*/
	system("pause");
}