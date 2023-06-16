#include <iostream>
#include <queue>
#include <list>
using namespace std;

class BSTNode{
public:
    int data;
    BSTNode* parent;
    BSTNode* left;
    BSTNode* right;

    BSTNode(int newData = int(), BSTNode* newParent = nullptr, BSTNode* newLeft = nullptr, BSTNode* newRight = nullptr) : data(newData), parent(newParent), left(newLeft), right(newRight) {}
    friend class BST;
    int getSize() const; 
};


class BST{
public:
    BSTNode* root;

    BST();
    BSTNode* getRoot() {return root;}
    void printInOrder(BSTNode* node);
    void printPreOrder(BSTNode* node);
    void printPostOrder(BSTNode* node);
    void printLevelOrder();
    void insert(int data);
    void remove(BSTNode*& temp);
   
};

void printInOrderTwo(BSTNode* root, list<int>& head, bool& flag);
bool compare(BSTNode* root, list<int> head);


int main () {

    BST* tree = new BST();
    list<int> list;

    tree->insert(10);
    tree->insert(5);
    tree->insert(20);

    list.push_back(5);
    list.push_back(10);
    list.push_back(20);

    BSTNode* BSTRoot = tree->root;

    cout << "LL data: ";
    for (auto i : list){
        cout << i << ' ';
    }
    cout << endl;

    cout << "Tree data (inOrder): ";
    tree->printInOrder(BSTRoot);
    cout << endl;

    bool sameValues = compare(BSTRoot, list);

    cout << endl << endl;
    cout << "Do the LL and BST both contain the same values? ";
    if(sameValues){
        cout << "Yes!";
    } else {
        cout << "No.";
    }


    return 0;
}

BST::BST() : root(nullptr) {}


int BSTNode::getSize() const {
    int count = 1;
    if(left != nullptr){
        count += left->getSize();
    }
    if(right != nullptr){
        count += right->getSize();
    }
    
    return count;
}


void BST::printInOrder(BSTNode* node){
    if (node != nullptr){
        printInOrder(node->left);
        cout << node->data << ' ';
        printInOrder(node->right);
    }
}


void BST::printPreOrder(BSTNode* node){
    if (node != nullptr){
        cout << node->data << ' ';
        printPreOrder(node->left);
        printPreOrder(node->right);
    }
}


void BST::printPostOrder(BSTNode* node){
    if (node != nullptr){
        printPostOrder(node->left);
        printPostOrder(node->right);
        cout << node->data << ' ';
    }
}


void BST::printLevelOrder(){
    queue<BSTNode*> queue;
    queue.push(root);
    while (!queue.empty()){
        BSTNode* temp = queue.front();
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


void BST::insert(int data){
    if (root == nullptr){
        root = new BSTNode(data);
        return;
    }

    BSTNode* temp = root;
    BSTNode* prev = root;

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
        prev->left = new BSTNode(data, prev);
    }
    else {
        prev->right = new BSTNode(data, prev);
    }
}

void printInOrderTwo(BSTNode* root, list<int>& head, bool& flag){
    BSTNode* tempBST = root;    

    if (tempBST != nullptr){
        printInOrderTwo(tempBST->left, head, flag);
        if (tempBST->data == head.front()){
            head.pop_front();
        } else{
            flag = false;
        }
        printInOrderTwo(tempBST->right, head, flag);
    }
}

bool compare(BSTNode* root, list<int> head){
    bool flag = true;

    printInOrderTwo(root, head, flag);

    return flag;
}