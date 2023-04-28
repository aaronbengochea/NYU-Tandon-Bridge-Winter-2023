#include <iostream>
#include <string>
using namespace std;

void formattedName(){
    string firstName = "", middleName = "", lastName = "";

    cout << "Input your first, middle and last names: " << endl;
    cin >> firstName >> middleName >> lastName;

    cout << endl;
    cout << "Output: " << endl;
    cout << lastName << ", " << firstName << " " << middleName[0] << ".";
}

int main () {

    formattedName();

    return 0;
}