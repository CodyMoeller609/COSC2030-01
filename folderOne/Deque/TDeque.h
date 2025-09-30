#ifndef __DEQUE_H__
#define __DEQUE_H__
#include <string>
#include <iostream>

using T = TTT;
using namespace std;


template <typename T>
class Deque {
private:
    struct Node {
	    T data;
	    Node* next;	
        Node* prev;
        Node(const T& value) : data(value), next(nullptr), prev(nullptr) {}
    };
	Node* head;
    Node* tail;
    int size = 0;

public:
	Deque() : head(nullptr), tail(nullptr) {}

    // Adds new element at the beginning
    void enqueueAtHead(const T& value) {
        Node* x = new Node(value);
        if(head==nullptr){
            tail = x;
        }else{
            head->prev = x;
            x->next = head;
        }
        head = x;
        size += 1;
    }

    // Adds new element at the end
    void enqueueAtTail(const T& value) {
        Node* x = new Node(value);
        if(tail==nullptr){
            head = x;
        }else{
            tail->next = x;
            x->prev = tail;
        }
        tail = x;
        size += 1;
    }

    // Deletes head element
    void dequeueFromHead() {
        if (head == nullptr) {
            cout << "The deque is empty" << endl;
        }
        else {
            Node* temp = head;
            // This if statement prevents an error that would occur when there was a single item in the deque
            if(head==tail){
                head = nullptr;
                tail = nullptr;
            }else{
            head = head->next;
            head->prev = nullptr;
            }
            size -= 1;
            delete temp;
        }

    }

    // Deletes tail element
    void dequeueFromTail() {
        if (tail == nullptr) {
            cout << "The deque is empty" << endl;
        }
        else {
            Node* temp = tail;
            // This if statement prevents an error that would occur when there was a single item in the deque
            if(head==tail){
                head = nullptr;
                tail = nullptr;
            }else{
            tail = tail->prev;
            tail->next = nullptr;
            }
            size -= 1;
            delete temp;
        }
    }
    
    // returns the global variable size
    int getSize(){
        return size;
    }

    bool isEmpty(){
        if(size==0){return true;} // return true if size==0
        return false;             // return false otherwise
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

    // Prints the whole deque
    void display() const {
        if (head == nullptr) {
            cout << "The deque is empty." << endl;
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
    ~Deque() {
        Node* curr = head;
        while (curr != nullptr) { 
            Node* temp = curr;
            curr = curr->next;
            delete temp;
        }   
    }
};
#endif