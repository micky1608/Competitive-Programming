#include <iostream>
#include <vector>
#include <set>

typedef long long ll;

using namespace std;

int main(int argc , char *argv[]) {
    int n,m,out=0, total;

    cin >> n >> m;
    total = n;

    vector<int> present(n,1);
    int acc;
    
    int index = 0;
    for(int i = 0 ; i < m ; i++) {
        acc=0;
        while(acc < 3*total && (!present[index] || !present[(index + 1) % total])) {
            index = (index + 1) % total;
            acc++;
        }     

        if(acc < 3*total) {
            present[(index + 1) % total] = 0;
            n--;
        }
        else {
             // on n'a pas deux chat cote a cote 
            if(n) {
                while(!present[index]) index = (index + 1) % total;
                present[index] = 0;
                n--;
            }
            else {
                cout << 0;
                return 0;
            }
        }
       
    }

    index=0;
    while(index < present.size()) {
        if(present[index]) {
            out++;
            while(index<present.size() && present[++index]);
        }
        index++;
    }

    if(present[0] && present[present.size()-1] && n != total) --out;
    cout << out << endl;
    

    return 0;
}