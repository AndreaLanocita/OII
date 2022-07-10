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
int N, D, i;
int P[MAXN];

long long int b_search(long long int inizio, long long int r) {
    long long int l = inizio;
    long long int mid;
    // mi fermo dove non costituisce più un problema
    while(l<r) {
        mid = (l+r)/2;
        // non rispetta la condizione, devo andare più avanti
        if(P[mid] - P[inizio-1] < D) l = mid+1;

        else r = mid;
    }
    // caso speciale, nessuna coppia rispetta le distanze
    if(r==N-1 && P[r] - P[inizio-1] < D) return r-inizio+1;
    // ritorno il numero di persone che non rispetta la condizione
    return r - inizio;
}

int main() {
//  uncomment the following lines if you want to read/write from files
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    assert(2 == scanf("%d %d", &N, &D));
    for(i=0; i<N; i++)
        assert(1 == scanf("%d", &P[i]));

    
    long long answer = 0;
    for(int i=0; i<N-1; i++) {
        answer += b_search(i+1, N);
    }
    
    printf("%lld\n", answer); // print the result
    return 0;
}
