#include <iostream>
using namespace std;
#include <cmath>

int main() {
    int n;
    int lineCount, powerOf2;

    cout<<"Please enter a positive integer:"<<endl;
    cin>>n;

    cout<<"Using while"<<endl;
    lineCount = 1;
    while(lineCount <= n){
        powerOf2 = pow(2, lineCount-1);
        cout << lineCount << ". " << powerOf2 << endl;
        lineCount += 1;
    }

    cout<<endl<<"Using for"<<endl;
    for(lineCount = 1; lineCount <= n; lineCount += 1) {
        powerOf2 = pow(2, lineCount-1);
        cout << lineCount << ". " << powerOf2 << endl;
    }

    cout<<endl<<"Using while in the incremental approach"<<endl;
    lineCount = 1;
    powerOf2 = 1;
    while(lineCount <= n){
        cout << lineCount << ". " << powerOf2 << endl;
        lineCount += 1;
        powerOf2 *= 2;
    }

    cout<<endl<<"Using for in the incremental approach"<<endl;
    for(lineCount = 1, powerOf2 = 1; lineCount <= n; lineCount += 1, powerOf2 *= 2){
        cout << lineCount << ". " << powerOf2 << endl;
    }

    return 0;
}
