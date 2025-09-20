#include <iostream>
#include <string>
#include "TDLList.h"

using T = TTT;
using namespace std;

int main() {
	int choice = 0;
	T item;
	
	TDLList<T>* L = new TDLList<T>();
	
	while (choice != 8) {
        cout << "-----------------------" << endl;
		L->traverse();
		//Present Choices
		cout << "-----------------------" << endl;
		cout << "1 - Prepend" << endl;
        cout << "2 - Append" << endl;
		cout << "3 - Delete Head" << endl;
        cout << "4 - Delete Tail" << endl;
		cout << "5 - Traverse" << endl;
		cout << "6 - Head Peek" << endl;
		cout << "7 - Tail Peek" << endl;
		cout << "8 - Exit" << endl;

		// take user input
		cout << "Enter your choice: ";
		cin >> choice;
                cout << "-----------------------" << endl;

		// interpret user input as a funtion call
		switch(choice) {
            case 1:
                cout << "Enter the data item to be prepended: ";
                cin >> item;
                L->prepend(item);
                break;
            case 2:
                cout << "Enter the data item to be appended: ";
                cin >> item;
                L->append(item);
                break;
			case 3: L->delHead(); 
				break;
            case 4: L->delTail(); 
				break;
			case 5: L->traverse(); 
				break;
			case 6: L->headPeek(); 
				break;
			case 7: L->tailPeek();
				break;
			case 8: break;
			default: cout << "Enter a valid choice" << endl;
				break;
		}
	}
	delete L;
	return 0;
}

