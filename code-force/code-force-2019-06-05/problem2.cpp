#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>

typedef long long ll;

using namespace std;

int main(int argc , char *argv[]) {
    int l;
    cin >> l;

    vector<int> factors;
    ll f=1;

    string command;

    ll nbadd = 0;
    int n;

    for(int i = 0 ; i < l ; i++) {
        cin >> command;
        if(command == "add") nbadd += f;
        else if(command == "for") {
            cin >> n;
            f *= n;
            factors.push_back(n);
        }
        else if(command == "end") {
            f /= factors[factors.size()-1];
            factors.erase(factors.end()-1);
        }
    }

    if(nbadd < pow(2,32)) cout << nbadd;
    else cout << "OVERFLOW!!!";
    return 0;
}