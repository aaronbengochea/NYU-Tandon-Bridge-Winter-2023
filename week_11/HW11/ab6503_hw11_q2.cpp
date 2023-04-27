#include <iostream>
using namespace std;

void printArray(int arr[], int arrLen) {

    for (int i = 0; i < arrLen; i++) {
        cout << arr[i];

        if (i != arrLen - 1) {
            cout << ", ";
        }
    }

    cout << endl;
}

int sumOfSquares(int arr[], int arrLen) {
    if (arrLen == 1) {
        return arr[0] * arr[0];
    } 
    else {
        int last = arr[arrLen - 1];

        return sumOfSquares(arr, arrLen - 1) + last * last;
    }
}

bool isSorted(int arr[], int arrLen) {
    if (arrLen == 1) {
        return true;
    } 
    else {
        int last = arr[arrLen - 1];
        int onePriorToLast = arr[arrLen - 2];

        return isSorted(arr, arrLen - 1) && (onePriorToLast <= last);
    }
}



int main() {
    int arrOne[] = {2, -1, 3, 10};
    int arrOneLen = sizeof(arrOne) / sizeof(*arrOne);

    cout << "Array: ";
    printArray(arrOne, arrOneLen);

    cout << "Sum of Squares: " << sumOfSquares(arrOne, arrOneLen) << endl;
    cout << "Sorted Array: ";

    if (isSorted(arrOne, arrOneLen)) {
        cout << "True" << endl;
    } 
    else {
        cout << "False" << endl;
    }

    return 0;
}

