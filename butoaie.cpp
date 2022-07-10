/*
 * This template is valid both in C and in C++,
 * so you can expand it with code from both languages.
 * NOTE: it is recommended to use this even if you don't
 * understand the following code.
 */

#include <bits/stdc++.h>

using namespace std;

// constraints
#define MAXN 200000

// input data
long long int N, K;
long long int Q, P, i;
long long int V[MAXN];

// circa NlogN

int check(long long int giorni) {
    // K*P + (N-K) * Q = INSETTI CHE POSSO UCCIDERE =
    // = K(P-Q) + NQ CON P>=Q --> POSSO USARE PER CIASCUNA STANZA LO STESSO REPELLENTE Q
    
    long long int insetti;

    // contatore di quanti insetticidi buoni ho bisogno
    long long int usi = giorni*K;

    for(int i=0; i<N; i++) {
        insetti = V[i];
        // posso uccidere gli insetti anche solo con il repellente peggiore nel numero di giorni
        // predisposti
        if(giorni * Q >= insetti) continue;

        // se neanche il repellente migliore usato ogni giorno basta esco
        if(giorni * P < insetti) return 0;

        // insetti rimasti se usassi ogni giorno il peggiore repellente
        insetti -= (giorni * Q);

        // gli usi (giorni in cui uso) del migliore repellente possoono essere trovati dividendo gli insetti rimasti
        // per la differenza di potenza tra i due repellenti, dato mi sono comportato come se avessi gia applicato
        // il peggior repellente dappertutto
        usi -= (insetti / (P-Q));
        if(insetti % (P-Q) != 0) usi--;
        if(usi < 0) return 0; 
    }
    // tutto ok
    return 1;
}

long long int b_search(long long int l, long long int r) {
    long long int mid;
    while(l<r) {
        mid = (l+r)/2;
        // non rispetta la condizione, aumento i giorni
        if(check(mid) == 0) l = mid+1;
        else r = mid;
    }
    return r;
}

int main() {
//  uncomment the following lines if you want to read/write from files
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    assert(2 == scanf("%lld%lld", &N, &K));
    assert(2 == scanf("%lld%lld", &P, &Q));
    for(i=0; i<N; i++) 
        assert(1 == scanf("%lld", &V[i]));

    // insert your code here
    // massimo per la ricerca binaria, se utilizzassi il peggiore repellente
    // ogni giorno per la stanza con più insetti

    if(Q>P) {
        swap(P, Q);
        K=N-K;
    }

    printf("%lld\n", b_search(0, 1e9)); // print the result
    return 0;
}