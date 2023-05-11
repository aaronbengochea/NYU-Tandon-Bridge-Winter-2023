#include <iostream>
#include <stack>
using namespace std;

int main () {
    stack<int> stack1;
    stack<int> stack2;


    stack1.push(1);
    stack1.push(2);
    stack1.push(3);

    stack2 = stack1;


    cout << stack2.size() << endl;
    cout << stack1.size() << endl;

   while(!stack2.empty()){
        cout << stack2.top() << ' ';
        stack2.pop();
    } 
    cout << endl;

    cout << stack2.size() << endl;
    cout << stack1.size() << endl;



    return 0;
}