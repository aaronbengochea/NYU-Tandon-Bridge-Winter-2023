#include <iostream>
using namespace std;

bool isConsonant(char ch){

    ch = toupper(ch);

    return !(ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') && ch >= 65 && ch <= 90;
}

int countConsonants(string str, int strLen){

    if (strLen == 1){
        return isConsonant(str[0]);
    }

    return countConsonants(str, strLen - 1) + isConsonant(str[strLen - 1]);



}
int main () {

    string str = "PathwaytoCSTandonMS";
    int strLen = str.length();

    cout << "Total Consonants: " << countConsonants(str,strLen);

    return 0;
}