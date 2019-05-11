#include <iostream>
#include <vector>
#include <set>
 
typedef long long ll;
 
using namespace std;
 
int countSubstring(string& str, string sub)
{
    if (sub.length() == 0) return 0;
    int count = 0;
    for (size_t offset = str.find(sub); offset != std::string::npos;
     offset = str.find(sub, offset + sub.length()))
    {
        ++count;
    }
    return count;
}
 
int main(int argc , char *argv[]) {
    int N;
 
    cin >> N;
    string s;
    int nbA=0 , nbB = 0, nbAB=0 , nbDouble=0;
 
    for(int i = 0 ; i < N ; i++) {
        cin >> s;        
        
        if(s[s.length() -1] == 'A') nbA++;
        if(s[0] == 'B') nbB++;
 
        nbAB += countSubstring(s , "AB");

        if(s[s.length() -1] == 'A' && s[0] == 'B') nbDouble++;
 
    }
 
    //cout << nbA << " " << nbB << endl;
    
    cout << min(nbA,nbB) + nbAB;
 
    return 0;
}