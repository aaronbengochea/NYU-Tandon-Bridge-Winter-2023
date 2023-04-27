#include <iostream>

using namespace std;

class B; //pre-definiton

class A {
	int x;
public:
	A(int newx = 0) :x(newx) {}
	//no accessor function for x!!!
	friend class B;
};
class B {
	A amember;
public:
	int getX() const { return amember.x; }
};

class Elephant {
	int* arr;
	int count;
	int capacity;
public:
	Elephant() : arr(new int[200000000]),count(0), capacity(200000000) {}
	~Elephant() { delete [] arr; }
	Elephant(const Elephant& rhs) : arr(new int[200000000]), count(0), capacity(200000000) { *this = rhs; }
	Elephant& operator=(const Elephant& rhs); //must be a member of the class!!!!!

};
Elephant& Elephant::operator=(const Elephant& rhs) { //must be a member of the class!!!!!
	if (this == &rhs)
		return *this;
	for (int i = 0; i < capacity; i++)
		arr[i] = rhs.arr[i];
	return *this;
}


class Thing {
	int *val;
public:
	Thing(int newval = 0) : val(new int(newval)) {}
	~Thing() { delete val; }
	Thing(const Thing& rhs) : val(new int(*rhs.val)) {}
	Thing& operator=(const Thing& rhs); //must be a member of the class!!!!!
	void setVal(int newval) { *val = newval; } //inline function
	Thing operator+(const Thing& rhs) const;
	int getVal()const { return *val; } //const-ify the calling object
	const int  getVal2() { return *val; } //const-ify the return value!
	//friend Thing operator-(const Thing& lhs, const Thing& rhs);

};
Thing operator-(const Thing& lhs, const Thing& rhs) { //non-member so two parameters!
	Thing temp(lhs.getVal() + rhs.getVal());
	//delete lhs.val;
	return temp;
}
// ReturnValue FunctionName (Parameter1Type Parameter1Name, Parameter2Type Parameter2Name)
Thing& Thing::operator=(const Thing& rhs) {
	if (this == &rhs) //test for self-assignment!
		return *this;
	*val = *rhs.val;
	return *this;
}

class NewThing {
public:
	int x;
	int y;
};

Thing Thing::operator+ (const Thing& rhs)const {
	Thing temp = *this;
	temp.val += *rhs.val;
	return temp;
}

ostream& operator<<(ostream& outs, const Thing& rhs) {
	outs << rhs.getVal();
	return outs;
}

void func(const Thing& one) {
	//one.getVal2();
}

void func2(const Elephant& e) {
	cout << "Bring in da noise, bring in da Func2!" << endl;
}


int main() {
	cout << "Creating an elephant!" << endl;
	Elephant e1;
	cout << "Now calling the func" << endl;
	func2(e1);
	cout << "Done!" << endl;
	Thing* tptr = new Thing(100);

	cout << *tptr << endl;
	(*tptr).getVal();// same: tptr->getVal();
	
	/*
	NewThing one;
	NewThing two;
	one.x = 10;
	one.y = 20;
	//two.x = one.x; two.y = one.y;
	two = one; //Shallow copy!
	Thing t1(5);
	Thing t2(10);
	Thing t3;
	t3 = t1 + t2; // t3.operator=(t1.operator+(t2));
	t3 = t1 - t2; // t3.operator=(operator-(t1,t2));
	t2 = t3; // t2.operator=(t3);
	t1 = t2 = t3;
	//(        cout   << endl; // operator<<(cout,endl);
	//operator<<(cout, t3);
	((cout << t3) << endl);
	*/
}