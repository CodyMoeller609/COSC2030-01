#include <iostream>

using namespace std;

int fact(int val, int sum){
    // Prevent stack overflow
    if (val == 0){
        return 0;
    }
    // Base Case
    if (val == 1){
        return sum;
    }
    // Multiply and reduce index
    else{
        sum *= val;
        return fact((val-1), sum);
    }
    return -1;
}

int main(int argc, char *argv[]){
    // Call recursive function
    int total = fact(atoi(argv[1]), 1);
    // Print total
    cout << total << endl;
    return 0;
}