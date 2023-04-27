#include <iostream>
using namespace std;



int main () {

    int i, j, k, rowtotal, n = 0;

    cout << "Please enter a postive integer: ";
    cin >> rowtotal;

    rowtotal *= 2;


    for (i = 1; i <= rowtotal / 2.0; i++, n++) {

        for (k = 1; k < i; k++){
            cout << " ";
        }

        for (j = i + n; j < rowtotal; j++){
            cout << "*";
        }

        
        cout << endl;

    }

    int a, b, c;
    n = 0;


    for (int a = 1; a <= rowtotal / 2.0; a++, n++) {

        for (int b = k; b > a; b--){
            cout << " ";
        }

        for (int c = j + n; c >= rowtotal; c--){
            cout << "*";
        }

        n++;
        cout << endl;

    }

    return 0;
}