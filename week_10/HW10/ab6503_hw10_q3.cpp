#include <iostream>
#include <vector>
using namespace std;

void printArray(int arr[], int arrSize){
    for (int i = 0; i < arrSize; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void indexSearchA(){
    int initArrSize = 300;
    int *initialArr = new int [initArrSize];

    int input = 0;
    int itrOne = 0;

    cout << "Section A: Using Heap Dynamic Arrays" << endl << endl;
    cout << "Please enter a sequence of positive integers, each in a separate line." << endl;
    cout << "End input by inserting a -1." << endl;
    while (input >= 0){
        cin >> input;
        if (input >= 1){
            initialArr[itrOne] = input;
            itrOne++;
        }
        
    }

    int *inputModArr = new int [itrOne];

    for (int i = 0; i < itrOne; i++){
        inputModArr[i] = initialArr[i];
    }

    delete [] initialArr;

    int searchInt = 0;
    cout << "Please enter a number you would like to search: " << endl;
    cin >> searchInt;

    int itrTwo = 0;
    int *initialArr2 = new int [itrOne];
    for (int i = 0; i < itrOne; i++){
        if(searchInt == inputModArr[i]){
            initialArr[itrTwo] = i + 1;
            itrTwo++;
        }
    }

    int *indexModArr = new int [itrTwo];
    for (int i = 0; i < itrTwo; i++){
        indexModArr[i] = initialArr[i];
    }


    cout << searchInt << " appears in lines ";
    for (int i = 0; i < itrTwo; i++){
        if (i != itrTwo - 1){
            cout << indexModArr[i] << ", ";
        }
        else{
            cout << indexModArr[i] << ".";
        }
    }
    delete [] initialArr2;
    delete [] inputModArr;
    delete [] indexModArr;
    cout << endl << endl;
}

void indexSearchB(){
    vector<int> inputVect;
    vector<int> indexVect;

    int input = 0;

    cout << "Section B: Using Vectors" << endl << endl;
    cout << "Please enter a sequence of positive integers, each in a separate line." << endl;
    cout << "End input by inserting a -1." << endl;
    while (input >= 0){
        cin >> input;
        if (input >= 1){
            inputVect.push_back(input);
        }  
    }

    int inputVectLen = inputVect.size();
    int searchInt = 0;
    int intStorage = 0;
    cout << "Please enter a number you would like to search: " << endl;
    cin >> searchInt;

    for (int i = 0; i < inputVectLen; i++){
        if(searchInt == inputVect[i]){
            intStorage = i + 1;
            indexVect.push_back(intStorage);
            intStorage = 0;
        }
    }

    int indexVectLen = indexVect.size();

    cout << searchInt << " appears in lines ";
    for (int i = 0; i < indexVectLen; i++){
        if (i != indexVectLen - 1){
            cout << indexVect[i] << ", ";
        }
        else{
            cout << indexVect[i] << ".";
        }
    }
}
int main () {

    indexSearchA();
    indexSearchB();


    return 0;
}