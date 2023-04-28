#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

void vectorizeStringtoChar(vector<char> &charVector, string str){
    int strLen = str.size();

    for (int i = 0; i < strLen; i++){
        if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z')){
            charVector.push_back(str[i]);
        }
        
    }

}

void getStrings(string &strOne, string &strTwo){
    cout << "Please enter the first phrase: ";
    getline(cin, strOne);

    cout << endl;

    cout << "Please enter the second phrase: ";
    getline(cin, strTwo);

}

void anagramChecker(vector<char> vectorOne, vector<char> vectorTwo){
    int vecOneLen = vectorOne.size();
    int vecTwoLen = vectorTwo.size();
    int vecOneCharCount = 0;
    int vecTwoCharCount = 0;
    int longItr = 0;
    int j = 0;
    char tgtLetter;
    char tgtModLetter;


    if (vecOneLen == vecTwoLen){

        while (longItr < vecOneLen){
            tgtLetter = vectorOne[longItr];

            if (tgtLetter >= 'a' && tgtLetter <= 'z'){
                tgtModLetter = tgtLetter - 32;
            }
            else{
                tgtModLetter = tgtLetter + 32;
            }

            if (tgtLetter == vectorOne[j] || tgtModLetter == vectorOne[j]){
                vecOneCharCount++;
            }
            if (tgtLetter == vectorTwo[j] || tgtModLetter == vectorTwo[j]){
                vecTwoCharCount++;
            }

            if (j == vecOneLen - 1){
                if (vecOneCharCount == vecTwoCharCount){
                    j = -1;
                    longItr++;
                }
                else {
                    cout << endl;
                    cout << "The two phrases are not anagrams";
                    break;
                }
            }

            if (longItr == vecOneLen){
                cout << endl;
                cout << "The two phrases are anagrams!";
            }

            
            j++;

        }
    }
    else {
        cout << endl;
        cout << "The two phrases are not anagrams";
    }

}

void isAnagram(){
    string strOne, strTwo;
    vector<char> strOneVector, strTwoVector;

    cout << "Anagram Checker:" << endl;
    getStrings(strOne, strTwo);

    vectorizeStringtoChar(strOneVector, strOne);
    vectorizeStringtoChar(strTwoVector, strTwo);
    anagramChecker(strOneVector, strTwoVector);
}


int main () {

    isAnagram();

    return 0;
}