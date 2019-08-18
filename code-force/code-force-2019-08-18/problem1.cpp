#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

typedef long long ll;

using namespace std;

int main(int argc , char *argv[]) {
    int n,m;

    cin >> n;
    vector<int> A(n);
    for(int i = 0 ; i < n ; i++) {
        cin >> A[i];
    }

    cin >> m;
    vector<int> B(m);
    for(int i = 0 ; i < m ; i++) {
        cin >> B[i];
    }

    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < m ; j++) {
            if(find(A.begin() , A.end() , A[i] + B[j]) == A.end() && find(B.begin() , B.end() , A[i] + B[j]) == B.end()) {
                cout << A[i] << " " << B[j] << endl;
                return 0;
            }
        }
    }




    
    return 0;
}