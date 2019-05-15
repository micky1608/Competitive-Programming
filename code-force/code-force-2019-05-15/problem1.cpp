#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

typedef long long ll;

using namespace std;

int main(int argc , char *argv[]) {
    int t;
    cin >> t;

    for(int i = 0 ; i < t ; i++) {
        int n;
        cin >> n;
        vector<char> vector(n);
        
        for(int l = 0 ; l < n ; l++) {
            cin >> vector[l];
        }

        bool okay = false;
        int k=n-11;

        for(int j=0 ; j<=k ; j++) {
            if(vector[j] == '8') {
                okay = true;
                break;
            }
        }

        if(okay) cout << "YES" << endl;
        else cout << "NO" << endl;
        


    }
    return 0;
}