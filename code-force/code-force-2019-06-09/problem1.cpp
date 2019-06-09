#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

typedef long long ll;

using namespace std;

int main(int argc , char *argv[]) {
    int q;
    cin >> q;

    for(int i = 0 ; i < q ; i++) {
        ll n;
        cin >> n;

        int count = 0;

        while(n>1) {
            if(n%2 == 0) {
                n /= 2;
                ++count;
            }
            else if(n%3 == 0) {
                n /= 3;
                n *= 2;
                ++count;
            }
            else if(n%5 == 0) {
                n /= 5;
                n *= 4;
                ++count;
            }
            else {
                count = -1;
                break;
            }
        }

        cout << count << endl;
         

    }
    return 0;
}