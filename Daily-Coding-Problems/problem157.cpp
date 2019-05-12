#include <iostream>
#include <vector>
#include <set>

typedef long long ll;

using namespace std;

int main(int argc , char *argv[]) {
    
    string s = "carrace";

    bool palyndrome=false;

    int nbEven=0, nbOdd=0;

    if(argc==2) s=argv[1];

    vector<int> count(26,0);

    for(int i = 0 ; i < s.length() ; i++) {
        count[s[i] - 'a']++;
    }

    for(int i = 0 ; i < 26 ; i++) {
        if(count[i] && count[i]%2) nbOdd++;
        else if(count[i]) nbEven++;
    }

    if(nbEven && nbOdd == 1)    cout << "TRUE" << endl;
    else cout << "FALSE" << endl;

    return 0;
}