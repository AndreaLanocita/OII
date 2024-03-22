#include <bits/stdc++.h>

using namespace std;

int N, K;
int peso[5000];
long long sol[5000][5000];


int main() {
    FILE *fr, *fw;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(2 == fscanf(fr, "%d %d", &N, &K));
    for(int i=0; i<N; i++) {
        assert(1 == fscanf(fr, "%d", &peso[i]));

        for(int j=0; j<=K; j++) {
            sol[i][j] = -1;
        }
    }

    // bottom-up
    // casi base per k=0
    for(int c=0; c<=K; c++) {
        if(peso[0] > c) sol[0][c] = peso[0];
        else sol[0][c] = 0; 
    }

    // sol
    for(int i=1; i<N; i++) {
        for(int c=1; c<=K; c++) {
            long long temp;
            temp = sol[i-1][c]; // non prendo questo panino
            // potendo prendo solo questo panino, è di sicuro meglio che
            // prendere anche il precedente
            if(peso[i] >= c) sol[i][c] = 0 + peso[i];
            else sol[i][c] = sol[i-1][c-peso[i]] + peso[i]; // prendo entrambi
            
            if(temp >= c) { // caso in cui non prendo il panino è valido
                if(temp <= sol[i][c]) sol[i][c] = temp;
            }
        }
    }

    
    fprintf(fw, "%lld\n", sol[N-1][K]);
    fclose(fr);
    fclose(fw);
    return 0;
}
