#ifndef __TDLLINKED_LIST_H__
#define __TDLLINKED_LIST_H__
#include <string>
#include <iostream>

using T = TTT;
using namespace std;


template <typename T>
class TDLList {
private:
    struct Node {
	    T data;
	    Node* next;	
        Node* prev;
        Node(const T& value) : data(value), next(nullptr), prev(nullptr) {}
    };
	Node* head;
    Node* tail;

public:
	TDLList() : head(nullptr), tail(nullptr) {}

    // Adds new element at the beginning
    void prepend(const T& value) {
        Node* x = new Node(value);
        if(head==nullptr){
            tail = x;
        }else{
            head->prev = x;
            x->next = head;
        }
        head = x;
    }

    // Adds new element at the end
    void append(const T& value) {
        Node* x = new Node(value);
        if(tail==nullptr){
            head = x;
        }else{
            tail->next = x;
            x->prev = tail;
        }
        tail = x;
    }

    // Deletes head element
    void delHead() {
        if (head == nullptr) {
            cout << "The Linked List is empty" << endl;
        }
        else {
            Node* temp = head;
            // This if statement prevents an error that would occur when there was a single item in the list
            if(head==tail){
                head = nullptr;
                tail = nullptr;
            }else{
            head = head->next;
            head->prev = nullptr;
            }
            delete temp;
        }
    }

    // Deletes tail element
    void delTail() {
        if (tail == nullptr) {
            cout << "The Linked List is empty" << endl;
        }
        else {
            Node* temp = tail;
            // This if statement prevents an error that would occur when there was a single item in the list
            if(head==tail){
                head = nullptr;
                tail = nullptr;
            }else{
            tail = tail->prev;
            tail->next = nullptr;
            }
            delete temp;
        }
    }

    // Displays head element
    void headPeek() const {
        if(head != nullptr){
        cout << head->data << endl;
        }
    }

    // Displays tail element
    void tailPeek() const {
        if(tail != nullptr){
        cout << tail->data << endl;
        }
    }

    // Traverses and prints the whole list

    void traverse() const {
        if (head == nullptr) {
            cout << "The Linked List is empty." << endl;
        }else {
            Node* curr = head;
            while (curr) {
                cout << "[" << curr->data << "]  ";
                curr = curr->next;
            }
            cout << endl;
        }	
    }		

    // Deconstructor
    ~TDLList() {
        Node* curr = head;
        while (curr != nullptr) { 
            Node* temp = curr;
            curr = curr->next;
            delete temp;
        }   
    }
};
#endif