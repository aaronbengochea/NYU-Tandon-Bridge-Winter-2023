#include <iostream>
using namespace std;

class Thing { 
public: 
    Thing(int newval=42) {x = newval; } 
    int x; 
}; 
 
int main() { 
    Thing* one; 
    cout << (one->x) << endl; 
    return 0;
}