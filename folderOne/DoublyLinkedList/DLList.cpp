#include <iostream>
#include "DLLinkedList.h"

using namespace std;

LinkedList::LinkedList() {
	head = nullptr;
}

void LinkedList::insert(Node* x) {
	x->next = head;
	head = x;
}

void LinkedList::del() {
    if (head == nullptr) {
        cout << "The Linked List is empty" << endl;
    }
	else {
		Node* temp = head;
		head = head->next;
		delete temp;
	}
}

void LinkedList::traverse() {
	if (head == nullptr) {
		cout << "The Linked List is empty" << endl;
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

LinkedList::~LinkedList() {
    Node* curr = head;
    while (curr != nullptr) { 
	Node* temp = curr;
        curr = curr->next;
	delete temp;
    }   
}