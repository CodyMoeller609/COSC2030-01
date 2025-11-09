#include <iostream>
#include <iomanip> 
#include "RB.h"

RB::RB(){
    root = nullptr;
}

// Search functions

// Recursive helper function called by search. Having another function for this allows me to pass a node arguement (needed for recursion),  
// but not require the user to be concerned with node pointers.
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

// Calls a recursive function to search for and return the node for a given key. Written as two functions so that the 
// user must only pass a key and not a node.
Node* RB::search(int key){
    return searchRecursively(root, key);
}


// Traversal functions

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


// Rotation functions

void RB::rotateR(Node* Q){ // Q is the pivot node
    Node* mid = Q->lchild;
    Q->lchild = mid->rchild;
    if(mid->rchild != nullptr){
        mid->rchild->parent = Q;
    }
    mid->parent = Q->parent;
    if(Q->parent == nullptr){
        root = mid;
    }else if(Q == Q->parent->lchild){
        Q->parent->lchild = mid;
    }else{
        Q->parent->rchild = mid;
    }
    mid->rchild = Q;
    Q->parent = mid;
}

void RB::rotateL(Node* Q){ // Q is the pivot node
    Node* mid = Q->rchild;
    Q->rchild = mid->lchild;
    if(mid->lchild != nullptr){
        mid->lchild->parent = Q;
    }
    mid->parent = Q->parent;
    if(Q->parent == nullptr){
        root = mid;
    }else if(Q == Q->parent->lchild){
        Q->parent->lchild = mid;
    }else{
        Q->parent->rchild = mid;
    }
    mid->lchild = Q;
    Q->parent = mid;
}


// Insert functions

// This is a helper function for the insert function that recusively locates the parent of the new node
Node* RB::locateParent(Node* currNode, int key){
    if(currNode->key > key){ 
        if(currNode->lchild == nullptr){
            return currNode;
        }
        return locateParent(currNode->lchild, key);
    } else {
        if(currNode->rchild == nullptr){
            return currNode;
        }
        return locateParent(currNode->rchild, key);
    }
    return nullptr;
}

// Red-Black tree specific recursive function for automatically fixing violations caused by insertion.
void RB::fixViolations(Node* currNode){
    while(currNode != root && currNode->parent->color == RED){
        Node* parent = currNode->parent;
        Node* gparent = parent->parent;

        if(gparent == nullptr) break; // prevent null grandparent crashes

        if(parent == gparent->lchild){ // parent is left child of grandparent
            Node* uncle = gparent->rchild;

            // Case 2A: uncle is red
            if(uncle != nullptr && uncle->color == RED){
                parent->color = BLACK;
                uncle->color = BLACK;
                gparent->color = RED;
                currNode = gparent;
            }
            else {
                // Case 3A: currNode is right child of left parent
                if(currNode == parent->rchild){
                    currNode = parent;
                    rotateL(currNode);
                    parent = currNode->parent;
                    gparent = parent->parent;
                }
                // Case 3B: currNode is left child of left parent
                parent->color = BLACK;
                gparent->color = RED;
                rotateR(gparent);
            }
        }else{ // parent is right child of grandparent
            Node* uncle = gparent->lchild;

            // Case 2B: uncle is red
            if(uncle != nullptr && uncle->color == RED){
                parent->color = BLACK;
                uncle->color = BLACK;
                gparent->color = RED;
                currNode = gparent;
            }
            else {
                // Case 3C: currNode is left child of right parent
                if(currNode == parent->lchild){
                    currNode = parent;
                    rotateR(currNode);
                    parent = currNode->parent;
                    gparent = parent->parent;
                }
                // Case 3D: currNode is right child of right parent
                parent->color = BLACK;
                gparent->color = RED;
                rotateL(gparent);
            }
        }
    }
    root->color = BLACK; // root should always be black
}

void RB::insert(int key){
    Node* x = new Node();
    Node* parent = nullptr;
    x->color = RED;
    x->key = key;
    x->lchild = nullptr;
    x->rchild = nullptr;
    x->parent = nullptr;

    if(root==nullptr){
        root = x;
        root->color = BLACK;
        cout << x->key << " is now the root" << endl;
        return;
    }else {
        parent = locateParent(root, key);
        x->parent = parent;
        if(x->key > parent->key){
            parent->rchild = x;
            cout << x->key << " is now the rchild of " << parent->key << endl;
        }else{
            parent->lchild = x;
            cout << x->key << " is now the lchild of " << parent->key << endl;
        }
    }

    // Fix violations created by the insertion. This function will recursively propagate up the tree to the root.
    fixViolations(x);
}


// Deletion functions

// Places node 2 in node 1's old location
void RB::transplant(Node* one, Node* two) { 
    if (one->parent == nullptr) { 
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

// Delete leaves violation in the RB tree as we did not have to update that for this asignment
void RB::Delete(int key) {
    Node* target = search(key);
    if (target == nullptr) {
        cout << "Key " << key << " not found." << endl;
        return;
    }

    if (target->lchild == nullptr) {
        transplant(target, target->rchild);
        delete target;
        target = nullptr;
    }
    else if (target->rchild == nullptr) {
        transplant(target, target->lchild);
        delete target;
        target = nullptr;
    }
    else {
        Node* successor = inOrderSuccessor(target->key);
        if (successor->parent != target) {
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


// Misc fucntions

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
        if(x->rchild == nullptr){
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
        if(x->lchild == nullptr){
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
        Node* currNode = x->lchild;
        while(currNode->rchild != nullptr){
            currNode = currNode->rchild;
        }
        return currNode;
    }
    return nullptr;
}


// Visualizer functions. Primarily created for debugging purposes

void RB::printTreeHelper(Node* currNode, int space) {
    const int INDENT = 6;
    if (currNode == nullptr){
        return;
    }
    space += INDENT;
    printTreeHelper(currNode->rchild, space);
    cout << endl;

    for (int i = INDENT; i < space; i++){
        cout << " ";
    } 
    string colorStr = (currNode->color == RED) ? "R" : "B";
    cout << currNode->key << "(" << colorStr << ")";
    printTreeHelper(currNode->lchild, space);
}

// Prints a graphic of the tree in ASCII. Prints the tree rotated 90 degrees CCW
void RB::printTree() {
    if (root == nullptr) {
        cout << "Tree is empty!" << endl;
        return;
    }
    cout << "Current Tree Structure:" << endl;
    printTreeHelper(root, 0);
    cout << endl;
}


// Deconstructor functions

void RB::decimateTree(Node* currNode) {
    if (currNode == nullptr) {
        return;
    }
    decimateTree(currNode->lchild);
    decimateTree(currNode->rchild);
    delete currNode;
}

RB::~RB() {
    decimateTree(root);
    root = nullptr;
}
