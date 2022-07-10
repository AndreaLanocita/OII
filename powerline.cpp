/*
 * This template is valid both in C and in C++,
 * so you can expand it with code from both languages.
 * NOTE: it is recommended to use this even if you don't
 * understand the following code.
 */

#include <bits/stdc++.h>
using namespace std;

// constraints
#define MAXN 100000

// input data
int N;
int H[MAXN];

int main() {
//  uncomment the following lines if you want to read/write from files
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    assert(1 == scanf("%d", &N));
    for(int i=0; i<N; i++)
        assert(1 == scanf("%d", &H[i]));

    // insert your code here
    int sol[100000];
    for(int i=0; i<N; i++) {
        sol[i] = -1;
    }

    // caso base
    sol[N-1] = 0; // l'ultimo non va mai cambiato

    for(int i=N-2; i>=0; i--) {
        if(H[i] < H[i+1]) {
            sol[i] = sol[i+1] + 1;
            H[i] = H[i+1];
        }
        else sol[i] = 0;
    }

    // posso ottimizzare aggiungendo max al primo for
    int max = 0;
    for(int i=0; i<N; i++) {
        if(sol[i] > max) max = sol[i];
    }

    printf("%d\n", max); // print the result

    return 0;
}