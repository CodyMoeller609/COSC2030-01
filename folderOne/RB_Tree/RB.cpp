#include <iostream>
#include "RB.h"

RB::RB(){
    root = nullptr;
}

int RB::getHeight(Node* Q){
    return Q->height;
}

// Recursive helper function called by search. Having another function for this allows me to pass a node arguement (needed for recursion),  
// but still follow the required formatting with the main call of the function.
Node* RB::searchRecursively(Node* currNode, int key){
    if(currNode == nullptr){
        cout << "There is no Tree!" << endl;
    }else{
        if(currNode->key == key){
            return currNode;
        }
        if(currNode->lchild != nullptr && (key < currNode->key)){
            return searchRecursively(currNode->lchild, key);
        }
        if(currNode->rchild != nullptr){
            return searchRecursively(currNode->rchild, key);
        }
    }
    return nullptr;
}

// Calls a recursive function to search for and return the node for a given key
Node* RB::search(int key){
    return searchRecursively(root, key);
}

// Recursive helper function called by traversal to traverse with inorder methodology
void RB::inorder(Node* currNode){
    if(currNode == nullptr){
        cout << "There is no Tree!" << endl;
    }else{
        if(currNode->lchild != nullptr){
            inorder(currNode->lchild);
        }
        cout << currNode->key << endl;
        if(currNode->rchild != nullptr){
            inorder(currNode->rchild);
        }
    }
}
// Recursive helper function called by traversal to traverse with preorder methodology
void RB::preorder(Node* currNode){
    if(currNode == nullptr){
        cout << "There is no Tree!" << endl;
    }else{
        cout << currNode->key << endl;
        if(currNode->lchild != nullptr){
            preorder(currNode->lchild);
        }
        if(currNode->rchild != nullptr){
            preorder(currNode->rchild);
        }
    }
}
// Recursive helper function called by traversal to traverse with postorder methodology
void RB::postorder(Node* currNode){
    if(currNode == nullptr){
        cout << "There is no Tree!" << endl;
    }else{
        if(currNode->lchild != nullptr){
            postorder(currNode->lchild);
        }
        if(currNode->rchild != nullptr){
            postorder(currNode->rchild);
        }
        cout << currNode->key << endl;
    }
}

void RB::traversal(string order){
    Node* currNode = root;
    if(order == "inorder"){
        inorder(root);
    }
    if(order == "preorder"){
        preorder(root);
    }
    if(order == "postorder"){
        postorder(root);
    }
}

void RB::rotateR(Node* Q){
    Node* mid = Q->lchild; // Store the left child of node Q as a variable
    Q->lchild = mid->rchild; // Set Q's new left child to mid's old right child
    mid->rchild = Q; // Set mid's right child as Q
    mid->parent = Q->parent; // Set mid's new parent as Q's old parent
    Q->parent = mid; // Set Q's new parent to be mid
    if(root == Q){ // if Q was the old root, set the root now to mid
        root = mid;
    }
}


void RB::rotateL(Node* Q){
    Node* mid = Q->rchild; // Store the right child of node Q as a variable
    Q->rchild = mid->lchild; // Set Q's new right child to mid's old left child
    mid->lchild = Q; // Set mid's left child as Q
    mid->parent = Q->parent; // Set mid's new parent as Q's old parent
    Q->parent = mid; // Set Q's new parent to be mid
    if(root == Q){ // if Q was the old root, set the root now to mid
        root = mid;
    }
}

