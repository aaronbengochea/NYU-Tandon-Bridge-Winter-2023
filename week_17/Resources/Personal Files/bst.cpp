#include <iostream>
#include <queue>
using namespace std;

template <class T>
class BSTNode{
private:
    T data;
    BSTNode<T>* parent;
    BSTNode<T>* left;
    BSTNode<T>* right;
public:
    BSTNode(T newData = T(), BSTNode<T>* newParent = nullptr, BSTNode<T>* newLeft = nullptr, BSTNode<T>* newRight = nullptr);
    friend class BST<T>;
    int getSize() const; 
}

template <class T>
class BST{
private:
    BSTNode<T>* root;
public:
    void printInOrder(BSTNode<T>* node);
    void printPreOrder(BSTNode<T>* node);
    void printPostOrder(BSTNode<T>* node);
    void printLevelOrder();
    void insert(T data);
    void remove(BSTNode<T>*& temp);
}


int main () {


    return 0;
}


BSTNode<T>::BSTNode(T newData = T(), BSTNode<T>* newParent = nullptr, BSTNode<T>* newLeft = nullptr, BSTNode<T>* newRight = nullptr) : parent(newParent), left(newLeft), right(newRight) {}

int BSTNode<T>::getSize() {
    int count = 1;
    if(left != nullptr){
        count += left->getSize();
    }
    if(right != nullptr){
        count += right->getSize();
    }
    
    return count;
}

void BST<T>::printInOrder(BSTNode<T>* node){
    if (node != nullptr){
        printInOrder(node->left);
        cout << node->data << ' ';
        printInOrder(node->right);
    }
}

void BST<T>::printPreOrder(BSTNode<T>* node){
    if (node != nullptr){
        cout << node->data << ' ';
        printpreOrder(node->left);
        printPreOrder(node->right);
    }
}

void BST<T>::printPostOrder(BSTNode<T>* node){
    if (node != nullptr){
        printPostOrder(node->left);
        printPostOrder(node->right);
        cout << node->data << ' ';
    }
}

void BST<T>::printLevelOrder(){
    queue<BSTNode<T>*> queue;
    queue.push(root);
    while (!queue.empty()){
        BSTNode<T>* temp = queue.front();
        queue.pop();
        cout << temp->data << ' ';
        if (temp->left != nullptr){
            queue.push(temp->left);
        }
        if (temp->right != nullptr){
            queue.push(temp->right);
        }
    }
}

void BST<T>::insert(T data){
    if (root == nullptr){
        root = new BSTNode<T>(data);
        return;
    }

    BSTNode<T>* temp = root;
    BSTNode<T>* prev = root;

    while (temp != nullptr){
        prev = temp;
        if (data < temp->data){
            temp = temp->left;
        }
        else{
            temp = temp->right;
        }
    }

    if (data < prev->data){
        prev->left = new BSTNode<T>(data, prev);
    }
    else {
        prev->right = new BSTNode<T>(data, prev);
    }
}

void BST<T>::remove(BSTNode<T>*& temp){
    if (temp->left == nullptr && temp->right == nullptr){
        if (parent == nullptr){
            root == nullptr;
        }
        else if (parent->left == temp){
            parent->left = nullptr;
        }
        else {
            parent->right = nullptr;
        }
        delete temp;
    }

    else if (temp->left == nullptr){}
    else if (temp->right == nullptr) {}
}