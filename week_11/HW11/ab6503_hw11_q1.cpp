#include <iostream>
using namespace std;

void printTriangle(int n){
    if(n <= 0){
    return;
    }
   
    printTriangle(n-1);
 
    for(int i = 0; i < n; i++){
        cout << "*";
    }
 
    cout << endl;
}

void printOpositeTriangles(int n){
    if(n <= 0){
        return;
    }
 
    for(int i = 0; i < n; i++){
        cout << "*";
    } 
    cout << endl;
 
    printOpositeTriangles(n-1); 
 
    for(int i = 0; i < n; i++){
        cout << "*";
    }
 
    cout << endl;
}

void print_ruler(int n) {
    if (n < 1) {
        return;
    } 
    
    else {
        print_ruler(n - 1);

        for (int i = 0; i < n; i++) {
            cout << '-';
        }

        cout << endl;
        print_ruler(n - 1);
    }
}

int main () {

    printTriangle(4);

    cout << endl;

    
    printOpositeTriangles(4);

    cout << endl;

    print_ruler(4);

    return 0;
}