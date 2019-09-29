#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <math.h>

typedef long long ll;

using namespace std;

#define MOD 1000000007

void primeFactors(int n , set<int>& primes)  
{  
    // Print the number of 2s that divide n  
    while (n % 2 == 0)  
    {  
        primes.insert(2); 
        n = n/2;  
    }  
  
    // n must be odd at this point. So we can skip  
    // one element (Note i = i +2)  
    for (int i = 3; i <= sqrt(n); i = i + 2)  
    {  
        // While i divides n, print i and divide n  
        while (n % i == 0)  
        {  
            primes.insert(i); 
            n = n/i;  
        }  
    }  
  
    // This condition is to handle the case when n  
    // is a prime number greater than 2  
    if (n > 2)  
        primes.insert(n);  
}  

inline ll g(ll x, ll p) {
    ll a = p;
    while(!(x%p)) {
        p*=a;
    }
    return p/a;
}

inline ll f(ll x, ll y , set<int>& primes) {
    ll res = 1;
    for(auto it = primes.begin() ; it != primes.end() ; ++it) {
        res *= g(y , *it);
    }

    return res;
}
  
int main(int argc , char *argv[]) {
    ll x , n;
    cin >> x >> n;

    set<int> primes;
    primeFactors(x , primes);

    ll res = 1;

    for(int i = 1 ; i <= n ; i++) {
        res *= f(x,i, primes);
        res %= MOD;
    }

    cout << res << endl;

    return 0;
}