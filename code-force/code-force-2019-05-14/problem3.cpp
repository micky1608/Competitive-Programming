#include <iostream>
#include <vector>
#include <set>

typedef long long ll;

using namespace std;

int main(int argc , char *argv[]) {
    int n;
    cin >> n;
    string s;
    cin >> s;

    int count = 0;

    vector<char> list;

    bool removeLast = false;

    int i=0,inc;
    while(i<n-1) {
        if((i-count)%2 == 0) {
            inc=0;
            while(i+1+inc < n && s[i] == s[i+1+inc]) inc++;
            count += inc;
            if(i+1+inc < n) {
                list.push_back(s[i]);
                list.push_back(s[i+1+inc]);
            }
            
            i+=inc+2;
        }
        else i++;
    }

    if((n-count) % 2 == 1) {
        count++;
        removeLast = true;
    }


    cout << count << endl;
    for(int i = 0 ; i < list.size() ; i++) {
        if(i<n-count || !removeLast) cout << list[i];
    }

    return 0;   
}