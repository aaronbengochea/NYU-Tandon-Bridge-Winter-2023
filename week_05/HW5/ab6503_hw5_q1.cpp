#include <iostream>
using namespace std;

int main () {

    int input;

    cout << "Please enter a positive integer:" << endl;
    cin >> input;
    for (int a=1;a <= input;a++){

        for (int i=1;i<=input;i++){
        cout << i * a << "\t";
        }
        cout << endl;
    }

    return 0;
}