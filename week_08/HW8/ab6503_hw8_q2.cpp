#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(string str){

    int stringLen = str.size();
    int stringSplit = stringLen / 2;
    bool truthValue = false;

    if (stringLen % 2 == 0){
        for (int i = 0, j = stringLen - 1; i < stringSplit && j >= stringSplit; i++, j--){
            if (str[i] == str[j]){
                truthValue = true;
            }
            else if(str[i] != str[j]){
                truthValue = false;
                break;
            }
        }

    }
    else{
        for (int i = 0, j = stringLen - 1; i < stringSplit && j > stringSplit; i++, j--){
            if (str[i] == str[j]){
                truthValue = true;
            }
            else if(str[i] != str[j]){
                truthValue = false;
                break;
            }
        }
    }

    return truthValue;

}

void userStringGatherAndPalindromeChecker(){

    string str = "";
    bool truthValue = false;

    cout << "Please enter a word: ";
    cin >> str;

    truthValue = isPalindrome(str);

    if (truthValue == 1){
        cout << str << " is a palindrome.";
    }
    else {
        cout << str << " is not a palindrome.";
    }

}

int main () {

    userStringGatherAndPalindromeChecker();

    return 0;
}