#include <iostream>
#include <iomanip> 
#include "RB.h"

RB::RB(){
    root = nullptr;
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

// Rotation functions

void RB::rotateR(Node* Q){
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

void RB::rotateL(Node* Q){
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

// This is a helper function for the insert function that recusively locates the parent of the new node
Node* RB::locateParent(Node* currNode, int key){
    cout << "locateParent called" << endl;
    cout << "current node:" << currNode->key << endl;
    cout << "key: " << key << endl;
    if(currNode->key > key){ 
        cout << "Searching Left" << endl;
        if(currNode->lchild == nullptr){
            cout << "Parent found as there is no left child" << endl;
            return currNode;
        }
        cout << "calls recursively Left" << endl;
        return locateParent(currNode->lchild, key);
    } else {
        cout << "Searching Right" << endl;
        if(currNode->rchild == nullptr){
            cout << "Parent found as there is no right child" << endl;
            return currNode;
        }
        cout << "calls recursively Right" << endl;
        return locateParent(currNode->rchild, key);
    }
    cout << "big problem" << endl;
    return nullptr;
}


// Red-Black tree specific recursive function for automatically fixing violations caused by insertion.
void RB::fixViolations(Node* x){
    while(x != root && x->parent->color == RED){
        Node* parent = x->parent;
        Node* gparent = parent->parent;

        if(gparent == nullptr) break; // prevent null grandparent crashes

        if(parent == gparent->lchild){ // parent is left child of grandparent
            Node* uncle = gparent->rchild;

            // Case 2A: uncle is red
            if(uncle != nullptr && uncle->color == RED){
                cout << "case 2A: recoloring" << endl;
                parent->color = BLACK;
                uncle->color = BLACK;
                gparent->color = RED;
                x = gparent;
            }
            else {
                // Case 3A: x is right child of left parent
                if(x == parent->rchild){
                    cout << "case 3A: left rotation needed" << endl;
                    x = parent;
                    rotateL(x);
                    parent = x->parent;
                    gparent = parent->parent;
                }
                // Case 3B: x is left child of left parent
                cout << "case 3B: right rotation" << endl;
                parent->color = BLACK;
                gparent->color = RED;
                rotateR(gparent);
            }
        }else{ // parent is right child of grandparent
            Node* uncle = gparent->lchild;

            // Case 2B: uncle is red
            if(uncle != nullptr && uncle->color == RED){
                cout << "case 2B: recoloring" << endl;
                parent->color = BLACK;
                uncle->color = BLACK;
                gparent->color = RED;
                x = gparent;
            }
            else {
                // Case 3C: x is left child of right parent
                if(x == parent->lchild){
                    cout << "case 3C: right rotation needed" << endl;
                    x = parent;
                    rotateR(x);
                    parent = x->parent;
                    gparent = parent->parent;
                }
                // Case 3D: x is right child of right parent
                cout << "case 3D: left rotation" << endl;
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
    Node* Parent = nullptr;
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

    // Fix violations created by the insertion. This function will recursively propagate up the tree to the root.
    fixViolations(x);
}

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


// the next two functions create a visualization of the tree. Primarily for debugging the rotations and such
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

void RB::printTree() {
    if (root == nullptr) {
        cout << "Tree is empty!" << endl;
        return;
    }
    cout << "Current Tree Structure:" << endl;
    printTreeHelper(root, 0);
    cout << endl;
}

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
