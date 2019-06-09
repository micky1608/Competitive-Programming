#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

typedef long long ll;

using namespace std;

int main(int argc , char *argv[]) {
    int t;
    cin >> t;


    for(int i = 0 ; i < t ; i++) {
        int n;
        cin >> n;

        int a;

        int count = 0;

        vector<int> array;
        for(int j = 0 ; j < n ; j++) {
            int a;
            cin >> a;

            if(a%3 == 0) ++count;
            else array.push_back(a);
        }
        
        

        bool okay = false;
        while(array.size() > 1) {
        
            okay = false;
            for(int j = 0 ; j < array.size() ; j++) {
                int k=j+1;
                while(k<array.size()) {
                    if((array[j] + array[k])%3 == 0) {
                        ++count;
                        array.erase(array.begin() + j);
                        array.erase(array.begin() + k - 1);
                        okay = true;
                        break;
                    }
                    k++;
                }

                if(okay) break; 

                if(j==array.size()-1) {
                   count += array.size()/3;
                   array.clear();
                }
            }
        }

        cout << count << endl;
    }
    return 0;
}