#include <iostream>
#include "BST.h"

BST::BST(){
    root = nullptr;
}

// Recursive helper function called by search. Having another function for this allows me to pass a node arguement (needed for recursion),  
// but still follow the required formatting with the main call of the function.
Node* BST::searchRecursively(Node* currNode, int key){
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
Node* BST::search(int key){
    return searchRecursively(root, key);;
}

// Recursive helper function called by traversal to traverse with inorder methodology
void BST::inorder(Node* currNode){
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
void BST::preorder(Node* currNode){
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
void BST::postorder(Node* currNode){
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

void BST::traversal(string order){
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

Node* BST::locateParent(Node* currNode, int key){
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

void BST::insert(int key){
    Node* x = new Node();
    x->key = key;
    if(root==nullptr){
        root = x;
        cout << x->key << " is now the root" << endl;
    } else {
        Node* parent = locateParent(root, key);
        x->parent = parent;
        if(x->key > parent->key){
            parent->rchild = x;
            cout << x->key << " is now the rchild of " << parent->key << endl;
        }else{
            parent->lchild = x;
            cout << x->key << " is now the lchild of " << parent->key << endl;
        }
    }
}

// Helper function to replace one subtree as a child of its parent with another
void BST::transplant(Node* u, Node* v) {
    if (u->parent == nullptr) { // u is the root
        root = v;
    } else if (u == u->parent->lchild) {
        u->parent->lchild = v;
    } else {
        u->parent->rchild = v;
    }
    if (v != nullptr) {
        v->parent = u->parent;
    }
}

void BST::Delete(int key) {
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

int BST::minimum(){
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

int BST::maximum(){
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

Node* BST::inOrderSuccessor(int key){
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

Node* BST::inOrderPredecessor(int key){

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
void BST::destroyTree(Node* currNode) {
    if (currNode == nullptr) return;

    destroyTree(currNode->lchild);
    destroyTree(currNode->rchild);

    delete currNode;
}
 
BST::~BST() {
    destroyTree(root);
    root = nullptr;
}