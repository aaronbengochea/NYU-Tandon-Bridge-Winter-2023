#include <iostream>
#include <vector>
using namespace std;


class Queue{
private:
    vector<int> queue;
    int front;
    int size;
public:
    void enqueue(int value);
    int dequeue();
    int queueFront();
    int queueBack();
    int queueSize();
    bool isEmpty();
    void clear();
    void print();
};

int main () {

    Queue vectQueue;
    int queueSize = 0;

    for(int i = 0; i < 20; i++){
        vectQueue.enqueue(i);
        //cout << "Added:" << i << endl;
    }

    //Printing queue post-enqueue
    vectQueue.print();

    //Printint current front of queue
    cout << "Current front of queue: " << vectQueue.queueFront() << endl;

    //Printing current back of queue
    cout << "Current back of queue: " << vectQueue.queueBack() << endl;

    //Printing if the queue is empty
    cout << "Is queue empty? ";
    if (vectQueue.isEmpty()){
        cout << "Yes";
    } else {
        cout << "No";
    }
    cout << endl;

    //Printing current queue size
    queueSize = vectQueue.queueSize();
    cout << "Current Queue Size: " << queueSize << endl << endl;

    //------------------------------------------------------------------------------------
    
    for(int i = 0; i < 10; i++){
        int dequeueValue = 0;
        // dequeueValue variable stores the dequeued value
        dequeueValue = vectQueue.dequeue();
        //cout << "Removed: " << dequeueValue << endl;
    }

    //Printing queue post-dequeue
    vectQueue.print();

    //Printing current front of queue
    cout << "Current front of queue: " << vectQueue.queueFront() << endl;

    //Printing current back of queue
    cout << "Current back of queue: " << vectQueue.queueBack() << endl;

    //Printing if the queue is empty
    cout << "Is queue empty? ";
    if (vectQueue.isEmpty()){
        cout << "Yes";
    } else {
        cout << "No";
    }
    cout << endl;

    //Printing current queue size
    queueSize = vectQueue.queueSize();
    cout << "Current Queue Size: " << queueSize << endl << endl;


    //Clears the vector, this function is also called everytime after you dequeue.
    //If you dequeue the last item of the vector, it clears itself which resets the front and size to 0.
    vectQueue.clear();

    //Printing queue post-clear
    vectQueue.print();

    //Printing if the queue is empty post-clear
    cout << "Is queue empty? ";
    if (vectQueue.isEmpty()){
        cout << "Yes";
    } else {
        cout << "No";
    }
    cout << endl;

    //Printing current queue size post-clear
    queueSize = vectQueue.queueSize();
    cout << "Current Queue Size: " << queueSize << endl << endl;

    
    

    return 0;
}

void Queue::enqueue(int value){
    queue.push_back(value);
    size++;
}

int Queue::dequeue(){
    int temp = queue[front];
    front++;
    size--;

    if (isEmpty()){
        clear();
    }

    return temp;
}

int Queue::queueFront(){
    return queue[front];
}

int Queue::queueBack(){
    return queue[front + size - 1];
}

int Queue::queueSize(){
    return size;
}

bool Queue::isEmpty(){
    return size == 0;
}

void Queue::clear(){
    queue.clear();
    front = 0;
    size = 0;
}

void Queue::print(){
    cout << "vectQueue: ";
    for(int i = front; i < front + size; i++){
        cout << queue[i] << ' ';
    }

    cout << endl;
}