Node* RB::locateParent(Node* currNode, int key){
    cout << "locateParent called" << endl;
    cout << "current node:" << currNode->key << endl;
    cout << "key: " << key << endl;
    if(currNode->key > key){ // Searches the left half of the tree
        cout << "Searching Left" << endl;
        cout << "current node > key || " << currNode->key << ">" << key << endl;
        if((currNode->lchild == nullptr)  /*||  (currNode->lchild->key == key)*/){ // if the current node's child matches the desired key or is childless, return it
            cout << "Parent found as there is no left child" << endl;
            return currNode;
        }
        cout << "calls recursively Left" << endl;
        return locateParent(currNode->lchild, key);

    } else /*if(currNode->key < key)*/{ // Searches the right half of the tree
        cout << "Searching Right" << endl;
        cout << "current node < key || " << currNode->key << "<" << key << endl;
        if((currNode->rchild == nullptr)  /*||  (currNode->lchild->key == key)*/){ // if the current node's child matches the desired key or is childless, return it
            cout << "Parent found as there is no right child" << endl;
            return currNode;
        }
        cout << "calls recursively Right" << endl;
        return locateParent(currNode->rchild, key);
    }
    cout << "big problem" << endl;
    return nullptr;
}
/*
int RB::BF(Node* Q){ // returns the balance factor of the node passed
    int lSum = -1;
    int rSum = -1;
    Node* currNode = Q->lchild;
    while(currNode != nullptr){
        lSum++;
        currNode = currNode->lchild;
    }
    currNode = Q->rchild;
    while(currNode != nullptr){
        rSum++;
        currNode = currNode->rchild;
    }
    return lSum+rSum;
}*/

int RB::searchForViolations(Node* victim){
    //Red node with red parent violation
    if(victim->parent->color == RED){
        return 1;
    }

    //Black height violation
    if(1==1){
        cout<<"black height violation"<<endl;
    }

    return -1;
}

void RB::fixViolations(Node* victim, Node* parent, Node* gparent, Node* uncle){
    if(parent->color != BLACK){
        if((parent->color == RED) && (uncle->color == RED)){ // Case two: parent and uncle are red
            cout<<"case 2"<<endl;
            parent->color = BLACK;
            uncle->color = BLACK;
            gparent->color = RED;
        }
        else if(1==1){ // Case three:
            cout<<"case 3"<<endl;
        }
        if(parent != nullptr){ // make recursive call if the current node is not the root
            if(parent == gparent->lchild){ fixViolations(gparent, gparent->parent, gparent->parent->parent, gparent->parent->parent->rchild);}
            else{ fixViolations(gparent, gparent->parent, gparent->parent->parent, gparent->parent->parent->lchild);}
        }
    /*
    while(searchForViolations(victim) == 1){ // fix if the parent is red
        Node* parent = victim->parent;
        Node* gparent = parent->parent;
        if(parent == gparent->lchild){
            Node* uncle = gparent->rchild;
        }else{
            Node* uncle = gparent->lchild;
        }

    }*/
    }
}

void RB::insert(int key){
    Node* x = new Node();
    Node* Parent = nullptr;
    x->color = RED;
    x->key = key;
    x->lchild = nullptr;
    x->rchild = nullptr;
    if(root==nullptr){
        root = x;
        root->parent = nullptr;
        cout << x->key << " is now the root" << endl;
    }else {
        Parent = locateParent(root, key);
        x->parent = Parent;
        if(x->key > Parent->key){
            Parent->rchild = x;
            cout << x->key << " is now the rchild of " << Parent->key << endl;
        }else{
            Parent->lchild = x;
            cout << x->key << " is now the lchild of " << Parent->key << endl;
        }
    }

    cout<<" HELLO     HELLO     : Parent==  "<< Parent /*<<"  Parent->parent==  "<< Parent->parent->key*/ << endl;
    // Now that the node has been inserted, fix the violations it caused.
    // Define surrounding nodes as variables
    if(Parent != nullptr){
        cout<<"Parent != nullptr"<<endl;
        Node* gparent = nullptr;
        if(Parent->parent != 0){
            gparent = Parent->parent;
        }
        Node* uncle;
        if(Parent == gparent->lchild){
            uncle = gparent->rchild;
        }else{
            uncle = gparent->lchild;
        }
    cout<<"Fix violations is running"<<endl;
    fixViolations(x, Parent, gparent, uncle);
    }

    root->color = BLACK; // Root should always be black
}

// Helper function to replace one subtree as a child of its parent with another
void RB::transplant(Node* one, Node* two) {
    if (one->parent == nullptr) { // if node one is the root
        root = two;
    } else if (one == one->parent->lchild) {
        one->parent->lchild = two;
    } else {
        one->parent->rchild = two;
    }
    if (two != nullptr) {
        two->parent = one->parent;
    }
}

