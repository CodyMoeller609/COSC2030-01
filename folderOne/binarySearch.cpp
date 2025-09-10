#include <iostream>

using namespace std;

int binSrch(int arr[], int target, int lo, int hi){
    int mid = lo + (hi-lo)/2;

    // Base Case
    if(target == arr[mid]){
        return mid;
    }
    // if in the lower half of the array
    if(target<arr[mid]){
        return binSrch(arr, target, lo, (mid-1));
    }
    // if in the upper half of the array
    else{
        return binSrch(arr, target, (mid+1), hi);
    }
    return -1;
}

int main(int argc, char *argv[]) {
    int array1[] = {1, 4, 6, 7, 8, 9};

    // Obtain the bounds for the first seach
    int length = (sizeof(array1)/sizeof(array1[0]));
    int hi = length-1;
    int lo = 0;
    // Call the recursive function with bounds for the first search
    int index = binSrch(array1, atoi(argv[1]), lo, hi);
    // Print the index of the target value
    cout << "index:" << index << endl;
    return 0;
}