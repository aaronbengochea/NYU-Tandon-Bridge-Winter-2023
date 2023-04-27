#include <iostream>
#include <string>
using namespace std;

int main () {

    int number, n = 0, evenCount = 0, placeholder, placeholderTwo, placeholderThree;
    string currentNumber, numberOne, numberTwo, numberThree;

    cout << "Please enter a positive integer: ";
    cin >> number;

   
    while (n <= number){


        if (n < 10){
            if (n % 2 == 0 && n != 0){
                currentNumber = to_string(n);
                cout << currentNumber << endl;
            }
        }

        if ((n >= 10) && (n < 100)){
            currentNumber = to_string(n);
            numberOne = currentNumber[0];
            numberTwo = currentNumber[1];

            placeholder = stoi(numberOne);
            placeholderTwo = stoi(numberTwo);


            if (placeholder % 2 == 0){
                evenCount++;
            }

            if (placeholderTwo % 2 == 0){
                evenCount++;
            }
            
            if (evenCount == 2){
                cout << currentNumber << endl;

            }

            evenCount = 0;
        }

        if ((n >= 100) && (n < 1000)){
            currentNumber = to_string(n);
            numberOne = currentNumber[0];
            numberTwo = currentNumber[1];
            numberThree = currentNumber[2];

            placeholder = stoi(numberOne);
            placeholderTwo = stoi(numberTwo);
            placeholderThree = stoi(numberThree);

            if (placeholder % 2 == 0){
                evenCount++;
            }

            if (placeholderTwo % 2 == 0){
                evenCount++;
            }

            if (placeholderThree % 2 == 0){
                evenCount++;
            }
            
            if (evenCount == 2){
                cout << currentNumber << endl;

            }

            evenCount = 0;
        }   

        n++;

    }




    return 0;
}