#include <iostream>

using namespace std;

int AddUp(int A[ ], int n){
    int sum = 0;
    for(int i=0;i<(n-1);i++){
        sum+=A[i];
    }
    return sum;
}

int main(int argc, char* argv[]) {
    if(argc>11){
        cout << "No more than 10 integers, please." << endl;
    }else{
        int AA[argc-1];
        for(int i=0;i<argc-1;i++){
            AA[i]=atoi(argv[i+1]);
        }
        cout << AddUp(AA, argc) << endl;
        }
    return 0;
}

