#include <bits/stdc++.h>
#include <climits>

using namespace std;

void mincammino(int N, int M, vector<int> X, vector<int> Y, vector<int> P, vector<int> &D) {
    int v[N] = { }; // per ogni nodo, visitato
    int n; // indice nodo che controllo in questo momento, parto da sorgente

    // CSR
    int v1[N] = { };
    for(int i=0; i<M; i++) v1[X[i]]++;

    // Prefix sum array
    int psa[N+1];
    psa[0] = 0;
    for(int i=1; i<N+1; i++) psa[i] = v1[i-1] + psa[i-1];

    // copia del psa
    int v3[N+1];
    for(int i=0; i<N+1; i++) v3[i] = psa[i];

    // adj
    int adj[psa[N]];
    // archi pesati
    int costo[psa[N]];

    for(int i=0; i<M; i++) {
        adj[v3[X[i]]] = Y[i];
        costo[v3[X[i]]] = P[i];
        v3[X[i]]++;
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> distanze;    // distanza, nodo di arrivo
    distanze.push({0, 0});
    D[0] = 0;
    for(int i = 1; i<N; i++) {
        distanze.push({INT_MAX, i});
        D[i] = INT_MAX;
    }
    
    // dijikstra
    for(int i=0; i<N; i++) {
        // cerco nodo più vicino che non ho già visitato
        while(true && !distanze.empty()) {
            n = distanze.top().second;
            // è up-to-date o è una useless entry?
            if(D[n] == distanze.top().first && v[n] != 1 && D[n] != INT_MAX) break;  
            distanze.pop();  // se no lo tolgo e continuo a cercare
        }
        if(distanze.empty()) break;  // non ho niente da controllare
        distanze.pop();
        // visitato
        v[n] = 1;

        // controllo tutti nodi adiacenti, se posso migliorare distanza lo faccio
        for(int j=psa[n]; j<psa[n+1]; j++) {  
            if(v[adj[j]] != 1 && costo[j] + D[n] < D[adj[j]]) {
                D[adj[j]] = costo[j] + D[n];
                distanze.push({D[adj[j]], adj[j]});
            } 
        }
    }

    // if distanza == INT_MAX cout -1
    for(int i=0; i<N; i++) {
        if(D[i] == INT_MAX) D[i] = -1;
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