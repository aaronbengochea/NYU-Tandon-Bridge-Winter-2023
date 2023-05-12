//Aaron Bengochea - ab6503 - N12478853
#include <iostream>
#include <string>
using namespace std;

int main () {


    int input, len, sum, intTrans;
    int group1 = 0, group2 = 0, group3 = 0, group4 = 0;
    string stringTrans, currentChar;

    cout << "Please enter a sequence of numbers (with at least 1-digit and at most 8-digits), each one in a separate line. End your sequence by typing -1:" << endl;

    
    while (input > -1){
        cin >> input;

        if (input > -1){
            stringTrans = to_string(input);
            len = stringTrans.length();

            for(int i=0;i < len; i++){
                currentChar = stringTrans[i];
                intTrans = stoi(currentChar);

                sum += intTrans;
                intTrans = 0;
            }

            if (sum < 10){
                group1++;
            }

            else if (sum >= 10 && sum < 20){
                group2++;
            }

            else if (sum >= 20 && sum < 30){
                group3++;
            }
            else{
                group4++;
            }

            sum = 0;
        }
        else{
            input = -1;
        }

    }

    cout << "Total count of numbers in the Numbers Group 1: " << group1 << endl;
    cout << "Total count of numbers in the Numbers Group 2: " << group2 << endl;
    cout << "Total count of numbers in the Numbers Group 3: " << group3 << endl;
    cout << "Total count of numbers in the Numbers Group 4: " << group4 << endl;



    return 0;
}