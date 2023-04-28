#include <iostream> 
#include <vector>
using namespace std;

void printArray(int *arr, int arrSize){
    for (int i = 0; i < arrSize; i++){
        cout << arr[i] << " ";
    }
}

int *getPosNums1(int *arr, int arrSize, int& outPosArrSize){
    int size = 0;

    for (int i = 0; i < arrSize; i++){
        if (arr[i] > 0){
            size++;
        }
    }
    
    int *newArray = new int[size];
    int counter = 0; 

    for (int i = 0; i < arrSize; i++){
        if (arr[i] > 0){
            newArray[counter] = arr[i];
            counter++;
        }
    }

    outPosArrSize = size;

    return newArray;
}

void posNums1(int *arr, int arrSize, int& outPosArrSize){

    int *posNumsOne = getPosNums1(arr, arrSize, outPosArrSize);

    cout << "Original array: ";
    printArray(arr, arrSize);
    cout << endl << endl;

    cout << "The new address = " << posNumsOne << " and the new size = " << outPosArrSize << endl;
    cout << "New array: ";
    printArray(posNumsOne, outPosArrSize);
    delete [] posNumsOne;
    cout << endl << endl;



}

int *getPosNums2(int *arr, int arrSize, int *outPosArrSizePtr){
    int size = 0;

    for (int i = 0; i < arrSize; i++){
        if (arr[i] > 0){
            size++;
        }
    }

    int *newArray = new int[size];
    int counter = 0;

    for (int i = 0; i < arrSize; i++){
        if (arr[i] > 0){
            newArray[counter] = arr[i];
            counter++;
        }
    }

    *outPosArrSizePtr = size;

    return newArray;

}

void posNums2(int *arr, int arrSize, int *outPosArrSize){
    cout << "Original Array: ";
    printArray(arr, arrSize);
    cout << endl << endl;

    int *posNumsTwo = getPosNums2(arr, arrSize, outPosArrSize);
    cout << "The new address = " << posNumsTwo << " and the new size = " << *outPosArrSize << endl;
    cout << "New Array: ";
    printArray(posNumsTwo, *outPosArrSize);
    delete [] posNumsTwo;
    cout << endl << endl;


}

void getPosNums3(int *arr, int arrSize, int *&outPosArr, int &outPosArrSize){
    int size = 0;

    for (int i = 0; i < arrSize; i++){
        if (arr[i] > 0){
            size++;
        }
    }
    
    int *newArray = new int[size];
    int counter = 0;

    for (int i = 0; i < arrSize; i++){
        if (arr[i] > 0){
            newArray[counter] = arr[i];
            counter++;
        }
    }

    outPosArr = newArray;
    outPosArrSize = size;

}

void posNums3(int *arr, int arrSize, int *&outPosArr, int &outPosArrSize){
    cout << "Original Array: ";
    printArray(arr, arrSize);
    cout << endl << endl;

    getPosNums3(arr, arrSize, outPosArr, outPosArrSize);
    cout << "The new address = " << outPosArr << " and the new size = " << outPosArrSize << endl;
    cout << "New Array: ";
    printArray(outPosArr, outPosArrSize);
    cout << endl << endl;

}

void getPosNums4(int *arr, int arrSize, int **outPosArrPtr, int *outPosArrSizePtr){
    int size = 0;

    for (int i = 0; i < arrSize; i++){
        if (arr[i] > 0){
            size++;
        }
    }
    
    int *newArray = new int[size];
    int counter = 0;

    for (int i = 0; i < arrSize; i++){
        if (arr[i] > 0){
            newArray[counter] = arr[i];
            counter++;
        }
    }

    *outPosArrPtr = newArray;
    *outPosArrSizePtr = size;
}

void posNums4(int *arr, int arrSize, int **outPosArrPtr, int *outPosArrSizePtr){
    cout << "Original Array: ";
    printArray(arr, arrSize);
    cout << endl << endl;

    getPosNums4(arr, arrSize, outPosArrPtr, outPosArrSizePtr);
    cout << "The new address = " << outPosArrPtr << " and the new size = " << *outPosArrSizePtr << endl;
    cout << "New Array: ";
    printArray(*outPosArrPtr, *outPosArrSizePtr);
    cout << endl << endl;

}

int main () {

    int originalArr[] = {3, -1, -3, 0, 6, 4, 7, -8, 296, 5000};
    int arrSize = sizeof(originalArr) / sizeof(int);

    cout << "Section A: " << endl;
    int posArrSizeOne = 0;
    // check for int* getPosNums1 function call within the posNums1 function
    posNums1(originalArr, arrSize, posArrSizeOne);

    cout << "Section B: " << endl;
    int posArrSizeTwo = 0;
    int *posArrSizeTwoPtr = &posArrSizeTwo;
    // check for int* getPosNums2 function call within the posNums2 function
    posNums2(originalArr, arrSize, posArrSizeTwoPtr);

    cout << "Section C: " << endl;
    int *posNumsThree = new int[arrSize];
    int posArrSizeThree = arrSize;
    // check for void getPosNums3 function call within the posNums3 function
    posNums3(originalArr, arrSize, posNumsThree, posArrSizeThree);

    cout << "Section D: " << endl;
    int posArrSizeFour = arrSize;
    int *posNums4SizePtr = &posArrSizeFour;
    int *posNums4Arr = new int[posArrSizeFour];
    int **posNums4ArrLoc = &posNums4Arr;
    // check for void getPosNums4 function call within the posNums4 function
    posNums4(originalArr, arrSize, posNums4ArrLoc, posNums4SizePtr);


    return 0;
}