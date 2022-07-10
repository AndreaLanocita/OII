#include <bits/stdc++.h>

using namespace std;

int N, K;
long long peso[5000];
long long sol[5000][5000];

int mangia(long long f, long long c) { // c = K - peso già occupato
    // caso base -- primo panino
    if(c<=0) return 0;
    
    if(f==0) {
        return peso[0];
    }

    // controllo
    if(sol[f][c] != 0) return sol[f][c];

    // soluzione
    long long temp;
    temp = mangia(f-1, c); // non prendo questo panino
    sol[f][c] = mangia(f-1, c-peso[f]) + peso[f]; // prendo panino

    if(temp >= c && temp <= sol[f][c]) sol[f][c] = temp;

    return sol[f][c];
}


int main() {
    FILE *fr, *fw;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(2 == fscanf(fr, "%d %d", &N, &K));
    for(int i=0; i<N; i++) {
        assert(1 == fscanf(fr, "%lld", &peso[i]));
    }
    
    long long finale = mangia(N-1, K);
    fprintf(fw, "%lld\n", finale);
    fclose(fr);
    fclose(fw);
    return 0;
}
