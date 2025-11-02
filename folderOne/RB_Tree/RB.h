#ifndef __RB_H__
#define __RB_H__
#include <iostream>
#include <string>
using namespace std;

enum Color { RED, BLACK };

class Node {
public:
	int key;
    Node* parent;
	Node* rchild;	
    Node* lchild;
    int height;
    Color color;
};

class RB {
    public:
        RB();
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
        /*int lBF(Node*);
        int rBF(Node*);
        int BF(Node*);*/
        int searchForViolations(Node*);
        void fixViolations(Node*,Node*,Node*,Node*);
        void insert(int);
        void Delete(int);
        int minimum();
        int maximum();
        Node* inOrderSuccessor(int);
        Node* inOrderPredecessor(int);
        void destroyTree(Node*);
        void printTreeHelper(Node*, int );
        void printTree(); // visualizer function.
        ~RB();
    private: 
        Node* root;
};

#endif