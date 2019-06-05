#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

typedef long long ll;

using namespace std;

int main(int argc , char *argv[]) {
    ll t,n,k;
    ll count;

    cin >> t;
    
    for(int i = 0 ; i < t ; i++) {
        cin >> n >> k;
        count = 0;
        
        while(n>0) { 
            if(n%k == 0) {
                n /= k;
                count++;
            }
            else {
                ll r = n%k;
                n -= r;
                count += r;
            }
            
        }
        
        cout << count << endl;
    }
    return 0;
}