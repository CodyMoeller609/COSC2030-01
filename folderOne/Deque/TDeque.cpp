#include <iostream>
#include <string>
#include "TDeque.h"

using T = TTT;
using namespace std;

int main() {
	int choice = 0;
	T item;
	
	Deque<T>* L = new Deque<T>();

	while (choice != 10) {
        cout << "-----------------------" << endl;
		L->display();
		//Present Choices
		cout << "-----------------------" << endl;
		cout << "1 - Enqueue at Head" << endl;
        cout << "2 - Enqueue at Tail" << endl;
		cout << "3 - Dequeue at Head" << endl;
        cout << "4 - Dequeue at Tail" << endl;
		cout << "5 - Display" << endl;
		cout << "6 - Get Size" << endl;
		cout << "7 - Check if the deque is empty" << endl;
		cout << "8 - Check head value" << endl;
		cout << "9 - Check tail value" << endl;
		cout << "10 - Exit" << endl;

		// take user input
		cout << "Enter your choice: ";
		cin >> choice;
                cout << "-----------------------" << endl;

		// interpret user input as a funtion call
		switch(choice) {
            case 1:
                cout << "Enter the data item to enqueue at the head: ";
                cin >> item;
                L->enqueueAtHead(item);
                break;
            case 2:
                cout << "Enter the data item to be enqueue at the tail: ";
                cin >> item;
                L->enqueueAtTail(item);
                break;
			case 3: L->dequeueFromHead(); 
				break;
            case 4: L->dequeueFromTail(); 
				break;
			case 5: L->display(); 
				break;
			case 6:
			cout << "The current deque size is: ";
			cout << L->getSize() << endl;
				break;
			case 7:
			if(L->isEmpty()==true){
				cout << "The deque is empty." << endl;
			}else{
				cout << "The deque is not empty." << endl;
			}
				break;
			case 8:L->headPeek();
				break;
			case 9:L->tailPeek();
				break;
			case 10: break;
			default: cout << "Enter a valid choice" << endl;
				break;
		}
	}
	delete L;
	return 0;
}

