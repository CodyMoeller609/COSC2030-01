#ifndef __DLLINKED_LIST_H__
#define __DLLINKED_LIST_H__

class Node {
public:
	int data;
	Node* next;	
    Node* last;
};

class DLLinkedList {
private:
	Node* head;
    Node* tail;

public:
	DLinkedList();
	void insert(Node*);
	void del();
	void traverse();
	~DLLinkedList();
};
#endif