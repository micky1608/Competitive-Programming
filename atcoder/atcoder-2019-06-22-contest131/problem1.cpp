#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

typedef long long ll;

using namespace std;

int main(int argc , char *argv[]) {
    string s;
    cin >> s;

    for(int i = 0 ; i < s.length()-1 ; i++) {
        if(s[i] == s[i+1]) {
            cout << "Bad";
            return 0;
        }
    }

    cout << "Good";
    return 0;
}