#include <iostream>
using namespace std;


int minInArray(int arr[], int arrSize){

    int minValue = arr[0];

    for (int i = 0; i < arrSize; i++){
        if (arr[i] < minValue){
            minValue = arr[i];
        }
    }

    return minValue;
}

void arrayFiller(int arr[], int arrSize){
    for (int i = 0; i < arrSize; i++){
        cin >> arr[i];
    }

}

void targetIndex(int arr[], int arrSize, int minValue){
    for (int j = 0; j < arrSize; j++){
        if (minValue == arr[j]){
            cout << j << " ";
        }
    }

}

void minIndexArray(int arr[], int arrSize){

    int minValue;

    cout << "Please enter 20 integers seperated by a space: " << endl;

    arrayFiller(arr,arrSize);

    minValue = minInArray(arr,arrSize);

    cout << endl;

    cout << "The minimum value is " << minValue << ", and it is located in the following indeces: ";

    targetIndex(arr,arrSize, minValue);
}


int main (){

    int array[20] = {};
    int arraySize = end(array) - begin(array);


    minIndexArray(array, arraySize);

    return 0;
}