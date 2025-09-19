#include <iostream>
#include "DLList.h"

using namespace std;

int main() {
	int choice;
	int item;
	
	DLList* L = new DLList();
	Node* x;
	
	while (choice != 6) {
        cout << "-----------------------" << endl;
		L->traverse();

		cout << "-----------------------" << endl;
		cout << "1 - Prepend" << endl;
        cout << "2 - Append" << endl;
		cout << "3 - Delete Head" << endl;
        cout << "4 - Delete Tail" << endl;
		cout << "5 - Traverse" << endl;
		cout << "6 - Exit" << endl;
		cout << "7 - Head Peek" << endl;
		cout << "8 - Tail Peek" << endl;

		cout << "Enter your choice: ";
		cin >> choice;
                cout << "-----------------------" << endl;

		switch(choice) {
			case 1: cout << "Enter the data item (integer) to be prepended: ";
				cin >> item;
				x = new Node;
				x->data = item;
				x->next = nullptr;
				x->prev = nullptr;
				L->prepend(x); 
				break;
            case 2: cout << "Enter the data item (integer) to be appended: "; //APPEND DOES NOT WORK ATM
				cin >> item;
				x = new Node;
				x->data = item;
				x->next = nullptr;
				x->prev = nullptr;
				L->append(x); 
				break;
			case 3: L->delHead(); 
				break;
            case 4: L->delTail(); 
				break;
			case 5: L->traverse(); 
				break;
			case 6: break;
			case 7: L->headPeek(); 
				break;
			case 8: L->tailPeek();
				break;
			default: cout << "Enter a valid choice" << endl;
				break;
		}
	}
	

	delete L;
	return 0;
}

