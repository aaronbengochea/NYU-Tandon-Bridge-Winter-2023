#include <iostream>
using namespace std;

const int MAX_NUMBER_OF_VALUES = 5;
double calcArrayAverage(int arr[], int arrSize);
void printAboveVal(int arr[], int arrSize, double val);
int readArray(int arr[], int arrPhysicalSize);
int main() {
    int valuesArray[MAX_NUMBER_OF_VALUES];
    int valuesArraySize;
    double average;

   // read data - will be implemented later
    valuesArraySize = readArray(valuesArray, MAX_NUMBER_OF_VALUES);

    // calculate average
    average = calcArrayAverage(valuesArray, valuesArraySize);
    cout<<"The average is "<<average<<endl;

    // print above average
    printAboveVal(valuesArray, valuesArraySize, average);

    return 0;
}

int readArray(int arr[], int arrPhysicalSize){
    int arrSize;
    int i;

    cout<<"Please enter number of values (no mare than "<<arrPhysicalSize<<"):"<<endl;
    cin>>arrSize;

    cout<<"Enter "<<arrSize<<" positive integers separated by a space:"<<endl;
    for(i = 0; i < arrSize; i += 1)
        cin>>arr[i];

    return arrSize;
}

double calcArrayAverage(int arr[], int arrSize){
    int sum;
    int i;
    double average;

    sum = 0;
    for(i = 0; i < arrSize; i += 1){
        sum += arr[i];
    }

    average = (double)sum / (double)arrSize;
    return average;
}

void printAboveVal(int arr[], int arrSize, double val){
    int i;

    cout<<"The values above "<<val<<" are ";
    for(i = 0; i < arrSize; i += 1) {
        if (arr[i] > val)
            cout << arr[i] << " ";
    }
    cout<<endl;
}