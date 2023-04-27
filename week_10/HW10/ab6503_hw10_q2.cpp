#include <iostream>
#include <vector>
using namespace std;

int *findMissing(int arr[], int &tgt, int &resArrSize){

    int elementCount = 0;
    int i = 0;
    int j = 0;

    while (i <= tgt){
    
        if (arr[j] == i){
            j = 0;
            i++;
        }
        else if (arr[j] != i && j != resArrSize - 1){
            j++;
        }


        if (j == resArrSize - 1 && arr[j] != i){
            elementCount++;
            i++;
            j = 0;
            
        }
        else if (j == resArrSize - 1 && arr[j] == i){
            i++;
            j = 0;
        }

    }

    int *newArray = new int [elementCount];
    i = 0;
    j = 0;
    int newArrItr = 0;

    while (i <= tgt){
    
        if (arr[j] == i){
            j = 0;
            i++;
        }
        else if (arr[j] != i && j != resArrSize - 1){
            j++;
        }


        if (j == resArrSize - 1 && arr[j] != i){
            newArray[newArrItr] = i;
            newArrItr++;
            i++;
            j = 0;
            
        }
        else if (j == resArrSize - 1 && arr[j] == i){
            i++;
            j = 0;
        }

    }

    resArrSize = elementCount;
    return newArray;

}

void printArray(int arr[], int arrSize){
    for (int i = 0; i < arrSize; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main () {

    int arr[] = {3, 1, 3, 0, 6, 4, 22};
    int arrLen = sizeof(arr) / sizeof(int);
    int *arrPtr = NULL;
    int tgt = 6;
    int resultArrSize = arrLen;

    arrPtr = findMissing(arr, tgt, resultArrSize);

    cout << "Original Arr: ";
    printArray(arr, arrLen);
    cout << "Target Int (n) = " << tgt << endl;
    cout << "New Arr Len: " << resultArrSize << endl;
    cout << "Arr Contents: ";
    printArray(arrPtr, resultArrSize);



    return 0;
}