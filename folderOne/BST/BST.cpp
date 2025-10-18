#include <iostream>
#include "BST.h"

BST::BST(){
    root = nullptr;
}

Node* BST::search(int){
    return nullptr;
}

// Recursive function called by traversal to traverse with inorder methodology - FINISHED
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
// Recursive function called by traversal to traverse with preorder methodology - UNFINISHED
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
// Recursive function called by traversal to traverse with postorder methodology - UNFINISHED
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


void BST::Delete(int key){

}

int BST::minimum(){
    return 0;
}

int BST::maximum(){
    return 0;
}

Node* BST::inOrderSuccessor(int key){
    return nullptr;
}

Node* BST::inOrderPredecessor(int key){
    return nullptr;
}

BST::~BST(){
    
}

/*
        Node* locateNewLeaf(Node* node, T leaf){
            if (node->key > leaf) {
                if (node->lChild == nullptr) {
                    return node->lChild;
                } else {
                    locateNewLeaf(node->lChild, leaf);
                }
            } else if (node->key < leaf){
                if(node->rChild == nullptr){
                    return node->rChild;
                }else{
                    locateNewLeaf(node->rChild, leaf);
                }
            }
            Node* nullNode;
            return nullNode;
        }


        void leafInsert(T key){
            Node* val = new Node(key);
            if(root==nullptr){
                root=val;
            }else{

            }
        }
*/