#include <iostream>
#include <string>
using namespace std;

int main () {


    int gradYear, currYear, yearDiff;
    string name, gradStatus;    

    cout << "Please enter your name: ";
    cin >> name;
    cout << "Please enter your graduation year: ";
    cin >> gradYear;
    cout << "Please enter current year: ";
    cin >> currYear;

    yearDiff = gradYear - currYear;


    if (yearDiff > 4){
        gradStatus = "you are not in college yet";
    }
    else if (yearDiff == 4){
        gradStatus = "you are a Freshman";
    }
    else if (yearDiff == 3){
        gradStatus = "you are a Sophmore";
    }
    else if (yearDiff == 2){
        gradStatus = "you are a Junior";
    }
    else if (yearDiff == 1){
        gradStatus = "you are a Senior";
    }
    else {
        gradStatus = "you've already Graduated!";
    }



    cout << name << ", " << gradStatus; 

    return 0;
}