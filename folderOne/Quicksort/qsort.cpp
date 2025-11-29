#include <iostream>
#include "qsort.h"

using namespace std;

// public sort function
void QSort::sort(int* arr, int size) {
    quicksort(arr, 0, size - 1);
}

// recursive quicksort (uses p and r now)
void QSort::quicksort(int* arr, int p, int r) {
    if (p < r) {
        int q = partition(arr, p, r);
        quicksort(arr, p, q - 1);
        quicksort(arr, q + 1, r);
    }
}

// splits around pivot (uses p, r, q)
int QSort::partition(int* arr, int p, int r) {
    int q = arr[r];  // pivot
    int i = p - 1;

    for (int j = p; j <= r - 1; j++) {
        if (arr[j] < q) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp = arr[i + 1];
    arr[i + 1] = arr[r];
    arr[r] = temp;

    return i + 1;
}

// takes user input and builds array
void QSort::buildArray(int*& arr, int& size) {
    cout << "Enter the number of elements: ";
    cin >> size;

    if (arr != nullptr) {
        delete[] arr;
    }

    arr = new int[size];
    cout << "Enter " << size << " integers: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
}

// prints array to console
void QSort::displayArray(int* arr, int size) {
    if (size == 0 || arr == nullptr) {
        cout << "[] " << endl;
        return;
    }
    for (int i = 0; i < size; i++) {
        cout << "[" << arr[i] << "]  ";
    }
    cout << endl;
}
