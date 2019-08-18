#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

typedef long long ll;

using namespace std;

int main(int argc , char *argv[]) {
    
    int n;
    cin >> n;

    set<int> values;
    vector<int> res(2*n,0);

    for(int i = 0 ; i < 2*n ; i++) {
        values.insert(i+1);
    }

    int ref = 0, ref2 = 0, cur = 0;
    bool possible = true;

    for(int i = 0 ; i < 2*n ; i++) {
        if(i == 0) {
            res[i] = 1;
            values.erase(1);
            ref += 1;
        }   
        else if(i == 1) {
            res[i] = 2*n;
            values.erase(2*n);
            ref += 2*n;
        }
        else if(i < n) {
            int index_next = (values.size()-1)/2;
            auto it = values.begin();
            advance(it , index_next);
            
            ref += *it;
            res[i] = *it;
            values.erase(it);
        }
        else {
            cur = 0;
            for(int j = 1 ; j < n ; j++) {
                cur += res[i-j];
            } 
            if(find(values.begin() , values.end() , ref - cur) != values.end()) {
                res[i] = ref-cur;
                values.erase(ref-cur);
            }
            else if(ref2) {
                if(find(values.begin() , values.end() , ref2 - cur) != values.end()) {
                    res[i] = ref2-cur;
                    values.erase(ref2-cur);
                }   
                else possible = false;
            }
            else {
                bool found = false;
                auto it = values.begin();
                while(it != values.end()) {
                    if(cur + *it == ref-1 || cur + *it == ref+1) {
                        res[i] = *it;
                        ref2 = cur+*it;
                        values.erase(it);
                        found = true;
                        break;
                    } 
                    it++;
                }
                if(!found) possible = false;
            }
        }
        if(!possible) break;
    }

    if(possible) {
        for(int i = 0 ; i < n-1 ; i++) {
            int check = 0;
            for(int j = 0 ; j < n ; j++) {
                check += res[(2*n-n+1+j)%(2*n)];
            }
            if(check != ref && check != ref2) {
                possible = false;
                break;
            }
        }
    }

    if(possible) {
        cout << "YES" << endl;
        for(int i=0 ; i < res.size() ; ++i) {
            cout << res[i] << " ";
        }   
        cout << endl;
    }
    else {
        cout << "NO" << endl;
    }
    


    




    
    
    return 0;
}