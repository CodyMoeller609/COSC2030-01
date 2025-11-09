#include "heap.h"
#include <iostream>
using namespace std;

Heap::Heap() {
    size = 0;
}

void Heap::swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void Heap::printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void Heap::printHeap() {
    if (size == 0) {
        cout << "Heap is empty" << endl;
        return;
    }
    printArray(data, size);
}

void Heap::percolateDown(int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && data[left] > data[largest])
        largest = left;
    if (right < size && data[right] > data[largest])
        largest = right;

    if (largest != i) {
        swap(data[i], data[largest]);
        percolateDown(largest);
    }
}

void Heap::percolateUp(int i) {
    while (i > 0) {
        int parent = (i - 1) / 2;
        if (data[i] > data[parent]) {
            swap(data[i], data[parent]);
            i = parent;
        } else {
            break;
        }
    }
}

void Heap::insert(int key) {
    if (size == 50) {
        cout << "The heap is at its capacity. A new element cannot be inserted unless one is deleted first." << endl;
        return;
    }
    data[size] = key;
    percolateUp(size);
    size++;
}

int Heap::getMax() {
    if (size == 0) {
        cout << "The heap is empty!" << endl;
        return -1;
    }
    return data[0];
}

int Heap::deleteMax() {
    if (size == 0) {
        cout << "Error: Heap is empty" << endl;
        return -1;
    }
    int maxVal = data[0];
    data[0] = data[size - 1];
    size--;
    if (size > 0) {
        percolateDown(0);
    }
    return maxVal;
}

// Build heap from an array
void Heap::buildHeap(int arr[], int n) {
    if (n > 50) {
        cout << "Error: Array size exceeds heap capacity (50)" << endl;
        return;
    }
    for (int i = 0; i < n; i++) {
        data[i] = arr[i];
    }
    size = n;

    for (int i = size / 2 - 1; i >= 0; i--) {
        percolateDown(i);
    }
}

void Heap::heapSort() {
    if (size == 0) {
        cout << "Error: Heap is empty, cannot sort" << endl;
        return;
    }

    // Copy internal heap data into a temporary array
    int temp[50];
    int n = size;
    for (int i = 0; i < n; i++) {
        temp[i] = data[i];
    }

    // Build max heap copy internally so the original is not destroyed
    for (int i = n / 2 - 1; i >= 0; i--) {
        int j = i;
        bool done = false;
        while (!done) {
            int largest = j;
            int left = 2 * j + 1;
            int right = 2 * j + 2;

            if (left < n && temp[left] > temp[largest]) {
                largest = left;
            }
            if (right < n && temp[right] > temp[largest]) {
                largest = right;
            }

            if (largest != j) {
                swap(temp[j], temp[largest]);
                j = largest;
            } else {
                done = true;
            }
        }
    }

    // Extract elements one by one
    for (int end = n - 1; end > 0; end--) {
        swap(temp[0], temp[end]);

        int j = 0;
        bool done = false;
        while (!done) {
            int largest = j;
            int left = 2 * j + 1;
            int right = 2 * j + 2;

            if (left < end && temp[left] > temp[largest]) {
                largest = left;
            }
            if (right < end && temp[right] > temp[largest]) {
                largest = right;
            }

            if (largest != j) {
                swap(temp[j], temp[largest]);
                j = largest;
            } else {
                done = true;
            }
        }
    }

    cout << "Sorted heap data: ";
    printArray(temp, n);
}



// Interprets user input of an array as a heap
void Heap::inputArray() {
    int n;
    cout << "Enter number of elements (max " << 50 << "): ";
    cin >> n;

    if (n > 50) {
        cout << "Too many elements! Limiting to " << 50 << endl;
        n = 50;
    }

    cout << "Enter " << n << " numbers, one at a time: " << endl;
    int arr[50];
    for (int i = 0; i < n; i++) {
        cout << "Element " << (i+1) << ": ";
        cin >> arr[i];
    }

    buildHeap(arr, n);

    cout << "Heap built from input array: ";
    printHeap();
}