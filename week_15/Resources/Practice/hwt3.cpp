#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>
using namespace std;

// Build big 3 for all of the classes
// Round out member functions in the LL

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
    double getPaid() const {return paid;}
    double getOwed() const {return owed;}
    string getName() const {return name;}
    void setPaid(double newPaid) {paid = newPaid;}
    void setOwed(double newOwed) {owed = newOwed;}
    void setName(string newName) {name = newName;}
};

// I do need it; when I use getHead() I am using a = operator; the destruction can occur in the LL; 
class Node{
private:
    Person data;
    Node* prev;
    Node* next;
    
public:
    Node(const Person& person = Person(), Node* prev = nullptr, Node* next = nullptr);
    // Node(const Node& rhs) : data(rhs->data), next(rhs->next) {*this = rhs;}
    // Node& operator=(const Person& rhs);
    // ~Node() {} --> dont need destructor bc nodes in heap mem are managed by LL class, node ptrs are on the stack and therefore clear in mem 
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
    LList& operator=(const LList& rhs);
    ~LList();
    int getSize() const;
    Node* getHead() const;
    Node* getTail() const;
    void insertAfter(const Person& data, Node* target);
    void insertAtTail(const Person& data);
    Person removeNode(Node* target);
    void printList() const;
    bool isEmpty() const;
    void clearDataNodes();
};

void openInputFile(ifstream& inFile);
void storePeople(LList& peopleList, ifstream& inFile);
void calculateOwed(LList& peopleList);
void fillOwedVector(LList& peopleList, vector<Node*>& posNodeVect, vector<Node*>& negNodeVect, vector<Node*>& flatNodeVect);
void settleDebts(LList& peopleList, vector<Node*>& posNodeVect, vector<Node*>& negNodeVect, vector<Node*>& flatNodeVect);



int main () {

    LList contributions;
    ifstream inFile;
    vector<Node*> pos;
    vector<Node*> neg;
    vector<Node*> flat;



    cout << "Open the file containing everyone's contribution" << endl;
    openInputFile(inFile);
    cout << endl;

    cout << "Reading and storing contributions..." << endl << endl;
    storePeople(contributions, inFile);

    contributions.printList();

    cout << "Calculating what is owed..." << endl << endl;
    calculateOwed(contributions);

    contributions.printList();
    cout << endl;

    
    fillOwedVector(contributions, pos, neg, flat);

    cout << "Settling Owed Amounts...." << endl << endl;
    settleDebts(contributions, pos, neg, flat);



    return 0;
}

Node::Node(const Person& person, Node* prev, Node* next) : data(person), prev(prev), next(next) {}




// LList class

LList::LList(){
    size = 0;
    head = new Node();
    tail = new Node();
    head->next = tail;
    tail->prev = head;
}


LList::LList(const LList& rhs){
    size = 0;
    head = new Node();
    tail = new Node();
    head->next = tail;
    tail->prev = head;
    *this = rhs;
}

LList& LList::operator =(const LList& rhs){
    if (this == &rhs){
        return *this;
    }

    clearDataNodes();

    Node* begin;
    Node* end;
    begin = rhs.head->next;
    end = rhs.tail;

    while (begin != end){
        insertAtTail(begin->data);
        begin = begin->next;
    }

    return *this;

}

LList::~LList(){
    clearDataNodes();
    delete head;
    delete tail;
}

int LList::getSize() const {
    return size;
}

Node* LList::getHead() const {
    return head->next;
}

Node* LList::getTail() const {
    return tail;
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

Person LList::removeNode(Node* target){
    Person data = target->data;
    target->prev->next = target->next;
    target->next->prev = target->prev;
    size--;

    delete target;
    return data;
}


void LList::printList() const {
    Node* temp;
    Node* temp2;
    temp = getHead();
    temp2 = getTail();


    while (temp != temp2){
        cout << "Person Name: " << temp->data.getName() << endl;
        cout << "Amount Paid: " << temp->data.getPaid() << endl;
        cout << "Amount Owed: " << temp->data.getOwed() << endl << endl;

        // cout << "Person Name: " << temp->getData().getName() << endl;
        // cout << "Amount Paid: " << temp->getData().getPaid() << endl;
        // cout << "Amount Owed: " << temp->getData().getOwed() << endl << endl;
        temp = temp->next;
    }

    cout << endl;
}

bool LList::isEmpty() const {
    return size == 0;
}

void LList::clearDataNodes(){
    while (!isEmpty()){
        removeNode(head->next);
    }
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
    avg = round(avg * 100.0) / 100.0;


    tempOne = peopleList.getHead();
    double paid = 0;
    while (tempOne != tempTwo){
        paid = tempOne->getData().getPaid();
        tempOne->getData().setOwed(paid - avg);
        tempOne = tempOne->getNext();
    }
}

void fillOwedVector(LList& peopleList, vector<Node*>& posNodeVect, vector<Node*>& negNodeVect, vector<Node*>& flatNodeVect){
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
        else if (tempOne->getData().getOwed() == 0){
            flatNodeVect.push_back(tempOne);
        }

        tempOne = tempOne->getNext();
    }

}

