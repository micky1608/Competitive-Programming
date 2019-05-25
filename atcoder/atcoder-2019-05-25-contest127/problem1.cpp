#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

typedef long long ll;

using namespace std;

int main(int argc , char *argv[]) {
    int a,b;
    cin >> a >> b;

    cout << (a >= 13 ? b : (a >= 6 ? b/2 : 0));
    return 0;
}