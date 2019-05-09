#include <iostream>
#include <vector>
#include <set>

typedef long long ll;

using namespace std;

/**
 * gcd(a,b) = a if b==0
 * else gcd(a,b) = gcd(b, a mod b)
 */
ll gcd(ll a , ll b) {
    if(!b) return a;
    if(!a) return b;

    return gcd(b, a%b);
}

int main(int argc , char *argv[]) {

    ll a = 10;
    ll b = 52;

    if(argc == 3) {
        a = (ll)atoi(argv[1]);
        b = (ll)atoi(argv[2]);
    }

    cout << "gcd(" << a << "," << b << ") = " << gcd((ll)a,(ll)b) << endl;
    
    return 0;
}