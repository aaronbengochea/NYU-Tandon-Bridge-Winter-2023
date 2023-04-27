#include <iostream>
using namespace std;

class Date{
    private:
        //member variables
        int day;
        int month;
        int year;

    public:
        //member functions
        void setDay(int newDay);
        void setMonth(int newMonth);
        void setYear(int newYear){year = newYear;}
        const int getDay(); //const{return day;}
        const int getMonth(); //const{return month;}
        const int getYear(); //const{return year;}

        // alternate prefered notation to declaring member get functions outside the class.
        // const variable must be declared before data type, forces the function to return 
        // a const value which is what we want out of getters
};

// :: = scope resulution Operator, this allows us to declare member functions 
void Date::setDay(int newDay){
    if (newDay > 0 && newDay < 31){
        day = newDay;
    }
}

void Date::setMonth(int newMonth){
    if (newMonth > 0 && newMonth < 12){
        month = newMonth;
    }
}

const int Date::getDay(){
    return day;
}

const int Date::getMonth(){
    return month;
}

const int Date::getYear(){
    return year;
}



int main (){

    //instantiate a Date object called aaronDay
    Date aaronDay;

    //call on class functions within the object, set dates
    aaronDay.setDay(3);
    aaronDay.setMonth(6);
    aaronDay.setYear(1992);



    //call on get class functions through the object
    cout << aaronDay.getDay() << endl;
    cout << aaronDay.getMonth() << endl;
    cout << aaronDay.getYear() << endl;







    return 0;
}