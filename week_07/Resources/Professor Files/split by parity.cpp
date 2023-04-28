#include <iostream>
using namespace std;

void splitNumberByParity(int num, int& outEvenDigitsNum, int& outOddDigitsNum);

int main() {
    int userInput;
    int evenDigitsNum, oddDigitsNum;

    cout<<"Please enter a positive integer, with digits 1-9"<<endl;
    cin>>userInput;

    splitNumberByParity(userInput, evenDigitsNum, oddDigitsNum);

    cout<<"Your even digits number is "<<evenDigitsNum<<endl;
    cout<<"Your odd digits number is "<<oddDigitsNum<<endl;
    cout<<"Thier sum is "<<evenDigitsNum + oddDigitsNum<<endl;

    return 0;
}

void splitNumberByParity(int num, int& outEvenDigitsNum, int& outOddDigitsNum){
    int currDig;
    int evenDigitsNum, oddDigitsNum;
    int evenWeight, oddWeight;

    evenDigitsNum = 0;
    evenWeight = 1;
    oddDigitsNum = 0;
    oddWeight = 1;
    while(num > 0){
        currDig = num % 10;

        if(( currDig % 2) == 0){
            evenDigitsNum += currDig * evenWeight;
            evenWeight *= 10;
        }
        else{
            oddDigitsNum += currDig * oddWeight;
            oddWeight *= 10;
        }

        num = num / 10;
    }

    outEvenDigitsNum = evenDigitsNum;
    outOddDigitsNum = oddDigitsNum;
}