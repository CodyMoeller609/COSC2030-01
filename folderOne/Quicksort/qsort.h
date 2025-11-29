#ifndef __QSORT_H__
#define __QSORT_H__

class QSort {
private:
    void quicksort(int*, int, int); // p and r
    int partition(int*, int, int);  // p and r
public:
    void sort(int*, int);
    void buildArray(int*&, int&);   // builds array from user input
    void displayArray(int*, int);   // prints array
};

#endif
