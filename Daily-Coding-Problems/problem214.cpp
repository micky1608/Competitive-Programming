#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>

typedef long long ll;

using namespace std;

int main(int argc , char *argv[]) {
    int n = 156;

    if(argc==2) n = atoi(argv[1]);

    int count=0, max=0, mask=1;

    for(int i = 0 ; i < ceil(log2(n)) + (!(n & (n-1))); i++) {    
            
        if(n & mask) {
            count++;
        }
        else {
            max = (count > max) ? count : max;
            count = 0;
        }
        mask <<= 1;
    }

    max = (count > max) ? count : max;

    cout << "max : " <<  max << endl;
    
    return 0;
}