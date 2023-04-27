#include <iostream>
#include <string>
using namespace std;

class Thing{
    int num;
    int num2;

public:
    Thing(int newnum = 0) :num(newnum){}
    int getNum() const {return num; }
    void setNum(int newnum) {num = newnum;}

    Thing operator+(const Thing& rhs) const;
    Thing& operator++();
    Thing operator++(int);
    void demoThisFunc() const;
};

void Thing::demoThisFunc(){
    cout << this << endl;
}

Thing& Thing::operator++(){
    num++;
    return *this;
}

Thing Thing::operator++(int){
    Thing temp = *this; //copy this object
    num++;
    return temp
}

Thing operator-()



void func(const Thing& x){
    x.getNum();
    Thing three = x + 5;
}

Thing Thing::operator+(const Thing&rhs) const{
    return num + rhs.num;
}




int main () {
    Thing one(1);

    cout << one.getNum() << endl;

    Thing two(2);
    Thing three;
    three = one + two;
    func(two);
    //cout << two.getNum() << endl;

    ++++two; //double pre-increment
    ++(++two); //same as the previos line
    (two.operator++()).operator++(); //still the same as the previos line
    two++; // works
    (two++)++; // 5++


    int x = 5 + 6;
    string fristName = "daniel";
    string lastName = "Katz";
    string name = fristName + lastName;


    int var;
    int result;
    var = 5;
    //result = var++;
    result = func1(var); // func1 returns the original value
    cout << var << endl; //6
    cout << result << endl; //5

    var = 5;
    result = ++var;
    results = func2(var); // 
    cout << var << endl; //6
    cout << result << endl; //6

    ++++var; // 






    return 0;
}