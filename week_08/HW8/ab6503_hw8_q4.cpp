#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

void printArray(int arr[],int arrSize){
    for (int i = 0; i < arrSize; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void passwordScrambler(){
    srand(time(0));

    int numbersArr[10];
    int numbersArrSize = end(numbersArr) - begin(numbersArr);

    int randArr[10];
    int randArrSize = end(randArr) - begin(randArr);

    const int PIN[5] = {0, 0, 6, 0, 3};
    int pinArrSize = end(PIN) - begin(PIN);

    int pinIndexArr[5];
    int pinIndexSize = end(pinIndexArr) - begin(pinIndexArr);

    int numsIndexArr[5];
    int numsIndexSize = end(numsIndexArr) - begin(numsIndexArr);

    int base = 3;

    for(int i = 0; i < 10; i++){
        numbersArr[i] = i;
    }

    for(int i = 0; i < 10; i++){
        randArr[i] = (rand() % base + 1);
    }

    
    cout << "PIN: ";
    printArray(numbersArr,numbersArrSize);

    cout << "NUM: ";
    printArray(randArr,randArrSize);


    int i = 0;
    while(i < pinArrSize){
        for (int j = 0; j < numbersArrSize; j++){
            if(numbersArr[j] == PIN[i]){
                pinIndexArr[i] = j;
            }
        }
        i++;
    }

    int z = 0;
    while(z < pinIndexSize){
        numsIndexArr[z] = randArr[pinIndexArr[z]];
        z++;
    }

    
    string input = "";

    cout << "Please enter your password: ";
    cin >> input;

    int j = 0;
    int truthValue = 0;
    int placeholder = 0;
    string stringPlaceholder = "";
    bool passwordMath = false;

    while(j < numsIndexSize){
        stringPlaceholder = input[j];
        placeholder = stoi(stringPlaceholder);
        if (placeholder == numsIndexArr[j]){
            truthValue++;
        }
        j++;
    }

    if (truthValue == 5){
        passwordMath = true;
    }

    if(passwordMath == true){
        cout << "Your PIN is correct." << endl;
    }
    else if(passwordMath == false){
        cout << "Your PIN is not correct." << endl;
    }

}


int main () {

    passwordScrambler();

    return 0;
}