void settleDebts(LList& peopleList, vector<Node*>& posNodeVect, vector<Node*>& negNodeVect, vector<Node*>& flatNodeVect){
    int posVectSize = posNodeVect.size();
    int negVectSize = negNodeVect.size();
    int flatVectSize = flatNodeVect.size();


    int i = 0;
    int j = 0;
    double currPos = 0;
    double currNeg = 0;
    int posNameSize = 0;
    int negNameSize = 0;
    int flatNameSize = 0;
    int posSizeOffset = 0;
    int negSizeOffset = 0;
    int flatSizeOffset = 0;
    string posName = "";
    string negName = "";
    string flatName = "";
    double posDecimal = 0;
    double negDecimal = 0;

    cout << "Summary of Payments: " << endl << endl;

    if (flatVectSize != 0){
        for (int i = 0; i < flatVectSize; i++){
            flatName = flatNodeVect[i]->getData().getName();
            flatNameSize = flatName.size();
            flatSizeOffset = flatNameSize - 1;

            for (int j = 0; j < flatSizeOffset; j++){
                cout << flatName[j];
            }

            cout << ", you don't need to do anything" << endl;
        }
    }
    


    while (i < posVectSize && j < negVectSize){
        currPos = posNodeVect[i]->getData().getOwed();
        posName = posNodeVect[i]->getData().getName();
        posNameSize = posName.size();
        posSizeOffset = posNameSize - 1;


        currNeg = negNodeVect[j]->getData().getOwed();
        negName = negNodeVect[j]->getData().getName();
        negNameSize = negName.size();
        negSizeOffset = negNameSize - 1;
        

        if (currPos >= abs(currNeg)){

            for (int i = 0; i < negSizeOffset; i++){
                cout << negName[i];
            }

            cout << ", you give ";

            for (int i = 0; i < posSizeOffset; i++){
                cout << posName[i];
            }

            negDecimal = round(abs(currNeg) * 100.0) / 100.0;

            
            cout << " $" << negDecimal;
            

            if (fmod(negDecimal * 100.0, 100.0) == 0.0){
                cout << ".00";
            }

            else if (fmod(negDecimal * 10.0, 10.0) == 0.0){
                cout << '0';
            }
            cout << endl;

            posNodeVect[i]->getData().setOwed(currPos + currNeg);
            negNodeVect[j]->getData().setOwed(0);
            j++;

        }
        else{
            for (int i = 0; i < negSizeOffset; i++){
                cout << negName[i];
            }

            cout << ", you give ";

            for (int i = 0; i < posSizeOffset; i++){
                cout << posName[i];
            }
            
            posDecimal = round(abs(currPos) * 100.0) / 100.0;
            
            cout << " $" << posDecimal;

            if (fmod(posDecimal * 100.0, 100.0)== 0.0){
                cout << ".00" ;
            }
            else if (fmod(posDecimal * 100.0, 10.0) == 0.0){
                cout << '0';
            }
            cout << endl;

            posNodeVect[i]->getData().setOwed(0);
            negNodeVect[j]->getData().setOwed(currPos + currNeg);
            i++;
        }

    }

    cout << endl;

    Node* tempOne;
    Node* tempTwo;
    tempOne = peopleList.getHead();
    tempTwo = peopleList.getTail();

    int count = 0;
    double sum = 0;
    double avg = 0;

    while (tempOne != tempTwo){
        sum += tempOne->getData().getPaid();
        count++;

        tempOne = tempOne->getNext();
    }

    avg = sum / count;
    avg = round(avg * 100.0) / 100.0;

    cout << "In the end, you should all have spent $" << avg;



    if (fmod(avg * 100.0, 100.0) == 0.0){
            cout << ".00" ;
    }
    else if (fmod(avg * 100.0, 10.0) == 0.0){
            cout << '0';
    }
    
    cout << endl;

    





}

