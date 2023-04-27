#include <iostream>
#include <vector>
using namespace std;

template <class T>
class LList;


template <class T>
class LListNode{
    T data;
    LListNode<T>* next;
public:
    LListNode(T newData = T(), LListNode<T>* newNext = nullptr) : data(newData), next(newNext) {}
    LListNode(const LListNode& rhs) : data(rhs->data), next(rhs->next) { *this = rhs; } 
    LListNode<T>& operator=(const LListNode<T>& rhs);
    ~LListNode() {}
    void getData() const;
    friend class LList<T>;
};


template <class T>
class LList{
    LListNode<T>* head;
    LListNode<T>* recursiveCopy(LListNode<T>* rhs);
public:
    LList() : head(nullptr) {}
    LList(const LList& rhs) : head(nullptr) {*this = rhs;} // copy
    LList<T>& operator=(const LList<T>& rhs); // assign
    ~LList() {clear();} // delete
    void printLList(); 
    void insertAtHead(T newData); //done
    void insertAtEnd(T newData); // done
    void insertBefore(int targetIndex, T newData); // done
    void insertAfter(int targetIndex, T newData); // done
    void removeNode(int targetIndex); // done
    void mergeSortList(vector<T> mergedDataVect);
    vector<T> getDataVector();
    bool isEmpty() const {return head == nullptr; } // done
    LListNode<T>* getTargetPrevNode(int targetIndex); // done
    LListNode<T>* getTargetCurrNode(int targetIndex); // done 
    LListNode<T>* searchData(T target); // not done
    int size() const; // done
    // T removeFromHead();
    void clear();
    //void mergeSort(LList<T>& LList, int low, int high);
    //void merge(LList<T>& LList, int lowLeft, int highLeft, int highRight);

    // void insertAtPoint(LListNode<T>* ptr, T newData);
};

void merge(vector<int>& listDataVect, int highLeft, int lowLeft, int highRight);
void mergeSort(vector<int>& listDataVect, int low, int high);



int main () {

    LList<int> list1;


    for (int i = 0; i < 5; i++){
        list1.insertAtHead(i);
    }
    list1.insertAtEnd(10);
    cout << endl;

    cout << "Print List -> first time: ";
    list1.printLList();


    list1.insertBefore(2, 55);
    list1.insertAfter(2, 88);

    cout << "Print List -> second time: ";
    list1.printLList();

    cout << "Print List -> third time: ";
    list1.removeNode(3);
    list1.printLList();

    cout << "Assign fetched node to tgtNode, getData on tgtNode: ";
    LListNode<int>* tgtNode = list1.getTargetCurrNode(1);
    tgtNode->getData();
    cout << endl;


    cout << "Final List Size: ";
    cout << list1.size();

    cout << endl;

    vector<int> dataArr;
    dataArr = list1.getDataVector();

    cout << "vect before Msort: ";
    for (int ele: dataArr){
        cout << ele << ' ';
    }
    cout << endl;

    cout << "vect after Msort: ";
    mergeSort(dataArr, 0, dataArr.size()-1);

    for (int ele: dataArr){
        cout << ele << ' ';
    }
    cout << endl;

    //still linear because we have to create the vect in the first place then copy one by one
    cout << "Print List -> after Msort: ";
    list1.mergeSortList(dataArr);
    list1.printLList();


    return 0;
}

template <class T>
void LList<T>::mergeSortList(vector<T> mergedDataVect){
    LListNode<T>* temp;
    temp = head;
    int index = 0;

    while (temp != nullptr){
        temp->data = mergedDataVect[index];
        index++;
        temp = temp->next;
    }
}

