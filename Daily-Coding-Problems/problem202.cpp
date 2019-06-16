#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>

typedef long long ll;

using namespace std;

int main(int argc , char *argv[]) {
    int a = 67876; 

    if(argc == 2) a = atoi(argv[1]);

    int nbDigit = ceil(log10(a));    

    vector<int> numbers;
    for(int i = 0 ; i < nbDigit ; i++) {
        numbers.push_back((int)(a / pow(10,i)) % 10);
    }

    bool palyndrome = true;
    int i=0 , j=numbers.size()-1;
    while(j>=i) {
        if(numbers[i] != numbers[j]) {
            palyndrome = false;
            break;
        }
        i++;
        j--;
    }

    cout << a << " " << ((palyndrome) ? "is" : "is NOT") << " a palyndrome" << endl;
    

    return 0;
}