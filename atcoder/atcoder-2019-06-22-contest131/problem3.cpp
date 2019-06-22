#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>

typedef long long ll;

using namespace std;

int main(int argc , char *argv[]) {
    ll a,b,c,d;
    cin >> a >> b >> c >> d;

    ll nb = b-a+1;    
    
    ll res = nb - (nb/c) - (nb/d) + ceil(((long double)nb/(c*d)));

    if(a%c && b%c) res--;
    if(a%d && b%d) res--;

    cout <<  res  << endl;
    return 0;
}