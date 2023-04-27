#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main () {

    int inputA, inputB = 1, multipliedDatasetA = 1, multipliedDatasetB = 1;
    float sequenceLengthA, sequenceLengthB, geoMeanA, geoMeanB;

    cout << "Section A:" << endl;
    cout << "Please enter the length of the sequence: ";
    cin >> sequenceLengthA;

    cout << "Please enter the sequence: " << endl;

    for (int i = 0; i < sequenceLengthA; i++){
        cin >> inputA;
        multipliedDatasetA *= inputA; 
    }

    geoMeanA = pow(multipliedDatasetA, 1.0 / sequenceLengthA);

    cout << "The geometric mean is: " << setprecision(5) << geoMeanA << endl;

    cout << endl;
    
    cout << "Section B:" << endl;
    cout << "Please enter a non-empty sequence of postivie integers, each one in a seperate line. " << endl;
    cout << "End your sequence by typing -1: " << endl;
    
    while (inputB != -1){
        cin >> inputB;
        if (inputB != -1){
        multipliedDatasetB *= inputB;
        sequenceLengthB++;};
    }

    geoMeanB = pow(multipliedDatasetB, 1.0 / sequenceLengthB);


    cout << "the geometric mean is: " << setprecision(5) << geoMeanB << endl;


    return 0;
}