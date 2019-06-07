#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>

typedef long long ll;

typedef struct pos {
    int x;
    int y;
} pos;

using namespace std;

int main(int argc , char *argv[]) {
    int n;
    cin >> n;
    
    int m = ceil(sqrt(n));

    while(2*m-2 < n-1) m++;

    cout << m << endl; 

    for(int i = 1 ; i <= m ; i++) {
        cout << "1 " << i << endl;
    }
    
    int i=2*m-n+1;
    while(i<=m) {
        cout << m << " " << i << endl;
        i++;
    }




    return 0;
}