#include <iostream>
#include <string>
#include <vector>
using namespace std;

void printArray(int arr[], int arrSize){
    for (int i = 0; i < arrSize; i++){
        cout << arr[i] << " ";
    }
}

string *createWordsArray(string sentence, int &outWordsArrSize){
    string storage = "";
    int wordPosStart = 0;
    int wordLen = 0;
    int wordCount = 0;
    int sentenceLen = sentence.size();

    for (int i = 0; i < sentenceLen; i++){
        if (sentence[i] == ' '){
            wordCount++;
        }

        if (i == sentenceLen - 1){
            wordCount++;
        }
    }

    string *strArray = new string[wordCount];
    int strArrItr = 0;

    for (int i = 0; i < sentenceLen; i++){
        if (sentence[i] == ' '){
            storage = sentence.substr(wordPosStart, wordLen);
            strArray[strArrItr] = storage;
            wordPosStart = i + 1;
            wordLen = 0;
            strArrItr++;
        }

        if (sentence[i] != ' '){
            wordLen++;
        }
 
        if (i == sentenceLen - 1){
            storage = sentence.substr(wordPosStart, wordLen);
            strArray[strArrItr] = storage;
        }
    }

    outWordsArrSize = wordCount;
    return strArray;
}

int main () {

    string sentence = "You! can do it!";
    string *strArray = NULL;
    int wordCount = 0;

    strArray = createWordsArray(sentence, wordCount);

    cout <<"Array Size: " <<  wordCount << endl;

    for (int i = 0; i < wordCount; i++){
        cout << strArray[i] << " ";
    }



    return 0;
}