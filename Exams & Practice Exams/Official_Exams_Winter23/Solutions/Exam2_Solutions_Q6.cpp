#include <iostream>
#include <vector>
using namespace std;

int main (){

    cout << "Please enter a non-empty sequence of Strings. Each string should";
    cout << "be in a separate line and consists of only lowercase English";
    cout << "letters and/or numerical characters. To indicate the end of the";
    cout << "input, enter an empty string in one line." << endl;

    // code not complete, please refer below to psudo code. I did not have enough time to complete this problem, 
    // even though I do believe I had the ability to solve it.


    vector<string> strVect;
    string input = " ";

    while (input != ""){
        cin >> input;
        strVect.push_back(input);
        if(input == ""){
            break;
        }
    }

    int vectSize = strVect.size();

    for (int i = 0; i < vectSize; i++){
        cout << strVect[i] << " ";
    }

    cout << endl;
    cout << vectSize;

    return 0;
}

/* did not have time to complete my code, I will write out my process as psudo code.

1) first I begin by initializing a str vector, a string for input.
2) I recieve input as strings from the user, that string is then pushed back onto the vector.
3) The final string recieved will be an empty string, that is how my first portion of code will know when to stop collecting string inputs.
4) Once all string inputs are collected, I will begin iterating through each string element in the str vector. 
5) I will itr through each string element and check its chars in order to determine if it contains any numberical values
    if it does, I will store the string in a new vector called stringsWithNumbers Vector(string) via pushback. 
6) while I am iterating, if I encounter a string element which contains no numbers, I will increment a int variable called nonNumberStrings by ++;
7) The results of all these iterations would be that the stringsWithNumbers Vector would contain all strings with numbers, while the count would hold the number of strings with no numerical values.
8) I would then print the stringsWithNumbers Vector elements one by one with endl behind each. 
9) I would then print "Number of Strings in the input sequence that contain only lowercase English letters:" with nonNumberStrings which would contain the count of all the strings I encountered which contained no numerical values.
10) The code would be complete with the correct output.





*/ 

