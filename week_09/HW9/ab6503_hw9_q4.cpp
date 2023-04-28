#include <iostream>
#include <vector>
using namespace std;

void oddsKeepEvensFlip(int arr[], int arrSize){
    vector<int> vectOdd;
    vector<int> vectEvenFlipped;

    for(int i = 0; i < arrSize; i++){
        if(arr[i] % 2 != 0){
            vectOdd.push_back(arr[i]);
        }
    }

    for(int i = arrSize - 1; i >= 0; i--){
        if(arr[i] % 2 == 0){
            vectEvenFlipped.push_back(arr[i]);
        }
    }

    int vectOddSize = vectOdd.size();
    int vectEvenFlippedSize = vectEvenFlipped.size();

    for(int i = 0; i < vectOddSize; i++){
        arr[i] = vectOdd[i]; 
    }

    int offset = 0;
    for(int i = 0; i < vectEvenFlippedSize; i++){
        offset = vectOddSize + i;
        arr[offset] = vectEvenFlipped[i];
    }
}

void printArray(int arr[], int arrSize){
    for (int i = 0; i < arrSize; i++){
        cout << arr[i] << " ";
    }
}


int main () {

    int arr[] = {5, 2, 11, 7, 6, 4};
    int arrSize = sizeof(arr) / sizeof(int);

    cout << "Original Array: ";
    printArray(arr,arrSize);
    cout << endl;

    oddsKeepEvensFlip(arr,arrSize);

    cout << "Transformed Array: ";
    printArray(arr,arrSize);




    return 0;
}