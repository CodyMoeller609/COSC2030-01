#ifndef HEAP_H
#define HEAP_H
#include <iostream>
using namespace std;

class Heap {
private:
    int data[50];
    int size;

    void print(int arr[]);
    void percolateDown(int i); 
    void percolateUp(int i);
    void swap(int &a, int &b);

public:
    Heap();
    void printArray(int arr[], int n);
    void printHeap();
    void insert(int key);
    int getMax();
    int deleteMax();
    void buildHeap(int arr[], int n);
    void heapSort();
    void inputArray();
};

#endif
