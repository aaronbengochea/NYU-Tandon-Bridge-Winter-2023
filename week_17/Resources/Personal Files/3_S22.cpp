// #7

Stack<T>& operator -(){
    vector<T> temp;
    while(!empty()){
        temp.push_back(pop())
    }

    Stack<T> newStack;
    for(T i: temp){
        newStack.push(i)
    }

    return newStack;
}

#include <stack>
#include <vector>
using namespace std;

template <class T>
class Queue{
    stack<T> stack;
}


//#3 - Summer 22
template <class T>
stack<T> Queue::reverseStack(){
    stack<T> newStack = stack;
    vector<T> tempVect;
    while(!stack.empty()){
        tempVect.push_back(newStack.top())
        newStack.pop();
    }

    for(T element: tempVect){
        newSack.push(element)
    }

    return newStack;

}

