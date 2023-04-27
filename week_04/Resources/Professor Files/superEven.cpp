#include <iostream>
using namespace std;

int main() {
    int userInput, num;
    int currDig;
    bool seenOddDigit;

    cout<<"Please enter a positive integer"<<endl;
    cin>>userInput;

    num = userInput;
    seenOddDigit = false;
    while((num > 0) && (seenOddDigit == false)){
        currDig = num % 10;
        if ((currDig % 2) == 1)
            seenOddDigit = true;
        num = num / 10;
    }

    if(seenOddDigit == false)
        cout<<userInput<<" is super even"<<endl;
    else
        cout<<userInput<<" is not super even"<<endl;

    return 0;
}
