#include <iostream>
#include <set>
using namespace std;


int main () {

    set<int> s;

    s.insert(10);
    s.insert(20);
    s.insert(10);
    s.insert(30);
    s.insert(10);
    s.insert(40);

    set<int>::iterator itr;

    itr = s.begin();
    while(itr != s.end()){
        cout << *itr << ' ';
        itr++;
    }




    return 0;
}