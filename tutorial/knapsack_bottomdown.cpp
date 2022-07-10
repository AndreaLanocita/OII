#include <bits/stdc++.h>

using namespace std;

int p[1000];
int w[1000];
int ans[1000][1000];    // tiene ripsota a sottoproblemi, iniazializzato a -1
int c;

// k indica sia l'oggetto dell'array, sia nella ricorrenza di ans il sottoproblema per ogni oggetto da 0 a k
int solve(int k, int c) {
    // caso base
    if(k==-1) return 0;

    // controllo se ho gia calcolato la risposta per k, se si la riporto
    if(ans[k][c] != -1) return ans[k][c];

    // posso sempre tenere conto del caso in cui non aggiungo un oggetto --> prendo la soluzione fino all'oggetto prima
    ans[k][c] = solve(k-1, c);

    // controllo se l'oggetto k ci sta nello zaino, se si vedo se raggiungo una soluzione migliore aggiungendolo
    if(w[k] <= c) ans[k][c] = max(ans[k][c], solve(k-1, c-w[k]) + v[k]);

    return ans[k][c];
}