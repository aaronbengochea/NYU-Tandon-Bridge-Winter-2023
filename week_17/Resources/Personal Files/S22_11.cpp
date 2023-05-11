#include <iostream>
#include <stack>
#include <queue>
using namespace std;

void printVect(vector<int>& vect){
    for(int i: vect){
        cout << i << ' ';
    }
    cout << endl;
}

void strangeSort(vector<int>& vect){
    queue<int> evenQueue;
    stack<int> oddStack;
    int nextToPush = 0;

    if(vect.size() != 0){
        for(int i = 0; i < vect.size(); i++){
            if(vect[i] % 2 == 0){
                evenQueue.push(vect[i]);
            }
            else{
                oddStack.push(vect[i]);
            }
        }

        for(int i = 0; i < vect.size(); i++){
            if(!evenQueue.empty()){
                nextToPush = evenQueue.front();
                evenQueue.pop();
                vect[i] = nextToPush;
            } else if(!oddStack.empty()){
                nextToPush = oddStack.top();
                oddStack.pop();
                vect[i] = nextToPush;
            }
        }
    
    }


}

int main () {

    vector<int> vect1{1, 2, 3, 4};
    vector<int> vect2{3, 5, 6, -2, 8}; 
    vector<int> vect3{7, 2, 3, 4, 9};
    vector<int> vect4{1, 7, 3, 4, 2, 8};
    vector<int> vect5{2, 4};
    vector<int> vect6{};

    printVect(vect1);
    printVect(vect2);
    printVect(vect3);
    printVect(vect4);
    printVect(vect5);
    printVect(vect6);

    strangeSort(vect1);
    strangeSort(vect2);
    strangeSort(vect3);
    strangeSort(vect4);
    strangeSort(vect5);
    strangeSort(vect6);

    cout << endl;

    printVect(vect1);
    printVect(vect2);
    printVect(vect3);
    printVect(vect4);
    printVect(vect5);
    printVect(vect6);


    return 0;
}