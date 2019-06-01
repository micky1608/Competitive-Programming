#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

typedef long long ll;

using namespace std;

int main(int argc , char *argv[]) {
    int a,b,c;
    cin >> a >> b >> c;

    ll res = 0;
    
    if(a<b) {
        b--;
        res += 2*c + 1;
    }
    else {
        res += 2*c;
    }

    res += (a>b ? 2*b + 1 : 2*a);  

    cout << res << endl;
    
    return 0;
}