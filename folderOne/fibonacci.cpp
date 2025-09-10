#include <iostream>

using namespace std;

int fib(int current, int lastNum, int currentIndex, int length){
    //Ends the function
    if(length == currentIndex){
        return 0;
    }
    currentIndex++;
    //Prints next number in sequence
    cout << lastNum << endl;
    //Stores "current" in a temperary var so it can be passed as "lastNum"
    int temp = current;
    //Sets the current number as the new "previous number"
    current += lastNum;
    // Calls itself recursively
    return fib(current, temp, currentIndex, length);
}

int main(int argc, char *argv[]){
    // Call the recursive function
    fib(1, 0, 1, atoi(argv[1])+1);
    return 0;
}
