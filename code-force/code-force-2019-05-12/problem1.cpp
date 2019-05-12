#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

typedef long long ll;

using namespace std;

int main(int argc , char *argv[]) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    
    int count=0 , min=0;    

    for(int i = 0 ; i < n ; i++) {
        if(s[i] == '-') {
            if(min+count <= 0) min++;
            count--;
        }
        if(s[i] == '+') {
            count++;
        }
    }
        
    cout << max(0,min+count);
    
    return 0;
}