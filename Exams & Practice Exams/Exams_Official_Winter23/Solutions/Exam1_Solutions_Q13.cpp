//Aaron Bengochea - ab6503 - N12478853
#include <iostream>
using namespace std;

int main () {

    int input;

    cout << "Please enter a positive integer: " << endl;
    cin >> input;

    int totalLines = 2 * input;
    int starCount = 1;
    int j = 1;
    int k = 1;

    for (int i = 0; i < totalLines; i++){

        for(j; j < totalLines - i; j++){
            cout << " ";
        }

        for(k; k <= starCount;k++){
            cout << "*";
        }

        j = 1;
        k = 1;
        starCount++;
        cout << endl;


    }



    return 0;
}