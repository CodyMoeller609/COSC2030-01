#include <iostream>
#include "heap.h"
#include "heap.cpp"
using namespace std;

int main () {
    int cmd;
    int value;
    Heap h;
    int arr[50];

    while(cmd != 6){
        cout << "-----------------------" << endl;
        h.printHeap();
		cout << "-----------------------" << endl;
        //Present Choices
		cout << "1 - Insert an Array" << endl;
        cout << "2 - Insert a single value" << endl;
		cout << "3 - Return the maximum value" << endl;
        cout << "4 - Delete the maximum value" << endl;
		cout << "5 - Preform heapsort" << endl;
        cout << "6 - Exit the Program" << endl;
        cout << "Choice: ";
        // take input and act accordingly
        cin >> cmd;
        switch(cmd) {
            case 1: // Insert an Array
                h.inputArray();
                break;
            case 2: // Insert a single value
                cout << "What number would you like to insert?" << endl;
                cin >> value;
                h.insert(value);
                break;
            case 3: // getMax
                cout << "The maximum value is: " << h.getMax() << endl;
                break;
            case 4: // deleteMax
                cout << "The maximum value, which was " << h.deleteMax() << ", has been deleted." << endl;
                break;
            case 5: // heapsort
                h.heapSort();
                break;
            case 6: break; // exit the program
            default: cout << "Enter a valid choice" << endl;
				break;
        };
    }
    return 0;
}