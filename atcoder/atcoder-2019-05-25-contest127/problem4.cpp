#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

typedef long long ll;

using namespace std;

int main(int argc , char *argv[]) {
    int n, m, b , c;
    cin >> n >> m;
    vector<int> cards(n);

    sort(cards.begin() , cards.end());

    ll sum = 0;

    for(int i = 0 ; i < n ; i++) {
        cin >> cards[i];
        sum += cards[i];
    }

    for(int i = 0 ; i < m ; i++) {
        cin >> b >> c;
        int index = 0;
        while(index < b) {
            if(cards[index] < c) {
                sum += (c-cards[index]);
                cards[index] = c;
            }
            else 
                break;

            index++;
        }
        sort(cards.begin() , cards.end());
    }

    cout << sum;
    
    return 0;
}