void merge(vector<int>& listDataVect, int lowLeft, int highLeft, int highRight){
    int lowRight = highLeft + 1;
    int size = highRight - lowLeft + 1;
    int indexRight, indexLeft, indexResult;

    vector<int> tempArr;
    //int *mergedArr = new int[size];

    indexLeft = lowLeft;
    indexRight = lowRight;
    indexResult = 0;

    while ((indexLeft <= highLeft) && (indexRight <= highRight)){
        if (listDataVect[indexLeft] < listDataVect[indexRight]){
            tempArr.push_back(listDataVect[indexLeft]);
            //tempArr[indexResult] = listDataVect[indexLeft];
            indexResult++;
            indexLeft++;
            
        }
        else {
            tempArr.push_back(listDataVect[indexRight]);
            //tempArr[indexResult] = listDataVect[indexRight];
            indexResult++;
            indexRight++;
        }
    }

    while (indexLeft <= highLeft){
        tempArr.push_back(listDataVect[indexLeft]);
        //tempArr[indexResult] = listDataVect[indexLeft];
        indexLeft++;
        indexResult++;
    }

    while (indexRight <= highRight){
        tempArr.push_back(listDataVect[indexRight]);
        //tempArr[indexResult] = listDataVect[indexRight];
        indexRight++;
        indexResult++;
    }

    for (int i = 0, indexArr = lowLeft; i < size; i++, indexArr++){
        listDataVect[indexArr] = tempArr[i];
    }


}

void mergeSort(vector<int>& listDataVect, int low, int high){
    int mid;

    if (low == high){
        return;
    }
    else{
        mid = (low + high) / 2;
        mergeSort(listDataVect, low, mid);
        mergeSort(listDataVect, mid + 1, high);
        merge(listDataVect, low, mid, high);
    }
}

template <class T>
vector<T> LList<T>::getDataVector(){
    vector<T> tempVect;
    LListNode<T>* frontPtr;
    LListNode<T>* tempPtr;

    frontPtr = head;
    tempPtr = head;

    while (tempPtr != nullptr){
        tempVect.push_back(tempPtr->data);
        tempPtr = tempPtr->next;
    }
    return tempVect;
}




// LL Class

// template <class T>
// void LList<T>::merge(LList<T>& LList, int lowLeft, int highLeft, int highRight){
//     int lowRight = highLeft + 1;
//     int size = highRight - lowLeft + 1;
//     int indexRight, indexLeft, indexResult;

//     indexLeft = lowLeft;
//     indexRight = lowRight;
//     indexResult = 0;

//     // can't get it to initialize properly - giving errors
//     LList<T> LList2; // << -- Tania believes this may not work
//     //temp Linked List to take in newly sorted nodes

//     LListNode<T>* temp;
//     temp = head; // effectively indexLeft

//     LListNode<T>* fwdTemp;
//     fwdTemp = getTargetCurrNode(indexRight);

//     while ((indexLeft <= highLeft) && (indexRight <= highRight)){
//         if (temp->data < fwdTemp->data){
//             LList2.insertAtEnd(temp->data);
//             indexResult++;
//             indexLeft++;
//             temp = temp->next;
//         }
//         else {
//             LList2.insertAtEnd(fwdTemp->data);
//             indexResult++;
//             indexRight++;
//             fwdTemp = fwdTemp->next;
//         }
        
//     }

//     while (indexLeft <= highLeft){
//         LList2.insertAtEnd(temp->data);
//         indexResult++;
//         indexLeft++;
//         temp = temp->next;
//     }

//     while (indexRight <= highRight){
//         LList2.insertAtEnd(fwdTemp->data)
//         indexResult++;
//         indexRight++;
//         fwdTemp = fwdTemp->next;
//     }

//     LList = LList2;
// }
    

// template <class T>
// void LList<T>::mergeSort(LList<T>& LList, int low, int high){
//     int mid;
//     cout << "speak";
//     if (low == high){
//         return;
//     }
//     else {
//         mid = (low + high) / 2;
//         mergeSort(LList, low, mid);
//         mergeSort(LList, mid + 1, high);
//         merge(LList, low, mid, high);
//     }
// }


template <class T>
LListNode<T>& LListNode<T>::operator=(const LListNode<T>& rhs){
    this->data = rhs->data;
    this->next = rhs->next;
    return *this;
}

template <class T>
LList<T>& LList<T>::operator=(const LList<T>& rhs) {
    this->head = rhs->head;
    return *this;

}

template <class T>
void LList<T>::clear() {
    LListNode<T>* temp;
    LListNode<T>* beforeTemp;
    temp = head;
    beforeTemp = head;

    if (temp == nullptr){
        return;
    }
    else{
        while (temp != nullptr){        
            temp = temp->next;
            delete beforeTemp;
            beforeTemp = temp;
            
        }
        head = nullptr;
    }
}

