#include <iostream>
using namespace std;

int main() {
    int currInput;
    int sum, count, evensCount, min;
    bool seenEndOfInput, isFirstItereation;
    double average;

    cout<<"Please enter a sequence of positive integers.";
    cout<<"Each in a separate line."<<endl;
    cout<<"End your sequence by typing -1:"<<endl;

    seenEndOfInput = false;
    isFirstItereation = true;
    sum = 0;
    count = 0;
    evensCount = 0;
    while(seenEndOfInput == false){
        //1. read a number
        cin>>currInput;
        if(currInput == -1)
            seenEndOfInput = true;
        else {
            //2. add it to statistics
            sum += currInput;
            count += 1;
            if((currInput % 2) == 0)
                evensCount += 1;
            if (isFirstItereation == true){
                min = currInput;
                isFirstItereation = false;
            }
            else {
                if (currInput < min)
                    min = currInput;
            }
        }
    }

    average = (double)sum / (double)count;
    cout<<"Sum is "<<sum<<endl;
    cout<<"Average is "<<average<<endl;
    cout<<"Number of evens is "<<evensCount<<endl;
    cout<<"Minimum value is "<<min<<endl;

    return 0;
}
