#include <iostream>
using namespace std;

int fib(int n){
    int first, second, sum, count;

    first = 0;
    second = 1;

    while (count <= n){

        if (count < 2){
            sum = first + second;
        }

        else {
        sum = first + second;
        first = second;
        second = sum;
        }

        count++;
    }

    return sum;

}


int main () {

    int input, output;

    cout << "Please enter a positive integer: ";
    cin >> input;

    // for (int i = 0; i <= 47; i++){
    //     output = fib(i);
    //     cout << i << " fib: " << output << endl;
    // }

    output = fib(input);

    cout << output;
    

    return 0;
}