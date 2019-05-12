#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

typedef long long ll;

using namespace std;

int main(int argc , char *argv[]) {
    int n;

    cin >> n;

    vector<int> vector(n);
    
    int k=1;
    bool okay=true;

    int min, imin;

    for(int i = 0 ; i < n ; i++) {
        cin >> vector[i];
        if(i==0) {
            min = vector[0];
            imin = 0;
        }
        else {
            if(vector[i] < min) {
                min = vector[i];
                imin = i;
            }
        }
    }

    do {
        if(vector[imin] >= k*(max(imin,(int)vector.size()-imin-1)) && vector[0] >= k*(vector.size()-1)) k++; 
        else okay=false;
    } while(okay);

   do {
       okay=true;
       for(int i=0 ; i<n ; i++) {
           for(int j=i+1 ; j<n ; j++) {
               if(k*(j-i) > std::min(vector[i],vector[j])) {
                   okay=false;
                   k--;
                   break;
               }
           }
           if(!okay) break;
       }
   } while(!okay);
    
    cout << k;
    return 0;
}