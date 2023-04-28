#include <iostream>
#include <cmath>
using namespace std;

void printDivisors(int num){
    int i;
    int n = num;

    for (i=1;i<sqrt(n);i++){
        if (n % i == 0){
            cout << i << " ";
        }
    }

    for (i;i >= 1; i--){
        if (n % i == 0){
            cout << (n/i) << " ";
        }
    }

    cout << endl;
}





int main () {
    
    

    cout << "Section A:"<< endl;
    printDivisors(6);

    cout << endl;

    int input;
    cout << "Section B:"<< endl;
    cout << "Please enter a positive integer >= 2: ";
    cin >> input;
    printDivisors(input);




    return 0;
}