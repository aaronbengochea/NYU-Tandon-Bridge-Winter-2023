#include <iostream>
#include <vector>
#include <string>

using namespace std;


class Measurement { //Rule: inches must be between 0 and 11 inclusive
	int feet; //default is PRIVATE!
	int inches;
	void normalize();
public:
	Measurement(int newInches = 0, int newFeet = 0) : feet(newFeet), inches(newInches) { normalize(); }
	void setInches(int val) { inches = val; normalize(); }
	void setFeet(int val) { feet = val; }
	int getInches()const { return inches;}
	int getFeet()const { return feet; }
	int getTotalInches() const { return feet * 12 + inches; }
	Measurement operator+(const Measurement& other) const ; //Two Objects: calling-object and the other
	bool operator<(const Measurement& rhs)const { return getTotalInches() < rhs.getTotalInches(); }
	friend ostream& operator<<(ostream& outs, const Measurement& rhs); //NOT A MEMBER OF THE CLASS!!!!!!

	Measurement& operator++();
	Measurement operator++(int);
};

Measurement& Measurement::operator++() { //pre-increment! ++x
	inches++;
	normalize();
	return *this;
}
Measurement Measurement::operator++(int) { //POST-increment x++
	Measurement temp(*this); // copy myself!
	inches++;
	normalize();
	return temp;
}


ostream& operator<<(ostream& outs, const Measurement& rhs) { // cout<<m1 is actually operator<<(cout,m1)
	outs << rhs.feet << "' " << rhs.inches << "\""; //Can DIRECTLY access private data due to "Friend" relationship!
	return outs;
}


Measurement operator-(const Measurement& lhs, const Measurement& rhs) { //lhs-rhs //can say: m-5 or 5-m
	Measurement temp(lhs.getInches() - rhs.getInches(), lhs.getFeet() - rhs.getFeet());
	return temp;
}

Measurement Measurement::operator+(const Measurement& other) const {  //can say: m-5 (but CANNOT DAY 5-m)
	Measurement temp(inches + other.inches, feet + other.feet);
	return temp;
}

void Measurement::normalize() {
	if (inches >= 12) {
		feet += inches / 12;
		inches %= 12;
	}
	while (inches < 0) {
		feet--;
		inches += 12;
	}
}

class Date; //predefinition 

class Person {
private:
	string name;
	Person* spouse; //Pointer to another Person
	Date bday;
public:
	Person(string newName) :name(newName) { spouse = nullptr; }
	string getName() const { return name; }
	bool marry(Person& other); //two objects: the calling object and other!
	string getSpouseName() const;
};

string Person::getSpouseName() const {
	if (spouse == nullptr)
		return "";
	//return (*spouse).name;
	return spouse->name; // arrow will dereference the lhs object
}

bool Person::marry(Person& other) {
	if (spouse != nullptr || other.spouse != nullptr)
		return false;
	spouse = &other; //I marry my wife
	other.spouse = this;//She marries me!
	return true;
}


class Date {
private:
	int day;
	int month;
	int year;
	string makeTwoDigit(int val) const; //helper function
public:
	Date() :day(1), month(1), year(1970) {} //Default Constructor
	Date(int newYear) : day(1), month(1), year(newYear) {} //Also a constructor

	void setYear(int newYear) {year = newYear;} //inLine function
	void setMonth(int newMonth);
	void setDay(int newDay);
	int getDay()const { return day; } //const guarantees that we will not modify the calling object!
	int getMonth()const { return month; }
	int getYear()const { return year; }
	void printSQLDate() const;
	void printAmericanDate() const;
};

string Date::makeTwoDigit(int val) const{
	if (val >= 10)
		return to_string(val);
	else
		return '0' + to_string(val);

}

void Date::setMonth(int newMonth){
	//int month; //BAD: Redefinition of the variable name locally!
	if (newMonth > 0 && newMonth <= 12)
		month = newMonth;
}
void Date::setDay(int newDay) {
	if (newDay > 0 && newDay <= 31)
		day = newDay; //Modify day in the calling object
}
void Date::printAmericanDate() const {
	//  MM/DD/YYYY
	cout << makeTwoDigit(month) << "/" << makeTwoDigit(day) << "/" << makeTwoDigit(year);
}
void Date::printSQLDate() const{
	//2021-04-02
	cout << makeTwoDigit(getYear()) << "-" << makeTwoDigit(getMonth()) << "-" << makeTwoDigit(getDay());
}

int main() {
	Measurement m1(120);
	Measurement m2(-120);
	Measurement m3 = m1 + m2;

	Person dan("Daniel");
	Person gloria("Gloria");
	dan.marry(gloria); //or gloria.marry(dan);

	Date item; //Automatic call to the DEFAULT constructor
	item.setDay(10); //Calling object: item
	Date other(2021); //Automatic call to the ONE INT ARGUMENT constructor
	other.setDay(20); //Calling object: other
	item.setDay(2);
	item.setMonth(4);
	item.setYear(2021);
	item.printSQLDate();

	Date itemCopy(item); //copy constructor
	itemCopy = item; //Assignemnt Operator

	Date otherCopy = other; //copy constructor

	int x;
	int y;

	x = 5;
	y = (++x);
	cout << "Y after ++X: " << y << endl; //6
	cout << "X after ++X: " << x << endl; //6
	x = 5;
	y = (x++);
	cout << "Y after X++: " << y << endl; //5
	cout << "X after X++: " << x << endl; //6

}
