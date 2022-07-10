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
long long int N, K, Q, P, i;
long long int V[MAXN];

long long int check() {
    long long int res = 0;
    long long int check = 0;
    pair<long long int, long long int> n_insetticida;
    pair<long long int, long long int> g_insetticida;
    // metto prima quello potente, poi quello scrauso
    if(P>=Q) {
        g_insetticida.first = P;
        g_insetticida.second = Q;
    }
    else {
        g_insetticida.first = Q;
        g_insetticida.second = P;
    }

    while(check == 0) {
        check = 1;
        if(P>=Q) {
            n_insetticida.first = K;
            n_insetticida.second = (N-K);
        }
        else {
            n_insetticida.second = K;
            n_insetticida.first = (N-K);
        }
        res++;
        sort(V, V+N);

        // uso per i posti con + insetti l'insetticida migliore
        long long int i=N-1;
        for(; i>= 0 && n_insetticida.first != 0; i--) {
            V[i] -= g_insetticida.first;
            n_insetticida.first--;
        }
        // secondo insetticida
        for(; i>=0; i--) {
            V[i] -= g_insetticida.second;
            n_insetticida.second--;
        }

        // controllo se ho ucciso tutti gli insetti
        for(long long int i=0; i<N; i++) {
            if(V[i] > 0) {
                check = 0;
                break;
            } 
        }
    }

    return res;
}

int main() {
//  uncomment the following lines if you want to read/write from files
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    assert(2 == scanf("%lld%lld", &N, &K));
    assert(2 == scanf("%lld%lld", &P, &Q));
    for(i=0; i<N; i++)
        assert(1 == scanf("%lld", &V[i]));

    // massimo per la ricerca binaria, se utilizzassi il peggiore repellente
    // ogni giorno per la stanza con più insetti

    printf("%lld\n", check()); // print the result
    return 0;
}
