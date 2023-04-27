#include <iostream>
using namespace std;

bool isSymmetricDistribution(int arr[], int n){
    int smallestNum = n;
    int largestNum = 1;
    bool isSymmetric = true;

    for (int i = 0; i < n; i++){
        if (arr[i] < smallestNum){
            smallestNum = arr[i];
        }
    }

    for (int i = 0; i < n; i++){
        if (arr[i] > largestNum){
            largestNum = arr[i];
        }

        if (arr[i] > n || arr[i] < 1){
            return false;
        }
    }


    int smallCount = 0;
    int largeCount = 0;
    int itr = 0;

    while (itr < n){
        if (smallestNum == largestNum){
            return isSymmetric;
        }

        for (int i = 0; i < n; i++){
            if (smallestNum == arr[i]){
                smallCount++;
            }
            if (largestNum == arr[i]){
                largeCount++;
            }
            
        }

        cout << "Small Num: " << smallestNum << endl;
        cout << "Large Num: " << largestNum << endl;
        cout << "Small count: " << smallCount << endl;
        cout << "Large count: " << largeCount << endl;

        if (smallCount != largeCount){
            return false;
        }
        else if(smallCount == largeCount){
            smallestNum++;
            largestNum--;
        }
        
        itr++;
        largeCount = 0;
        smallCount = 0;
    }

    return isSymmetric;

}

int main (){
    int arr[] = {3,3,3}; // 15 size
    int arrSize = sizeof(arr) / sizeof(int);
    bool symmetric;

    

    symmetric = isSymmetricDistribution(arr,arrSize);

    cout << endl;
    if (symmetric == true){
        cout << "Yes, The array is symmetric!";
    }
    else{
        cout << "No, the array is not symmetric.";
    }




}