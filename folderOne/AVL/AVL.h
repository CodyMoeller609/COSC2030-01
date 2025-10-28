#ifndef __AVL_H__
#define __AVL_H__
#include <iostream>
#include <string>
using namespace std;

class Node {
public:
	int key;
    Node* parent;
	Node* rchild;	
    Node* lchild;
    int height;
};

class AVL {
    public:
        AVL();
        int getHeight(Node*);
        Node* searchRecursively(Node*, int);
        Node* search(int);
        void inorder(Node*);
        void preorder(Node*);
        void postorder(Node*);
        void traversal(string);
        Node* locateParent(Node*, int);
        void transplant(Node*, Node*);
        void rotateR(Node*);
        void rotateL(Node*);
        int lBF(Node*);
        int rBF(Node*);
        int BF(Node*);
        void insert(int);
        void Delete(int);
        int minimum();
        int maximum();
        Node* inOrderSuccessor(int);
        Node* inOrderPredecessor(int);
        void destroyTree(Node*);
        ~AVL();
    private: 
        Node* root;
};

#endif