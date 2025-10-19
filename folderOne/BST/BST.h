#ifndef __BST_H__
#define __BST_H__
#include <iostream>
#include <string>
using namespace std;

class Node {
public:
	int key;
    Node* parent;
	Node* rchild;	
    Node* lchild;
};

class BST {
    public:
        BST();
        Node* searchRecursively(Node*, int);
        Node* search(int);
        void inorder(Node*);
        void preorder(Node*);
        void postorder(Node*);
        void traversal(string);
        Node* locateParent(Node*, int);
        void insert(int);
        void transplant(Node*, Node*);
        void Delete(int);
        int minimum();
        int maximum();
        Node* inOrderSuccessor(int);
        Node* inOrderPredecessor(int);
        void destroyTree(Node*);
        ~BST();
    private: 
        Node* root;
};

#endif