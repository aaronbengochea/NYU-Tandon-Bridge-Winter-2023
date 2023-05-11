#include <iostream>
#include <set>

using namespace std;

class FamilyMember {
	int age;
public:
	FamilyMember(int newage = 0) { age = newage; }
	virtual void setAge(int newage) { age = newage; }
	virtual int getAge()const { return age; }
};
class Pet:public FamilyMember{
public:
	Pet(int newage) :FamilyMember(newage) {}
	virtual int getAge()const { return FamilyMember::getAge() * 7; }
};
class Human : public FamilyMember {
public:
	Human(int newage) :FamilyMember(newage) {}
};


template <class T>
class BSTNode {
	BSTNode<T>* left, *right, *parent;
public:
	T data;
	int height()const;
};

template <class T>
int BSTNode<T>::height()const {
	int leftHeight=0;
	int rightHeight=0;
	if (left != nullptr)
		leftHeight = left->height();
	if (right != nullptr)
		rightHeight = right->height();
	if (leftHeight > rightHeight)
		return 1 + leftHeight;
	else
		return 1 + rightHeight;
}

class lessThanOnage {
public:
	bool operator()(const FamilyMember* lhs, const FamilyMember* rhs) { return lhs->getAge() < rhs->getAge(); }
};

int main() {
	set<FamilyMember*, lessThanOnage> s;
	Human h1(10);
	Human h2(5);
	Pet p1(3);
	s.insert(&h1);
	s.insert(&h2);
	s.insert(&p1);

	for (set<FamilyMember*>::iterator i = s.begin(); i != s.end(); i++)
		cout << (*i)->getAge() << endl;




}