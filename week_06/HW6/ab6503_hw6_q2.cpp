#include <iostream>
using namespace std;

void printShiftedTriangle(int n, int m, char symbol){

    int symbolCount = 1;
    int spaceCount = m + n - 1;

    for (int i = 0; i < n; i++){

        for (int j = 0; j < spaceCount;j++){
            cout << " ";
        }
        for (int k = 0;k < symbolCount;k++){
            cout << symbol;
        }

        symbolCount += 2;
        spaceCount--;
        cout << endl;

    }
}

void printPineTree(int n, char symbol){

    int pineLength = n;
    int symbolCount = 1;
    int spaceCount = n;
    int openingStack = 2;

    while (pineLength > 0){

        for (int i=0; i < openingStack; i++){

            for (int j = 0; j < spaceCount; j++){
                cout << " ";
            }

            for (int k = 0;k < symbolCount;k++){
                cout << symbol;
            }

            spaceCount--;
            symbolCount+=2;
            cout << endl;

        }
        symbolCount = 1;
        openingStack++;
        spaceCount = n;
        pineLength--;
    }

}

int main () {

    cout << "Section A: Print Shifted Triangle" << endl;
    printShiftedTriangle(3, 4, '+');

    cout << endl;

    cout << "Section B: Print Pine Tree" << endl;
    printPineTree(3,'+');
   

    return 0;
}