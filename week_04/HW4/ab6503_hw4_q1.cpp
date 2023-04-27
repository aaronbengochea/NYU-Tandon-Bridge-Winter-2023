#include <iostream>
using namespace std;

int main () {

    int n,outputA, outputB;
    int i = 1, itr = 1;

    cout << "Please enter a positive integer: ";
    cin >> n;

    cout << "Section A: " << endl;
    for (i; i <= n; i++){
        cout << i * 2 << endl;

    }
    cout << endl;


    cout << "Section B: " << endl;
    while (itr <= n){
        cout << itr * 2 << endl;
        itr++;

    }
    cout << endl;



    return 0;
}