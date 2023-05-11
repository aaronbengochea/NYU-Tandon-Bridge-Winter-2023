#include <iostream>
#include <fstream>
#include <stack>
using namespace std;

void openInFile(ifstream& inFIle);
bool balanceSymbols(ifstream& inFile);

int main () {
    ifstream inFile;

    openInFile(inFile);

    if (balanceSymbols(inFile)){
        cout << "All symbols are balanced!" << endl;
    } 
    else {
        cout << "The symbols are not balanced." << endl;
    }

    return 0;
}

void openInFile(ifstream& inFile){
    string filename;

    cout << "Enter the file name: ";
    cin >> filename;
    inFile.open(filename);

    while(inFile.fail()){
        cout << "Filename error" << endl;
        cout << "Enter a new file name: ";
        cin >> filename;
        inFile.clear();
        inFile.open(filename);
    }
}

bool balanceSymbols(ifstream& inFile){
    string phrase;
    int phraseSize = 0;
    stack<char> symbols;
    bool inputTracker = false;

    while(inFile >> phrase){
        if(phrase == "begin"){
            inputTracker = true;
        }
        else if(phrase == "end"){
            return inputTracker && symbols.empty();
        }
        else{
            if(!inputTracker){
                return false;
            }
        

            phraseSize = phrase.size();

            for(int i = 0; i < phraseSize; i++){
                if(phrase[i] == '(' || phrase[i] == '{' || phrase[i] == '['){
                    symbols.push(phrase[i]);
                }

                if(phrase[i] == ')'){
                    if(!symbols.empty() && symbols.top() == '('){
                        symbols.pop();
                    } 
                    else {
                        return false;
                    }
                }

                if(phrase[i] == '}'){
                    if(!symbols.empty() && symbols.top() == '{'){
                        symbols.pop();
                    } 
                    else {
                        return false;
                    }
                }

                if(phrase[i] == ']'){
                    if(!symbols.empty() && symbols.top() == '['){
                        symbols.pop();
                    } 
                    else {
                        return false;
                    }
                }
            }
        }
    }

    return false;
}