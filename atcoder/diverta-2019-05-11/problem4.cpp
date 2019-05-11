#include <iostream>
#include <vector>
#include <set>

typedef long long ll;

using namespace std;

int main(int argc , char *argv[]) {
    int N;
    cin >> N;

    int sum=0;

    for(int m=1 ; m<=N ; m++) {
        if(N/m == N%m) sum+=m;
    }

    cout << sum;
    return 0;
}