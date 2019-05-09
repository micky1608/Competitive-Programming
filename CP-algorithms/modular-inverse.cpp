#include <iostream>

typedef long long ll;

using namespace std;

void extended_euclidean(ll *u , ll *v , ll *r , ll a , ll b) {
    ll  U[3] = {1,0,0}, // U0 = 1 , U1 = 0 , U2 = 0
        V[3] = {0,1,0}, // V0 = 0 , V1 = 1 , V2 = 0
        R[3] = {a,b,0}; // R0 = a , R1 = b , R2 = 0

        // each loop computes U(i+1), V(i+1) and R(i+1)
        while(R[1]) {

            ll q = R[0]/R[1];   // Quotient R(i-1) / R(i)            

            R[2] = R[0]-R[1]*q;       // Remainder R(i-1) / R(i)
            U[2] = U[0]-q*U[1]; // Cofactor of a
            V[2] = V[0]-q*V[1]; // Cofactor of b

            // shift arrays 
            R[0] = R[1];
            R[1] = R[2];
            U[0] = U[1];
            U[1] = U[2];
            V[0] = V[1];
            V[1] = V[2]; 
        }

        *r = R[0];
        *u = U[0];
        *v = V[0];
}

ll modular_inverse(ll a , ll N) {
    ll u,v,r;
    extended_euclidean(&u,&v,&r,a,N);
    return u + (u<0)*N;
}

/**
 * Get the inverse of a mod N
 * If N is prime, all element a < N are inversible 
 * If N is not prime, all element a such that a<N and gcd(a,N)==1 are inversible
 */
int main(int argc , char *argv[]) {
    
    int a = 2;
    int N = 5;

    if(argc == 3) {
        a = atoi(argv[1]);
        N = atoi(argv[2]);
    }

    cout << "Inverse of " << a << " mod " << N << " = " << modular_inverse(a,N) << endl;
    
    return 0;
}