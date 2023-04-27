#include <iostream>
using namespace std;

const int FLOOR_ROUND = 1;
const int CEILING_ROUND = 2;
const int ROUND = 3;

int main() {

    int roundingType, roundedNumber;
    float number, modulo;

    cout << "Please enter a Real number:" << endl;
    cin >> number;
    cout << "Choose your rounding method:" << endl;
    cout << "1. Floor Rounding" << endl;
    cout << "2. Ceiling Rounding" << endl;
    cout << "3. Round to the nearest whole number" << endl;
    cin >> roundingType;

    switch (roundingType == FLOOR_ROUND){
        case true:
            roundedNumber = (int)(number - .5);
            break;
    }

    switch (roundingType == CEILING_ROUND){
        case true:
            roundedNumber = (int)(number + .5);
            break;
    }

    modulo = number - (int)number;

   switch (roundingType == ROUND){
        case true:
            if (modulo > .5){
                roundedNumber = (int)(number + .5);
            }
            else{
                roundedNumber = (int)(number - .5);
            }
   }


    cout << roundedNumber;



    return 0;
}