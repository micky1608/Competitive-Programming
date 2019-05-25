#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

typedef long long ll;

using namespace std;

int main(int argc , char *argv[]) {
    int r, d, x2000;

    cin >> r >> d >> x2000;

    for(int i = 0 ; i < 10 ; i++) {
        x2000 *= r;
        x2000 -= d;
        cout << x2000 << endl;
    }
    return 0;
}