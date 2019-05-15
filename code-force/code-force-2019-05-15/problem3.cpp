#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

typedef long long ll;

using namespace std;

int main(int argc , char *argv[]) {
    int n,m;
    cin >> n >> m;

    vector<set<int>> groups(n);
    vector<set<int>> compo(m);

    // pour chaque groupe
    for(int i = 0 ; i < m ; i++) {
        int size, user;
        cin >> size;
        for(int k = 0 ; k < size ; k++) {
            cin >> user;
            groups[user-1].insert(i+1);
            compo[i].insert(user);
        }
    }


    //Pour chaque utilisateur
    for(int i = 0 ; i < n ; i++) {
        set<int> friends, others;
        friends.insert(i+1);
        
            for(auto f : friends) {
                for(auto g : groups[f-1]) {
                    for(auto user : compo[g -1]) {
                        friends.insert(user);
                        if(user < i+1) others.insert(user);
                    }
                }
            }

            for(auto f : others) {
                for(auto g : groups[f-1]) {
                    for(auto user : compo[g -1]) {
                        friends.insert(user);
                    }
                }
            }
        

        
       
        //for(auto it = friends.begin() ; it != friends.end() ; it++) cout << *it << " "; cout << endl;

        cout << friends.size() << " ";

    }

    

    return 0;
}