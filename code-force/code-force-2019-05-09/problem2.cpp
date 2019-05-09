#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

typedef long long ll;

using namespace std;

int main(int argc , char *argv[]) {
    int n;

    cin >> n;

    vector<int> ribbon(n);
    vector<int> count(10,0);
    vector<int> count_copy(10,0);
    
    for(int i = 0 ; i < n ; i++){
        cin >> ribbon[i]; 
        count[ribbon[i]-1]++;
        count_copy[ribbon[i]-1]++;
    } 

    int x=n , index;
    bool okay;

    while(x) {
        okay=true;
        for(int i=0 ; i<10 ; i++) count[i] = count_copy[i];
        sort(count.begin() ,count.end());

        index=0;
        while(!count[index]) index++;
        if(index != 9) {
            for(int l=index+1 ; l<9 ; l++) {
                if(count[l] != count[l+1]) okay=false;
            }
            
            if(okay) okay=(count[index] == 1);

            if(!okay) {
                if(count[9] - count[8] == 1) {
                    okay=true;
                    for(int l=index ; l<8 ; l++) {
                        if(count[l] != count[l+1]) okay =false;
                    }
                }
            }

            if(okay) {
                bool all_equals=true;
                for(int i=index ; i<9 ; i++) if(count[i] != count[i+1]) all_equals=false;
                if(all_equals && count[index]>1) okay=false;
            }
        else okay=false;
        }
            
        if(okay) break;
        
        count_copy[ribbon[x-1] - 1]--;
        --x;
        
    } 

    cout << x;
    return 0;
}