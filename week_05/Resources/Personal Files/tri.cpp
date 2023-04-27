#include <iostream>
using namespace std;


int main () {

    char startLetter = 'A', space = ' ';
    char nextLetter;
    int input, outsideSpace, insideSpace;
    

    cout << "Please enter a positive integer: ";
    cin >> input;

    int numOfLines = 2 * input - 1;

    for (int i = 1; i <= numOfLines; i++){
        // patter for each half

        if (i <= input){
            outsideSpace = input - i;
            insideSpace = 2 * (i - 1) - 1;
            nextLetter = startLetter + (i - 1); // because we start i count @ 1

        }


        // pattern for bottom half

        else{
            outsideSpace = i - input;
            insideSpace = 2 * (2 * input - i) - 3;
            nextLetter = startLetter + (numOfLines - i);
        }

        // for each line, we start by printing outside spaces
        while (outsideSpace >= 1){
            cout << space;
            outsideSpace--;

        }
        // once done printing outside spaces, we print the letter
        cout << nextLetter;
        // if there are inside spaces, we print the inside spaces
        if (insideSpace >= 1){
            while (insideSpace >= 1){
                cout << space;
                insideSpace--;
            }
            cout << nextLetter;
        }
        // then if line is not first or final line, print letter again
        // we then start a new line
        cout << endl;



    }


    







    return 0;
}