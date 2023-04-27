#include <iostream>
#include <string>
using namespace std;

const float POUND_PER_KILO = .453592;
const float METER_PER_INCH = .0254;

int main () {

    int weight, height;
    float transWeight, transHeight, bmi;
    string status;

    cout << "Please enter weight (in pounds): ";
    cin >> weight;
    cout << "Please enter height (in inches): ";
    cin >> height;

    transWeight = weight * POUND_PER_KILO;
    transHeight = height * METER_PER_INCH;

    bmi = transWeight / (transHeight * transHeight);

    if (bmi < 18.5){
        status = "Underweight";
    }
    else if (bmi >= 18.5 && bmi < 25){
        status = "Normal";
    }
    else if (bmi >= 25 && bmi < 30){
        status = "Overweight";
    }
    else {
        status = "Obese";
    }

    cout << "The weight status is: " << status;




    return 0;
}