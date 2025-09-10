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

int bi(int n, int k){
    int numerator = fact(n, 1);
    int denomCoeficient = fact(k, 1);
    int num3 = fact(k-n, 1);
    int denom = denomCoeficient*num3;
    int answer = numerator/denom;
    return answer;
}

int main(int argc, char *argv[]){
    int answer = bi(atoi(argv[1]), atoi(argv[2]));
    cout << answer << endl;
    return 0;
}