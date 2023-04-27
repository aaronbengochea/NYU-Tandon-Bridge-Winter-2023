#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <cstring>
#include <sstream>
using namespace std;

class LList;
class Node;

class Person{
private:
    double paid;
    double owed;
    string name;
public:
    Person(double newPaid, double newOwed, string newName) : paid(newPaid), owed(newOwed), name(newName) {}
    Person(double newPaid, string newName) : paid(newPaid), owed(0), name(newName) {}
    Person() : paid(0), owed(0), name("") {}
    // Person(const Person& rhs) : paid(rhs->paid), owed(rhs->owed), name(rhs->name) {*this = rhs; }
    // Person& operator=(const Person& rhs);
    // ~Person() {}
    double getPaid() const {return paid;}
    double getOwed() const {return owed;}
    string getName() const {return name;}
    void setPaid(double newPaid) {paid = newPaid;}
    void setOwed(double newOwed) {owed = newOwed;}
    void setName(string newName) {name = newName;}
    friend class Node;
};

class Node{
private:
    Person data;
    Node* prev;
    Node* next;
    
public:
    Node(const Person& person = Person(), Node* prev = nullptr, Node* next = nullptr);
    // Node(const Node& rhs) : data(rhs->data), next(rhs->next) {*this = rhs;}
    // Node& operator=(const Person& rhs);
    // ~Node() {}
    Person& getData() {return data;}
    Node* getPrev() {return prev;}
    Node* getNext() {return next;}
    friend class LList;
};

class LList{
    int size;
    Node* head;
    Node* tail;
public:
    LList();
    LList(const LList& rhs);
    //LList& operator=(const LList& rhs);
    ~LList() {}
    int getSize() const;
    Node* getHead() const;
    Node* getTail() const;
    void insertAfter(const Person& data, Node* target);
    void insertAtTail(const Person& data);
    void printList();
    //void insertAtHead(Person& info);
    //void insertAtTail();
};

void openInputFile(ifstream& inFile);
void storePeople(LList& peopleList, ifstream& inFile);
void calculateOwed(LList& peopleList);
void fillOwedVector(LList& peopleList, vector<Node*>& posNodeVect, vector<Node*>& negNodeVect);
void settleDebts(vector<Node*> posNodeVect, vector<Node*> negNodeVect);



int main () {

    LList list1;
    LList contributions;
    ifstream inFile;

    cout << "Open the file containing everyone's contribution" << endl;
    openInputFile(inFile);

    cout << "Read and store contributions..." << endl << endl;
    storePeople(contributions, inFile);



    //contributions.printList();
    calculateOwed(contributions);

    //prints LL to check if owed variables are set correctly
    //contributions.printList();  // working up until here

    vector<Node*> pos;
    vector<Node*> neg;

    fillOwedVector(contributions, pos, neg);

    //iterates thru both vectors so I can check they are correct
    /*for (Node* i: pos){
        cout << i->getData().getName() << endl;
    }

    cout << endl;

    for (Node* j: neg){
        cout << j->getData().getName() << endl;
    }

    cout << endl;
    */

    settleDebts(pos, neg);


// Exploratory code....

//     Person a1 = Person(10, "cicy");
//     Person a2 = Person(100, "bobo");
//     Person a3 = Person(20, "frank");

//     list1.insertAtTail(a1);
//     list1.insertAtTail(a2);
//     list1.insertAtTail(a3);
//     list1.printList();

//     // cout << list1.getSize() << endl << endl;
//     // Node* temp4 = list1.getHead();

//     // cout << temp4->getData().getName() << endl;
//     // cout << temp4->getData().getPaid() << endl;
//     // cout << temp4->getData().getOwed() << endl;

//     // temp4 = temp4->getNext();

//     // cout << temp4->getData().getName() << endl;
//     // cout << temp4->getData().getPaid() << endl;
//     // cout << temp4->getData().getOwed() << endl;

//     // temp4 = temp4->getNext();

//     // cout << temp4->getData().getName() << endl;
//     // cout << temp4->getData().getPaid() << endl;
//     // cout << temp4->getData().getOwed() << endl;


    

    // build the person object 
    Person person1;
    cout << person1.getPaid() << endl;
    cout << person1.getOwed() << endl;
    person1.setOwed(50);
    cout << person1.getOwed() << endl;
    cout << person1.getName() << endl;
   person1.setName("Sage");
    cout << person1.getName() << endl;

    Person person2;

    person2 = person1;
    cout << person1.getPaid() << endl;
    cout << person1.getOwed() << endl;
    cout << person1.getName() << endl;



    
   

//     // then pass it to node constructor === works
//     Node* temp2 = new Node(person1);
//     cout << endl;
//     cout << temp2->getData().getOwed() << endl;
//     cout << temp2->getData().getName() << endl;
//     cout << temp2->getData().getPaid() << endl << endl;


//     // build person object then pass it to node constructor ====  works
//     Person person2 = Person(55, "Aaron");
//     Node* temp3 = new Node(person2);
//     cout << temp3->getData().getOwed() << endl;
//     cout << temp3->getData().getName() << endl;
//     cout << temp3->getData().getPaid() << endl << endl;
    
    
    

    return 0;
}

