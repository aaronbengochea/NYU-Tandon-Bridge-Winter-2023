#include <iostream>
using namespace std;

int main () {

    char input;
    int inputTrans;


    cin >> input;

    inputTrans = input;

    cout << input << endl;
    cout << inputTrans << endl;

    for (int i = 0; i < 4; i++){
        input = input + i;
        inputTrans = input;

        cout << input << endl;
        cout << inputTrans << endl;
    }






    return 0;
}