template <class T>
void LListNode<T>::getData() const {
    LListNode<T>* temp;
    temp->data = this->data;
    cout << temp->data;
}

template <class T>
void LList<T>::printLList(){
    LListNode<T>* temp;
    temp = head;

    while (temp != nullptr){
        cout << temp->data << ' ';
        temp = temp->next;
    }
    cout << endl;
}

template <class T>
LListNode<T>* LList<T>::recursiveCopy(LListNode<T>* rhs){
    if (rhs == nullptr){
        return nullptr;
    }
    
    return new LListNode<T>(rhs->data,recursiveCopy(rhs->next));
}


template <class T>
void LList<T>::insertAtHead(T newData) {
    LListNode<T>* temp = new LListNode<T>(newData);

    if (isEmpty()){
        head = temp;
        return;
    }

    temp->next = head;
    head = temp;

    cout << "Item Inserted at head!" << endl;
}

template <class T>
void LList<T>::insertAtEnd(T newData){
    if (isEmpty()){
        insertAtHead(newData);
        return;
    }

    // allocates dynamic memory for the temp object 
    LListNode<T>* temp = new LListNode<T>(newData);  // gets created with a nullptr in its next value since we only passed newData
    LListNode<T>* end = head; // creates a movable ptr that begins by pointing to head

    while (end->next != nullptr){ // iterates thru the LL until it find the final node
        end = end->next;
    }
    end->next = temp; // sets the final nodes next to the 

    cout << "Item Inserted at tail!" << endl;
}

template <class T> 
void LList<T>::insertBefore(int targetIndex, T newData){
    LListNode<T>* temp = new LListNode<T>(newData);
    LListNode<T>* prevNode;
    prevNode = getTargetPrevNode(targetIndex);

    temp->next = prevNode->next;
    prevNode->next = temp;
}

template <class T>
void LList<T>::insertAfter(int targetIndex, T newData){
    LListNode<T>* temp = new LListNode<T>(newData);
    LListNode<T>* currNode;
    currNode = getTargetCurrNode(targetIndex);

    temp->next = currNode->next;
    currNode->next = temp;
}

template <class T>
void LList<T>::removeNode(int targetIndex){
    LListNode<T>* temp;
    LListNode<T>* temp2;
    temp = getTargetPrevNode(targetIndex); // finds the node previous to the target node
    temp2 = getTargetCurrNode(targetIndex); // finds the target node to be discarded

    temp->next = temp2->next; // previous ->next points to the delete target's next; effectively cutting its link; 
    delete temp2; // deallocating heap memory
}


template <class T>
LListNode<T>* LList<T>::getTargetPrevNode(int targetIndex){
    LListNode<T>* temp;
    temp = head;
    int i = 0;

    if (targetIndex > 0){
        targetIndex = targetIndex - 1;
    }

    if (temp == nullptr){
        return nullptr;
    }
    else{
        while (i < targetIndex && temp->next != nullptr){
            temp = temp->next;
            i++;
        }
        if (i == targetIndex){
                return temp;
            }

        return nullptr;
    }   
}

template <class T>
LListNode<T>* LList<T>::getTargetCurrNode(int targetIndex){
    LListNode<T>* temp;
    temp = head;
    int i = 0;

    if (temp == nullptr){
        return nullptr;
    }
    else{
        while (i < targetIndex && temp->next != nullptr){
            temp = temp->next;
            i++;
        }
        if (i == targetIndex){
                return temp;
            }

        return nullptr;
    }   

}


template <class T>
LListNode<T>* LList<T>::searchData(T target){
    LListNode<T>* temp;
    temp = head;

    if (temp == nullptr){
        return nullptr;
    }
    else{
        if (temp->data == target){
            cout << temp->data << endl;
            return temp;
        }
        else {
            while (temp->data != target && temp != nullptr){
                temp = temp->next;
                if (temp->data == target){
                    cout << temp->data << endl;
                    return temp;
                }
            }
            return nullptr;
        }
    }
}




template <class T>
int LList<T>::size() const {
    int count = 0;
    LListNode<T>* temp = head;
    while (temp != nullptr){
        count++;
        temp = temp->next;
    }

    return count;
}
