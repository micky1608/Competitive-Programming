#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

typedef long long ll;

using namespace std;

int main(int argc , char *argv[]) {
    int n;
    cin >> n;

    vector<int> val(n);
    for(int i = 0 ; i < n ; i++) {
        cin >> val[i];
    }

    ll cost = 0;
    int nb_neg = 0, nb_zero = 0;;

    for(int i = 0 ; i < n ; i++) {
        nb_zero += (!val[i]);
        nb_neg += (val[i] < 0);
        cost += abs(abs(val[i]) - 1);
    }
        
    cost += (nb_neg % 2 && !nb_zero) ? 2 : 0;

    cout << cost << endl;
    return 0;
}