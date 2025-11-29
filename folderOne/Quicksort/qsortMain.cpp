#include <iostream>
#include "qsort.cpp"

using namespace std;

int main() {
    int choice = 0;
    int size = 0;
    int* arr = nullptr;
    QSort sorter;

    while (choice != 4) {
        cout << "-----------------------" << endl;
        sorter.displayArray(arr, size);
        cout << "-----------------------" << endl;
        cout << "1 - Create / Enter Array" << endl;
        cout << "2 - Sort Array (Quicksort)" << endl;
        cout << "3 - Display Array" << endl;
        cout << "4 - Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;
        cout << "-----------------------" << endl;

        switch(choice) {
            case 1:
                sorter.buildArray(arr, size);
                break;

            case 2:
                if (arr == nullptr || size == 0) {
                    cout << "Array is empty. Create an array first." << endl;
                } else {
                    sorter.sort(arr, size);
                    cout << "Array has been sorted." << endl;
                }
                break;

            case 3:
                sorter.displayArray(arr, size);
                break;

            case 4:
                break;

            default:
                cout << "Enter a valid choice" << endl;
                break;
        }
    }

    delete[] arr;
    return 0;
}
