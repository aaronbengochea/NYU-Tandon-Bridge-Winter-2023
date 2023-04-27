#include <iostream>
using namespace std;



int main () {
    int a, b;
    float x, y;

    cout << "Please enter two positive integers,g++ seperated by a space: " << endl;
    cin >> a >> b;

    x = a;
    y = b;

    cout << a << " + " << b << " = " << (a + b) << endl;
    cout << a << " - " << b << " = " << (a - b) << endl;
    cout << a << " * " << b << " = " << (a * b) << endl;
    cout << a << " / " << b << " = " << (x / y) << endl;
    cout << a << " div " << b << " = " << (a / b) << endl;
    cout << a << " mod " << b << " = " << (a % b) << endl;



    return 0;
}