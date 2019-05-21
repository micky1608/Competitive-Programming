#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

typedef long long ll;

using namespace std;

int main(int argc , char *argv[]) {
    string s1 = "abc", s2 = "bcd";

    if(argc == 3) {
        s1 = argv[1];
        s2 = argv[2];
    }

    vector<int> mapping(26,-1);

    bool possible = true;
    
    for(int i = 0 ; i < s2.length() ; i++) {
        if(mapping[s1[i] - 'a'] != -1 &&  mapping[s1[i] - 'a'] != s2[i] - 'a') {
            possible = false;
            break;
        }
        else {
            mapping[s1[i] - 'a'] = s2[i] - 'a';
        }
    }

    cout << "Mapping " << (possible ? "Possible" : "NOT possible") << endl; 
    if(possible) {
        for(int i = 0 ; i < 26 ; i++) {
            if(mapping[i] != -1) {
                cout << char('a' + i) << " -> " << char(mapping[i] + 'a') << endl;
            }
        }
    }
    
    return 0;
}