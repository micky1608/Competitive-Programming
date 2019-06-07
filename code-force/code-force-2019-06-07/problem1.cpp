#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

typedef long long ll;

using namespace std;

int main(int argc , char *argv[]) {
    int x,y,z;
    cin >> x >> y >> z;

    int s = x-y;

    if(abs(s) > z) {
        if(s>0) cout << "+";
        else if (s<0) cout << "-";
        else cout << "0";
    }

    else {
        if(z) cout << "?";
        else cout << "0";
    }
    return 0;
}