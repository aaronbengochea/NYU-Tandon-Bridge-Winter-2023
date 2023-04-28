#include <iostream>
using namespace std;

void reverseArray(int arr[], int arrSize){

    int arraySplit = arrSize / 2;
    int frontPlaceHolder = 0, backPlaceHolder = 0;    

    for (int i = 0, j = arrSize - 1; i < arraySplit && j >= arraySplit; i++, j--){
        frontPlaceHolder = arr[i];
        backPlaceHolder = arr[j]; 
        arr[i] = backPlaceHolder;
        arr[j] = frontPlaceHolder;
    }

}

void removeOdd(int arr[], int& arrSize){

    int j, count = 0;

    for (int i = 0; i < arrSize; i++){
        
        if(arr[i] % 2 != 0){
            int j = i + 1;

            for(int k = i;k < arrSize; k++){
                arr[k] = arr[j];
                j++;
            }

            count++;
            i--;
        }
    }

    arrSize -= count;
}

void splitParity(int arr[],int arrSize){

    int arraySplit = arrSize / 2;
    int frontPlaceHolder = 0, backPlaceHolder = 0;

    for(int i = 0, j = arrSize - 1;i < arraySplit || j > arraySplit && i <= j; i++, j--)
    {
        if (arr[i] % 2 == 0 && arr[j] % 2 != 0){
            frontPlaceHolder = arr[i];
            backPlaceHolder = arr[j];
            arr[i] = backPlaceHolder;
            arr[j] = frontPlaceHolder;
        }

        else if(arr[i] % 2 != 0 && arr[j] % 2 != 0){
            j++;
        }
        else if(arr[i] % 2 == 0 && arr[j] % 2 == 0){
            i--;
        }
    }

}

void printArray(int arr[],int arrSize){
    for (int i = 0; i < arrSize; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main () {

    int arrOne[] = {1, 2, 3, 4, 5, 6};
    int arrayOneSize = end(arrOne) - begin(arrOne);

    int arrTwo[] = {1, 2,7,9, 3, 4, 5, 6};
    int arrayTwoSize = end(arrTwo) - begin(arrTwo);

    int arrThree[] = {12,15,7,1,3,296,500,1750,222,1,1,1,1,1,1,3,2,3,1,3};
    int arrayThreeSize = end(arrThree) - begin(arrThree);


    reverseArray(arrOne, arrayOneSize);
    cout << "Array One (Flipped): ";
    printArray(arrOne,arrayOneSize);

    removeOdd(arrTwo, arrayTwoSize);
    cout << "Array Two (Remove Odds): ";
    printArray(arrTwo,arrayTwoSize);

    splitParity(arrThree, arrayThreeSize);
    cout << "Array Three (Split Parity): ";
    printArray(arrThree, arrayThreeSize);


    return 0;
}