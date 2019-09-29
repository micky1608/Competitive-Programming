#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

typedef long long ll;

using namespace std;

int main(int argc , char *argv[]) {
    int l,r;
    cin >> l >> r;

    int res = l;    
    int copy;
    while(res <= r) {
        int copy = res;
        bool ok = true;
        vector<short> elements;
        while(copy) {
            elements.push_back(copy%10);
            copy /= 10;
        }

        sort(elements.begin() , elements.end());
        for(int i = 0 ; i < elements.size()-1 ; i++) {
            if(elements[i] == elements[i+1]) {
                ok = false;
                break;
            }
        }
        if(ok) break;
        res++;
    }

    cout << ((res <= r) ? res : -1) << endl;

    return 0;
}