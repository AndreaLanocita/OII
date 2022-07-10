#include <bits/stdc++.h>

using namespace std;

#define INF 2147483647

void mincammino(int N, int M, vector<int> X, vector<int> Y, vector<int> P, vector<int> &D) {
    int v[N]; // per ogni nodo, visitato
    int n; // indice nodo che controllo in questo momento, parto da sorgente

    D[0] = 0;
    for(int i = 1; i<N; i++) {
        D[i] = INF;
    }
    
    // dijikstra
    for(int i=0; i<N; i++) {
        // cerco nodo più vicino che non ho già visitato
        int min = INF;
        for(int j = 0; j<N; j++) {
            if(D[j] < min && v[j] != 1) n = j;
        }

        // visitato
        v[i] = 1;

        // controllo tutti nodi adiacenti, se posso migliorare distanza lo faccio
        // controllo quali sono gli adiacenti
        for(int j = 0; j<M; j++) {
            // il nodo di partenza è quello giusto
            if(X[j] == n) {
                // posso controllare nodo di fine e peso
                int finale = Y[j];
                if(P[j] + D[n] < D[finale]) D[finale] = P[j] + D[n];
            }
        }
    }

    // if distanza == inf cout -1
    for(int i=0; i<N; i++) {
        if(D[i] == INF) D[i] = -1;
    }
}

int main() {
    ios::sync_with_stdio(false);

    // Uncomment the following lines if you want to read/write from files
    // ifstream cin("input.txt");
    // ofstream cout("output.txt");

    // Reading input
    int N, M;
    cin >> N >> M;

    vector<int> X(M), Y(M), P(M), D(N);
    for (int i = 0; i < M; i++) {
        cin >> X[i] >> Y[i] >> P[i];
    }

    // Calling functions
    mincammino(N, M, move(X), move(Y), move(P), D);

    // Writing output
    for(int d : D) {
        cout << d << " ";
    }
    cout << endl;

    return 0;
}