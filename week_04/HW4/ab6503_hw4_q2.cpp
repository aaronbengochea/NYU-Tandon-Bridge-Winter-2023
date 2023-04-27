#include <iostream>
using namespace std;




int main () {

    int n, workingNumbers, beginningInput;
    string romanNumber;

    cout << "Enter a decimal number: ";
    cin >> n;

    beginningInput = n;

    if (n > 1000){
        workingNumbers = n / 1000;
        n = n % 1000;
        while (workingNumbers > 0){
            romanNumber += "M";
            workingNumbers--;
        }
    }

    if (n >= 500){
        workingNumbers = n / 500;
        n = n % 500;
        while (workingNumbers > 0){
            romanNumber += "D";
            workingNumbers--;
        }
    }

    if (n >= 100){
        workingNumbers = n / 100;
        n = n % 100;
        while (workingNumbers > 0){
            romanNumber += "C";
            workingNumbers--;
        }
    }

    if (n >= 50){
        workingNumbers = n / 50;
        n = n % 50;
        while (workingNumbers > 0){
            romanNumber += "L";
            workingNumbers--;
        }
    }

    if (n >= 10){
        workingNumbers = n / 10;
        n = n % 10;
        while (workingNumbers > 0){
            romanNumber += "X";
            workingNumbers--;
        }
    } 

    if (n >= 5){
        workingNumbers = n / 5;
        n = n % 5;
        while (workingNumbers > 0){
            romanNumber += "V";
            workingNumbers--;
        }
    }

    if (n >= 1){
        workingNumbers = n / 1;
        n = n % 1;
        while (workingNumbers > 0){
            romanNumber += "I";
            workingNumbers--;
        }
    }


    cout << beginningInput << " is " << romanNumber << endl;


    return 0;
}