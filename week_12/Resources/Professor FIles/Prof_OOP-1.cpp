#include <iostream>
#include <string>

using namespace std;

class Date{
	int month;
	int day;
public:
	int year;
	int getDay() const { return day; }
	void setDay(int newday);
	void printDate(){ cout << month << "/" << day << "/" << year; }
	//Date();
	Date(int newmonth=1, int newday=1, int newyear=1970);
};

Date::Date(int newmonth, int newday, int newyear){
	if (month > 0 && month <= 12)
		month = newmonth;
	if (day > 0 && day <= 31)
		day = newday;
	year = newyear;
}

/*Date::Date(){
	month = 1;
	day = 1;
	year = 1970;
}*/

void Date::setDay(int newday){
	if (day<=31 && day>0)
		day = newday;
}

class Person{
	string name;
	double height;
	int idNumber;
	Person* spouse;
	Date bday;
	Date anniversary;
public:
	string getName() const{ return name; }
	void changeName(string newname){ name = newname; }
	Date getBday() const { return bday; }
	void setBday(Date newBday){ bday = newBday; }
	Person(string newname="Rumplestitlskin");

	bool marry(Person& other);
	string getSpouseName(){
		return (spouse != nullptr) ? spouse->name : "";
		/*if (spouse != nullptr)
			return spouse->name;
		else
			return "";*/
	}
};
bool Person::marry(Person& other){
	if (this->spouse == nullptr && other.spouse == nullptr){
		//this->spouse is the same as (*this).spouse
		//this->spouse is NOT the same as *this.spouse
		spouse = &other;
		other.spouse = this;
		return true;
	}
	else
		return false;
}
Person::Person(string newname){
	name = newname;
	height = 20;
	idNumber = 11111;
	spouse = nullptr;
}

void func(const Date & d){
	cout << d.getDay() << endl;
	
	//d.setDay(100); //Can't call non-const functions!!!!!
}

class Measurement{
	int feet;
	int inches;
	void normalize();
public:
	Measurement(int newfeet = 0, int newinches = 0) :feet(newfeet), inches(newinches){}
	int getFeet()const{ return feet; }
	int getInches()const{ return inches; }
	void setFeet(int newfeet){ feet = newfeet; }
	void setInches(int newInches){ inches = newInches; normalize(); }
	Measurement operator+(const Measurement& rhs) const;
	Measurement& operator+=(const Measurement& rhs);
	Measurement& operator++();
	Measurement operator++(int);
	friend ostream& operator<<(ostream& outs, const Measurement& rhs); // NOT A MEMBER!!!!
};
ostream& operator<<(ostream& outs, const Measurement& rhs){
	outs << rhs.feet << "' " << rhs.getInches() << "\""; //if friend, can use either
	return outs;
}
Measurement& Measurement::operator++(){ //preincrement (++x)
	inches++;
	normalize();
	return *this;
}
Measurement Measurement::operator++(int){ //post-increment (x++)
	Measurement temp = *this;
	inches++;
	normalize();
	return temp;
}
Measurement& Measurement::operator+=(const Measurement& rhs){
	feet += rhs.feet;
	inches += rhs.inches;
	normalize();
	return *this;
}

Measurement Measurement::operator+(const Measurement& rhs) const{
	Measurement temp;
	temp.feet = feet + rhs.feet;
	temp.inches = inches + rhs.inches;
	temp.normalize();
	return temp;
}
int main(){
	int x = 5;
	int y;
	y = x++;
	cout << y << endl; //5
	x = 5;
	y = ++x;
	cout << y << endl; //6
	Measurement m1(2, 1);
	Measurement m2(3, 11);
	Measurement m3 = m1 + m2; //"this" is m1; rhs is m2
	m3.setFeet(m1.getFeet() + m2.getFeet());
	m3.setInches(m1.getInches() + m2.getInches());
	m3 = (m2 += m1); //Works for Return by value or reference
	m3 = m2 = m1; 
	(m2 += m1)++;
	cout << "M1: " << m1<< endl;
	cout << "M2: " << m2.getFeet() << "' " << m2.getInches() << "\"" << endl;
	cout << "M3: " << m3.getFeet() << "' " << m3.getInches() << "\"" << endl;
}

void Measurement::normalize(){
	if (inches >= 12){
		feet += inches / 12;
		inches %= 12;
	}
	
	while (inches<0){
		feet--;
		inches += 12;
	}
}

/*int main(){
	Date d;
	d.setDay(4);
	d.printDate();
	Date d2(10, 4, 2018);
	//func(d);
	Person p1("Gloria");
	Person p2("Daniel");
	p1.marry(p2); //p1 is "this" and p2 is "other"
}*/