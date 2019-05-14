#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

typedef long long ll;

using namespace std;

int main(int argc , char *argv[]) {
    int n;
    cin >> n;
    int k = 1;

    vector<int> contests_size(n);

    for(int i = 0 ; i < n ; i++) {
        cin >> contests_size[i];
    }

    sort(contests_size.begin() , contests_size.end());

    vector<int> done(n,0);
    bool find = false;
    int index=0;

    while(k < n) {
        index=0;
        find = false;
        do {
            if(!done[index] && contests_size[index] >= k) {
                find = true;
                done[index] = 1;
            }
            index++;
        } while(index < n && !find);

        if(!find) break;
        k++;
    }

    cout << k-1;



    
    return 0;
}