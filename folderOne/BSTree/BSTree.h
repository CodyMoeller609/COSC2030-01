#ifndef __BSTree_H__
#define __BSTree_H__
#include <iostream>
using T = TT;
using namespace std;

template <typename T>
class BSTree {
    private:
        struct Node{
            T key = nullptr;
            Node* lChild = nullptr;
            Node* rChild = nullptr;
        };
    public:
        Node* root;
        BSTree(){
            root = nullptr;
        }
        
        Node* search(Node* node, T key){
            if (node->key == key){
                return node;
            }else{
                search(node->lChild, key);
                search(node->rChild, key);
            }
            return -1;
        }

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

        //Deconstructor to be completed when I develop a traverse function
        //~BSTree(){
        //}
};

#endif