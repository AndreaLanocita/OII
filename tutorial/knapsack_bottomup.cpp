#include <bits/stdc++.h>

using namespace std;

int p[1000];
int w[1000];
int ans[1000][1000];    // tiene ripsota a sottoproblemi, iniazializzato a -1
int C;   // capienza
int N;   // numero di oggetti

int main() {
    // dato che non si può accedere ad un array con index -1, come passo base si usa 0
    for(int c=0; c<=C; c++) {
        // per ogni prefisso (gruppo di elementi prima di) k se il peso del primo oggetto è maggiore dell'index (capacità di quel sottoproblema)
        // allora la soluzione è 0 (zaino vuoto), se no è il valore del primo oggetto, che aggiungo
        if(w[0] > c) ans[0][c] = 0; 
        else ans[0][c] = V[0];
    }

    for(int k=1; k<N; k++) {
        // per ogni oggetto, scorro ciascuno dei "sottoproblemi" (zaini con capienza da 0 a C) e calcolo la soluzione ottimale
        for(int c=0; c<=C; c++) {
            // posso sempre tenere conto del caso in cui non aggiungo un oggetto --> prendo la soluzione fino all'oggetto prima
            ans[k][c] = ans[k-1][c];
            // controllo se l'oggetto k ci sta nello zaino, se si vedo se raggiungo una soluzione migliore aggiungendolo
            if(w[k] <= c) ans[k][c] = max(ans[k][c], ans[k-1][c-w[k]] + v[k]);
        }
    }
}

int risparmio_memoria() {
    // dato che per ogni iterazione accedo solo alla parte k-1 del vettore,
    // mi salvo solo quella, calcolo il nuovo vettore in un temporaneo e poi
    // lo sostituistico
    int ans_tmp[C];
    int ans_v[C];
    
    // caso base
    for(int c=0; c<=C; c++) {
        if(w[0] > c) ans[c] = 0;
        else ans[c] = V[0];
    }
    
    for(int k=1; k<N; k++) {
        for(int c=0; c<=C; c++) {
            ans_tmp[c] = ans_v[c];
            if(w[k] <= c) ans_tmp[c] = max(ans_tmp[c], ans_v[c-w[k]] + v[k]);
        }
        ans_v = ans_tmp;
    }
}
