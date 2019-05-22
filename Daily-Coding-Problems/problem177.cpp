#include <iostream>
#include <vector>
#include <set>
#include <algorithm>


#define LENGTH 20

typedef long long ll;

typedef struct node {
    int value;
    struct node *next;
} node;

using namespace std;

int main(int argc , char *argv[]) {

    int k=2;
    if(argc == 2) k = atoi(argv[1]);

    k %= (LENGTH);
    while(k < 0 ) k+= LENGTH;


    node *first = new node;
    first->value = 1;
    first->next = nullptr;

    node *it = first;
    for(int i = 0 ; i < LENGTH-1; i++) {
        node *n = new node;
        n->value = i + 2;
        n->next = nullptr;
        it->next = n;
        it = n;
    }

    cout << "Initial list : ";
    it = first;
    while(it != nullptr) {
        cout << it->value  << " ";
        it = it->next;
    }
    
    
    if(k) {
        it = first;
        node *newfirst;
        int count = 1;
        if(k > 1) {
            while(count < k-1) {
                count++;
                it=it->next;
            }
        }
    
        newfirst = it->next;
        it->next = nullptr;
        it = newfirst;
        
        while(it->next != nullptr) it=it->next;

        it->next = first;
        first = newfirst;
    }

    cout << endl << "Shifted list : ";
    it = first;
    while(it != nullptr) {
        cout << it->value  << " ";
        it = it->next;
    }


    it = first;
    node *it_next;
    while(it != nullptr) {
        it_next = it->next;
        delete it;
        it = it_next;

    } 

    cout << endl;


    return 0;
}