Node::Node(const Person& person, Node* prev, Node* next) : data(person), prev(prev), next(next) {}




// LList class

LList::LList(){
    size = 0;
    head = new Node;
    tail = new Node;
    head->next = tail;
    tail->prev = head;
}

LList::LList(const LList& rhs){
    size = 0;
    head = new Node;
    tail = new Node;
    head->next = tail;
    tail->prev = head;
    *this = rhs;
}



void LList::printList(){
    Node* temp;
    Node* temp2;
    temp = getHead();
    temp2 = getTail();


    while (temp != temp2){
        cout << "Person Name: " << temp->getData().getName() << endl;
        cout << "Amount Paid: " << temp->getData().getPaid() << endl;
        cout << "Amount Owed: " << temp->getData().getOwed() << endl << endl;
        temp = temp->next;
    }

    cout << endl;
}

void LList::insertAfter(const Person& data, Node* target){
    Node* temp = new Node(data, target, target->next);
    target->next = temp;
    temp->next->prev = temp;
    size++;

}

void LList::insertAtTail(const Person& data){
    insertAfter(data, tail->prev);
}

Node* LList::getHead() const {
    return head->next;
}

Node* LList::getTail() const {
    return tail;
}

int LList::getSize() const {
    return size;
}



void openInputFile(ifstream& inFile){
    string fileName;

    cout << "Please enter the file name: ";
    cin >> fileName;
    inFile.open(fileName);

    while (inFile.fail()){
        cout << "Error in the file name submitted" << endl;
        cout << "Please enter the file name: ";
        cin >> fileName;
        inFile.clear();
        inFile.open(fileName);
    }
}

void storePeople(LList& peopleList, ifstream& inFile){
    double paid;
    string name;


    while (inFile >> paid){
        inFile.ignore(100, ' ');
        getline(inFile, name);
        peopleList.insertAtTail(Person(paid, name));
    }



}

void calculateOwed(LList& peopleList){
    Node* tempOne;
    Node* tempTwo;
    tempOne = peopleList.getHead();
    tempTwo = peopleList.getTail();

    double sum = 0;
    int count = 0;
    


    while (tempOne != tempTwo){
        sum += tempOne->getData().getPaid();
        count++;
        tempOne = tempOne->getNext();
    }

    double avg = sum / count;

    // cout << sum << endl;
    // cout << count << endl;
    // cout << avg << endl;

    tempOne = peopleList.getHead();
    double paid = 0;
    while (tempOne != tempTwo){
        paid = tempOne->getData().getPaid();
        tempOne->getData().setOwed(paid - avg);
        tempOne = tempOne->getNext();
    }
}

void fillOwedVector(LList& peopleList, vector<Node*>& posNodeVect, vector<Node*>& negNodeVect){
    Node* tempOne;
    Node* tempTwo;
    tempOne = peopleList.getHead();
    tempTwo = peopleList.getTail();

    while (tempOne != tempTwo){
        if (tempOne->getData().getOwed() > 0){
            posNodeVect.push_back(tempOne);
        } 
        else if (tempOne->getData().getOwed() < 0){
            negNodeVect.push_back(tempOne);
        }

        tempOne = tempOne->getNext();
    }

}

void settleDebts(vector<Node*> posNodeVect, vector<Node*> negNodeVect){
    int posVectSize = posNodeVect.size();
    int negVectSize = negNodeVect.size();


    int i = 0;
    int j = 0;
    double currPos = 0;
    double currNeg = 0;
    int posNameSize = 0;
    int negNameSize = 0;
    string posName;
    string negName;

    

    while (i < posVectSize && j < negVectSize){
        currPos = posNodeVect[i]->getData().getOwed();
        posName = posNodeVect[i]->getData().getName();
        posNameSize = posName.size();


        currNeg = negNodeVect[j]->getData().getOwed();
        negName = negNodeVect[j]->getData().getName();
        negNameSize = negName.size();



        cout << "Curr Pos Owed: " << posNodeVect[i]->getData().getOwed() << endl;
        cout << "Curr Pos Name: " << posNodeVect[i]->getData().getName() << endl;
        cout << "Curr Neg Owed: " << negNodeVect[j]->getData().getOwed() << endl;
        cout << "Curr Neg Name: " << negNodeVect[j]->getData().getName() << endl;

        cout << "Curr Pos: " << currPos << endl;
        cout << "Pos Name: " << posName << endl;
        cout << "Pos Name Size: " << posNameSize << endl;
        cout << "Curr Neg: "  << currNeg << endl;
        cout << "Neg Name: " << negName << endl;
        cout << "Neg Name Size: " << negNameSize << endl;
        

        if (currPos >= abs(currNeg)){
            cout << negName;
            cout << ", gives to " <<  posName << currPos << endl << endl;
            posNodeVect[i]->getData().setOwed(currPos + currNeg);
            negNodeVect[j]->getData().setOwed(0);
            j++;

        }
        else{
            cout <<  negName;   
            cout << ", gives to " <<  posName  << currNeg <<endl << endl;
            posNodeVect[i]->getData().setOwed(0);
            negNodeVect[j]->getData().setOwed(currPos + currNeg);
            i++;
        }

    }



}

