#include <iostream>
#include "DLList.h"

using namespace std;

// Constructor
DLList::DLList() {
	tail = nullptr;
	head = nullptr;
    
}

// Adds new element at the beginning
void DLList::prepend(Node* x) {
	if(head==nullptr){
		tail = x;
	}else{
		head->prev = x;
		x->next = head;
	}
	head = x;
}

// Adds new element at the end
void DLList::append(Node* x) {
	if(tail==nullptr){
		head = x;
	}else{
		tail->next = x;
		x->prev = tail;
	}
	tail = x;
}

// Deletes head element
void DLList::delHead() {
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
void DLList::delTail() {
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
void DLList::headPeek() {
	if(head != nullptr){
	cout << head->data << endl;
	}
}

// Displays tail element
void DLList::tailPeek() {
	if(tail != nullptr){
	cout << tail->data << endl;
	}
}

// Traverses and prints the whole list
void DLList::traverse() {
	if (head == nullptr) {
		cout << "The Linked List is empty." << endl;
	}else {
		Node* curr = head;
		while (curr != nullptr) {
			cout << "[" << curr->data << "]  ";
			curr = curr->next;
		}
		cout << endl;
	}	
}		

// Deconstructor
DLList::~DLList() {
    Node* curr = head;
    while (curr != nullptr) { 
		Node* temp = curr;
        curr = curr->next;
		delete temp;
    }   
}