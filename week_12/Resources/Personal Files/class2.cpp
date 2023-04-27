#include <iostream>
#include <string>
using namespace std;

//if code is more then one line, write it outside the class
class Thing {
    int num;
    int num2;
    int* value;
public:
    //constructor
    //auto set to implicit
    //explicit Thing(int newnum = 0) :num(newnum) {} <-- explicit example
    //member initialization list method
    Thing(int newnum = 0) :num(newnum), value(new int(newnum)) {}

    // the alternate initialization method below
    /*
    Thing(){
        num = 0;
    }
    */


    //getter
    int getNum() const {return num;}

    //setter
    void setNum(int newnum) { num = newnum;}
    
    //rhs = right hand side
    Thing operator+(const Thing& rhs) const;
    Thing& operator++(); //pre-increment
    Thing operator++(int); //post-increment
    void demoThisFunc() const;

    //Big 3 solution - if you need any then you need all 3, making deep copies
    //shallow copy is a copy of the ptr to an objects location, deep copy is a copy of the item ptr is pointing too
    ~Thing() {delete value; } //destructor
    Thing(const Thing& rhs) {value = new int(*rhs.value);} //copy constructor
    Thing& operator=(const Thing& rhs){ *value = *rhs.value;} //Assignment operator

};

void Thing::demoThisFunc() const{
    cout << this << endl;
}

Thing& Thing::operator++(){
    num++;
    return *this; //return the actual object
}

Thing Thing::operator++(int){
    Thing temp = *this; //copy this object
    num++;
    return temp; //return the original as a copy
}






//Any function that is not making a change should be const
//constified functions can be used with other const 
void func(const Thing& x){
    x.getNum();
    Thing three = x + 5;
}
//in pass by value, I am making a copy
//void func(Thing x)

//pass by ref, does not make a copy
//void func(Thing& x)


//in non member function - two parameters needed since it has no member
//in member functions, you only need one parameter bc the object itself is the lhs
Thing operator-(const Thing& lhs, const Thing& rhs){
    return lhs.getNum() - rhs.getNum();

}

//member function - only rhs parameter
//implicit call to the constructor; makes a new object
Thing Thing::operator+(const Thing& rhs) const {
    return num + rhs.num; //implicit call to constructor(value)
}


int main (){

    //Explicit call to the constructor
    Thing one(1);

    cout << "Thing1 = " << one.getNum() << endl;

    Thing two(2);
    cout << "Thing2 = " << two.getNum() << endl;
    two.setNum(5);
    cout << "Thing2 Mod = " << two.getNum() << endl;
    
    //Thing three = one.getNum() + two.getNum();
    //Thing three(one.getNum() + two.getNum());
    // or the below work, below we overide the + operator in the thing class
    Thing three = one + two; //<-- three.operator= (one.operator+(two))
    cout << "Thing3 = " << three.getNum() << endl;

    Thing four = one - two;
    cout << "Thing4 = " << four.getNum() << endl;

    two++;
    two++;
    //++++two; // double pre-increment
    //++(++two); // same as prev line
    //(two.operator++()).operator++(); //same as prev lines
    cout << "Thing2 = " << two.getNum() << endl; //result = 11

    //this demonstration, this = pointer to the object calling the function since its a member function
    two.demoThisFunc();
    cout << &two << endl;


    return 0;
}