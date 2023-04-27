#include <iostream>
using namespace std;



// Sorted array - Search
void findIndexSortedArray(int arr[], int arrSize, int search);

// Selection Sort + Helper Functions
int findIndexMin(int arr[], int low, int high);
void swap(int arr[], int cur, int low);
void selectionSort(int arr[], int arrSize);

// Merge Sort + Helper Functions
void merge(int arr[], int lowLeft, int highLeft, int highRight);
void mergeSort(int arr[], int low, int high);

void printArray(int arr[], int arrSize);

int main () {

    //Sorted Search Algo
    int arr1[] = {10,20,30,40,50,60,70,80,90,100};
    int arrSize = sizeof(arr1) / sizeof(int);
    int search = 22;

    cout << "Sorted Array Search Algo: " << endl;
    findIndexSortedArray(arr1,arrSize,search); 


    //Selection Sort Algo
    int arr2[] = {100,20,22,4,50,99,70,22,90,10020};
    int arrSize2 = sizeof(arr2) / sizeof(int);

    cout << "Selection Sort Algo: " << endl;
    printArray(arr2,arrSize2);
    selectionSort(arr2, arrSize2);
    printArray(arr2, arrSize2);

    // Merge Sort Algo
    int arr3[] = {100,20,22,4,50,99,70,22,90,10020};
    int arrSize3 = sizeof(arr3) / sizeof(int);

    cout << "Merge Sort Algo: " << endl;
    printArray(arr3,arrSize3);
    mergeSort(arr3,0, arrSize3-1);
    printArray(arr3, arrSize3);
     
    return 0;
}

void findIndexSortedArray(int arr[], int arrSize, int search){
    bool found = false;
    int high = arrSize - 1;
    int low = 0;
    int mid;
    int searchIndex;

    while ((found == false) && (low <= high)){
        mid = (high + low) / 2;

        if (arr[mid] == search){
            found = true;
            searchIndex = mid; 
        }

        else if (arr[mid] < search){
            low = mid + 1;
        }
        else if (arr[mid] > search){
            high = mid - 1;
        }
    }

    if (found == true){
        cout << searchIndex + 1 << endl;
    } else{
        cout << -1 << endl;
    }
}

void selectionSort(int arr[], int arrSize){
    int minIndex;
    int high = arrSize - 1;

    for (int i = 0; i < arrSize; i++){
        minIndex = findIndexMin(arr, i, high);
        swap(arr[i], arr[minIndex]);
    }  
}

int findIndexMin(int arr[], int low, int high){
    int min = arr[low];
    int minIndex = low;

    for (int i = low + 1; i < high; i++){
        if (arr[i] < min){
            min = arr[i];
            minIndex = i;
        }
    }

    return minIndex;   
}   

void swap(int arr[], int curr, int low){
    int temp;

    temp = arr[curr];
    arr[curr] = arr[low];
    arr[low] = temp;
}

void merge(int arr[], int lowLeft, int highLeft, int highRight){
    int lowRight = highLeft + 1;
    int size = highRight - lowLeft + 1;
    int indexRight, indexLeft, indexResult;

    int *mergedArr = new int[size];

    indexLeft = lowLeft;
    indexRight = lowRight;
    indexResult = 0;

    while ((indexLeft <= highLeft) && (indexRight <= highRight)){
        if (arr[indexLeft] < arr[indexRight]){
            mergedArr[indexResult] = arr[indexLeft];
            indexResult++;
            indexLeft++;
            
        }
        else {
            mergedArr[indexResult] = arr[indexRight];
            indexResult++;
            indexRight++;
        }
    }

    while (indexLeft <= highLeft){
        mergedArr[indexResult] = arr[indexLeft];
        indexLeft++;
        indexResult++;
    }

    while (indexRight <= highRight){
        mergedArr[indexResult] = arr[indexRight];
        indexRight++;
        indexResult++;
    }

    for (int i = 0, indexArr = lowLeft; i < size; i++, indexArr++){
        arr[indexArr] = mergedArr[i];
    }

    delete [] mergedArr;
}

void mergeSort(int arr[], int low, int high){
    int mid;

    if (low == high){
        return;
    }
    else{
        mid = (low + high) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

void printArray(int arr[], int arrSize){
    for (int i = 0; i < arrSize; i++){
        cout << arr[i] << ' ';
    }
    cout << endl;
}








