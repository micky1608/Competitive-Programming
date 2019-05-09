#include <iostream>
#include <vector>
#include <set>
#include <chrono>

using namespace std;

typedef long long ll;

/* 
    Compute a^n
*/
ll binary_exp(int a , int n) {
    if(n==0) return 1;

    ll res;

    if(n%2 == 0) {
        res = binary_exp(a,n/2);
        return res*res;
    }
    else {
        res =  binary_exp(a,(n-1)/2);
        return a*res*res;
    }
}



int main(int argc , char *argv[]) {

    if(argc != 3) {
        cerr << "Please enter a and n to compute a^n\nexemple : ./binary_exp 10 2 -> compute 10^2" << endl;
        exit;
    }

    int a = atoi(argv[1]);
    int n = atoi(argv[2]);
    
    ll res = binary_exp(a,n);

    cout << a << "^" << n << " = " << res << endl;

    return 0;
}