void RB::Delete(int key) {
    Node* target = search(key);
    if (target == nullptr) {
        cout << "Key " << key << " not found." << endl;
        return;
    }

    // Case 1: no left child
    if (target->lchild == nullptr) {
        transplant(target, target->rchild);
        delete target;
        target = nullptr;
    }
    // Case 2: no right child
    else if (target->rchild == nullptr) {
        transplant(target, target->lchild);
        delete target;
        target = nullptr;
    }
    // Case 3: two children
    else {
        Node* successor = inOrderSuccessor(target->key);

        if (successor->parent != target) {
            // Replace successor with its right child
            transplant(successor, successor->rchild);
            successor->rchild = target->rchild;
            if (successor->rchild != nullptr) {
                successor->rchild->parent = successor;
            }
        }

        transplant(target, successor);
        successor->lchild = target->lchild;
        if (successor->lchild != nullptr) {
            successor->lchild->parent = successor;
        }

        delete target;
        target = nullptr;
    }
}

int RB::minimum(){
    if(root == nullptr){
        cout << "There is no Tree!" << endl;
    }else{
        Node* currNode = root;
        while(currNode->lchild != nullptr){
            currNode = currNode->lchild;
        }
        return currNode->key;
    }
    return 0;
}

int RB::maximum(){
    if(root == nullptr){
        cout << "There is no Tree!" << endl;
    }else{
        Node* currNode = root;
        while(currNode->rchild != nullptr){
            currNode = currNode->rchild;
        }
        return currNode->key;
    }
    return 0;
}

Node* RB::inOrderSuccessor(int key){
        Node* x = search(key);

    if(x != nullptr){
        if(x->rchild == nullptr){ // If the node has no right child, the successor is an ancestor
            if(x->parent == nullptr){
                return nullptr;
            }else{ 
                while(x->parent->key < x->key){
                    x = x->parent;
                    if(x->parent == nullptr){
                        return nullptr;
                    }
                }
                return x->parent;
            }
        }
        // if the node does have a right child, travserse left from that child until the leaf is reached. return the leaf
        Node* currNode = x->rchild;
        while(currNode->lchild != nullptr){
            currNode = currNode->lchild;
        }
        return currNode;
    }
    return nullptr;
}

Node* RB::inOrderPredecessor(int key){

    Node* x = search(key);

    if(x != nullptr){
        if(x->lchild == nullptr){ // If the node has no left child, the predecessor is an ancestor
            if(x->parent == nullptr){
                return nullptr;
            }else{ 
                while(x->parent->key > x->key){
                    x = x->parent;
                    if(x->parent == nullptr){
                        return nullptr;
                    }
                }
                return x->parent;
            }
        }
        // if the node does have a left child, travserse right from that child until the leaf is reached. return the leaf
        Node* currNode = x->lchild;
        while(currNode->rchild != nullptr){
            currNode = currNode->rchild;
        }
        return currNode;
    }
    return nullptr;
}

// Helper function for recursive deletion
void RB::destroyTree(Node* currNode) {
    if (currNode == nullptr) {
        return;
    }

    destroyTree(currNode->lchild);
    destroyTree(currNode->rchild);

    delete currNode;
}

  // Below is a visualizer that I had ChatGPT make for me. I did not use AI for any 
  // coding required in the project. This is simply to help with visualization and 
  // debugging.

#include <iomanip> // for setw()

// Helper to print the tree sideways with color
void RB::printTreeHelper(Node* currNode, int space) {
    const int INDENT = 6; // controls spacing between levels
    if (currNode == nullptr){
        return;
    }
    space += INDENT;
    printTreeHelper(currNode->rchild, space); // print r child
    cout << endl;

    for (int i = INDENT; i < space; i++){
        cout << " ";
    } 
    string colorStr = (currNode->color == RED) ? "R" : "B";
    cout << currNode->key << "(" << colorStr << ")"; //print curr node

    printTreeHelper(currNode->lchild, space); // print l child
}

// Public interface for printing the full tree
void RB::printTree() {
    if (root == nullptr) {
        cout << "Tree is empty!" << endl;
        return;
    }
    cout << "Current Tree Structure:" << endl;
    printTreeHelper(root, 0);
    cout << endl;
}
// End of the visualiser code that ChatGPT made me
 
RB::~RB() {
    destroyTree(root);
    root = nullptr;
}    