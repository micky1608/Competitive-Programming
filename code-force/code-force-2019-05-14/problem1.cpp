#include <iostream>
#include <vector>
#include <set>

typedef long long ll;

using namespace std;

int main(int argc , char *argv[]) {
    int n,x,y;
    cin >> n >> x >> y;

    vector<char> b(n);
    vector<int> bits(n);
    
    int count=0;

    for(int i = 0 ; i < n ; i++) {
        cin >> b[i];
        bits[i] = b[i] - '0';
    }

    int index = n-x;
    while(index < n) {
        
        if(index == n-y-1) {
            if(bits[index] == 0) count++;
        }
        else {
            if(bits[index] == 1) count++;
        }
        index++;
    }

    cout << count;

    return 0;
}