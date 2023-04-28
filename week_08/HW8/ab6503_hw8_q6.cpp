#include <iostream>
#include <string>
using namespace std;

void numbersOnlyFlag(bool& flag, string storage, string sentence, int itr){
    if (storage[0] == ' ' && sentence[itr] >= '0' && sentence[itr] <= '9'){
        flag = true;
    }

    if (storage[0] >= '0' && storage[0] <= '9' && sentence[itr] == ' '){
        flag = false;
    }

}

void replaceWithX(bool flag, string& sentence, int itr){
    if (sentence[itr] >= '0' && sentence[itr] <= '9' && flag == true ){
        sentence[itr] = 'x';
    }
}

void charStorage(string& storage, string sentence, int itr){
     if (itr > 1){
            storage[0] = sentence[itr];
        }

}

void digitObfuscation(){
    string str;
    int i;
    bool numberOnly = false;
    string storage = "";

    cout << "Enter a line of text: ";
    getline(cin, str);

    storage = str[0];

    for (i = 0; i <= str.length(); i++)
    {

        numbersOnlyFlag(numberOnly, storage, str, i);
        replaceWithX(numberOnly,str, i);
        charStorage(storage, str, i);

    }

    cout << "Edited text: " << str << endl;

}


int main () {

    digitObfuscation();
    
    return 0;
}


