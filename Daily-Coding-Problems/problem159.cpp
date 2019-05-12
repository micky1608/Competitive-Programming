#include <iostream>
#include <vector>
#include <set>

typedef long long ll;

using namespace std;

int main(int argc , char *argv[]) {
    
    string s = "acbbac";

    if(argc == 2) s = argv[1];

    set<char> seen;

    int i;
    for(i = 0 ; i < s.length() ; i++) {
        if(seen.count(s[i])) break;
        else seen.insert(s[i]);
    }
    
    if(i<s.length()) cout << s[i] << endl;
    else cout << "NULL" << endl;


    return 0;
}