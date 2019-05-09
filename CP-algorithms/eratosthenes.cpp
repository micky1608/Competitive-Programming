#include <iostream>
#include <vector>
#include <set>

using namespace std;

/**
 * Find and print all the prime numbers smaller than n
 */

int main(int argc , char *argv[]) {

    // default boundary 
    int n = 100;

    if(argc == 2) n = atoi(argv[1]);

    vector<int> vector(n+1 , 1);
    vector[0] = vector[1] = 0;

    for(int i=2 ; i<=n ; i++) {
        // if i is prime and <= sqrt(n)
        if(vector[i] && (long long) i*i <= n) {
            for(int j=i*i ; j<= n ; j+= i)
                vector[j] = 0;
        }
    } 

   cout << "Prime numbers smaller than " << n << " : ";
   for(int i=0 ; i < vector.size() ; ++i) {
       if(vector[i]) cout << i << " ";
   }
   cout << endl;


      
    return 0;
}