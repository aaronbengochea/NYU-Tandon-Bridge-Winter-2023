#include <iostream> 
using namespace std;

int main () {

    int x = 100;
    int y = 200;
    int* ptr;
    int* ptr2 = NULL;
    int **ptr3 = NULL;


    ptr = &x;
    *ptr = 50;
    ptr3 = *ptr;
    *ptr3 = 60;

    cout << "Location: " << ptr << endl;
    cout << "Substance: " << *ptr << endl << endl;

    cout << "Location: " << ptr3 << endl;
    cout << "Substance: " << *ptr3 << endl << endl;


    ptr2 = &x;
    *ptr2 = 20;

    cout << "Location: " << ptr2 << endl;
    cout << "Substance: " << *ptr2 << endl;




    return 0;
}