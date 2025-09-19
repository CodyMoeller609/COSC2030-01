#include <iostream>
#include "DLList.h"

using namespace std;

DLList::DLList() {
	tail = nullptr;
	head = nullptr;
    
}

void DLList::prepend(Node* x) {
	if(head==nullptr){
		tail = x;
	}else{
	head->prev = x;
	x->next = head;
	}
	head = x;
}

void DLList::append(Node* x) {
	if(tail==nullptr){
		head = x;
	}else{
	tail->next = x;
	x->prev = tail;
	}
	tail = x;
}

void DLList::delHead() {
    if (head == nullptr) {
        cout << "The Linked List is empty" << endl;
    }
	else {
		Node* temp = head;
		head = head->next;
		head->prev = nullptr;
		delete temp;
	}
}

void DLList::delTail() {                                  // DEL TAIL FAILS only if there is only one term in list
    if (tail == nullptr) {
        cout << "The Linked List is empty" << endl;
    }
	else {
		Node* temp = tail;
		tail = tail->prev;
		tail->next = nullptr;
		delete temp;
	}
}

void DLList::headPeek() {
	cout << head->data << endl;
}

void DLList::tailPeek() {
	cout << tail->data << endl;
}

void DLList::traverse() {
	if (head == nullptr) {
		cout << "The Linked List is empty. Has no head ptr" << endl;
	}else if(tail == nullptr){
		cout << "The Linked List is empty. Has no tail ptr" << endl;
	}
	else {
		Node* curr = head;
		while (curr != nullptr) {
			cout << "[" << curr->data << "]  ";
			curr = curr->next;
		}
		cout << endl;
	}	
}		

DLList::~DLList() {
    Node* curr = head;
    while (curr != nullptr) { 
		Node* temp = curr;
        curr = curr->next;
		delete temp;
    }   
}