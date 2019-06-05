#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

typedef long long ll;

using namespace std;

int main(int argc , char *argv[]) {
    int t;
    cin >> t;

    int n,k;

    for(int i = 0 ; i < t ; i++) {
        cin >> n >> k;
        vector<int> values(n);
        for(int j = 0 ; j < n ; j++) {
            cin >> values[j];
        }
        cout << (values[0]+values[n-1])/2 << endl;
    }
    return 0;
}