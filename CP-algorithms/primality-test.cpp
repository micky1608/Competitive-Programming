#include <iostream>
#include <cmath>
#include <time.h>
#include <NTL/ZZ.h>

/**
 * g++ -o primality-test primality-test.cpp -lntl
 */

typedef long long ll;

#define NB_ITER 20

using namespace std;
using namespace NTL;

bool fermat_is_prime(ll p , int iter) {
    if(p < 4) return p==2 || p==3;

    ZZ a;   // test base between 2 and p-2

    
    for(int i = 0 ; i < iter ; i++) {
        a = 2 + rand() % (p-3);  
        ZZ t = 
        if(t != 1)
            return false;
    }
    return true;
}

int main(int argc , char *argv[]) {
    
    ll p = 5;
    int nb_iter = 100;

    srand (time(NULL));

    if(argc == 3) {
        p = atoi(argv[1]);
        nb_iter = atoi(argv[2]);
    }
        
    
    cout << p << " " << (fermat_is_prime(p , nb_iter) ? "is prime" : "is NOT prime") << endl;
    
    return 0;
}