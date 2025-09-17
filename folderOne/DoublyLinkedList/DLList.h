#ifndef __DLLINKED_LIST_H__
#define __DLLINKED_LIST_H__

class Node {
public:
	int data;
	Node* next;	
    Node* last;
};

class DLList {
private:
	Node* head;
    Node* tail;

public:
	DLList();
	void prepend(Node*);
    void append(Node*);
	void delHead();
    void delTail();
	void traverse();
	~DLList();
};
#endif