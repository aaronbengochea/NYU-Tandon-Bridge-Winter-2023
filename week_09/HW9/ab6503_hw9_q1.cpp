#include <iostream>
#include <string>
#include <cstring>
using namespace std;

void getString(string &str){
    cout << "Please enter a line of text: ";
    getline(cin, str);
}

void wordCounter(string str, int &wordCount){
    
    int len = str.size();
    int altItr = 0;

    for (int i = 0; i < len; i++){

        if (i >= 1){
            altItr = i - 1;
        }

        if ((str[i] == '.' || str[i] == ',') && (str[altItr] >= 'A' && str[altItr] <= 'Z' || str[altItr] >= 'a' && str[altItr] <= 'z')){
            wordCount++;
        }

        if (str[i] == ' ' && str[altItr] != '.' && str[altItr] != ',' && str[altItr] != ' '){
            wordCount++;
        }

        if (i == len - 1 && str[i] != ' ' && str[i] != '.' && str[i] != ','){
            wordCount++;
        }    
    }

    cout << endl;
    cout << wordCount << "\t" << "words" << endl;
}

void charCounter(string str){
    int charCount = 0;
    char asciiCheckerUpper = 'A';
    char asciiCheckerLower = asciiCheckerUpper + 32;
    int i = 0;
    int len = str.size();

    char* charArray = new char[len];

    // for(int j = 0; j < len; j++){
    //     if((str[j] >= 'A' && str[j] <= 'Z') || (str[j] >= 'a' && str[j] <= 'z')){
    //         charArray[j] = str[j];
    //     }
    // }
    cout << len << endl;

    for(int j = 0; j < len; j++){
        charArray[j] = str[j];
    }


    for(int j = 0; j < len; j++){
        cout << charArray[j] << " ";
    }
    cout << endl;



    while (asciiCheckerUpper < 91){
        if (i == len){
            i = 0;
        }

        if (charArray[i] == asciiCheckerUpper || charArray[i] == asciiCheckerLower){
            charCount++;
        }

        if (i == len - 1){
            if (charCount != 0){
                cout << charCount << '\t' << asciiCheckerLower << endl;
            }
            charCount = 0;
            asciiCheckerUpper++;
            asciiCheckerLower++;
        }

        i++;
    }

    delete[] charArray;

}

void wordAndCharCounter(){
    string str = "";
    int wordCount = 0;
    
    getString(str);
    wordCounter(str,wordCount);
    charCounter(str);

}


int main () {

    wordAndCharCounter();

    return 0;
}