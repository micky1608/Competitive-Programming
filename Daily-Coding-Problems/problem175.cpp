#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <random>
#include <string.h>

#define NBSTATE 3

typedef long long ll;

using namespace std;

double randDouble(double min , double max) {
    return double(rand()) / (double(RAND_MAX) + 1.0);
}


int main(int argc , char *argv[]) {
    srand(static_cast<unsigned int>(clock()));

    double markov_law[NBSTATE][NBSTATE] = {
        {0.9, 0.075, 0.025},
        {0.15, 0.8 , 0.05},
        {0.25, 0.25 , 0.5}
    };

    int start = 0;
    int steps = 5;

    if(argc == 3) {
        start = atoi(argv[1]);
        steps = atoi(argv[2]);
    }

    if(start < 0 || start >= NBSTATE) {
        cerr << "Invalid start";
        exit(-1);
    }

    if(steps < 0) {
        cerr << "Invalid steps";
        exit(-1);
    }

    int current = start, next;

    int count[NBSTATE];
    memset(count , 0 , NBSTATE*sizeof(int));

    double cumsum[NBSTATE];

    for(int i = 0 ; i < steps ; i++) {
        
        count[current]++;
        
        cumsum[0] = markov_law[current][0];
    
        memset(cumsum + sizeof(double) , 0 , (NBSTATE-1)*sizeof(double));
        for(int k = 1 ; k < NBSTATE ; k++) {
            cumsum[k] = cumsum[k-1] + markov_law[current][k];
        }   


        double random = randDouble(0. , 1.0);

        next = 0;
        while(next < NBSTATE && random > cumsum[next]) ++next;
        
        current = next;
    }

    for(int i = 0 ; i < NBSTATE ; i++) {
        cout << char((i + 'a')) << " : " << count[i] << endl;
    }
    
    return 0;
}