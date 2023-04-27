#include <iostream>
using namespace std;

int main() {
    char inputLetter;
    char currLetter, lastLetterInLine;
    int n;
    int lineCount, spaceCount;

    cout<<"Please enter a lower case letter:"<<endl;
    cin>>inputLetter;

    cout<<"Line of letters"<<endl;
    for(currLetter = 'a'; currLetter <= inputLetter; currLetter += 1){
        cout<<currLetter;
    }
    cout<<endl;

    cout<<endl<<"Triangle of letters"<<endl;
    n = (inputLetter - 'a') + 1;
    for(lineCount = 1, lastLetterInLine = 'a'; lineCount <= n; lineCount += 1, lastLetterInLine += 1){
        // print a sequence of (n - lineCount) spaces
         for(spaceCount = 1; spaceCount <= (n - lineCount); spaceCount += 1)
            cout<<" ";

        // print letters (from 'a') up to lastLetterInLine
        for(currLetter = 'a'; currLetter <= lastLetterInLine; currLetter += 1)
            cout<<currLetter;

        // break the line
        cout<<endl;
    }

    return 0;
}
