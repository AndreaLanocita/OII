#include <bits/stdc++.h>
#include <climits>

using namespace std;

void mincammino(int N, int M, vector<int> X, vector<int> Y, vector<int> P, vector<int> &D) {
    int v[N] = { }; // per ogni nodo, visitato
    int n; // indice nodo che controllo in questo momento, parto da sorgente

    // precalcolo, metto tutto in una lista di adiacenza
    vector<int> adj[N];  // posti pari = nodo arrivo, dispari = costo;
    for(int i=0; i<M; i++) {
        adj[X[i]].push_back(Y[i]);
        adj[X[i]].push_back(P[i]);
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> distanze;    // distanza, nodo di arrivo
    distanze.push({0, 0});
    D[0] = 0;
    for(int i = 1; i<N; i++) {
        D[i] = INT_MAX;
    }
    
    // dijikstra
    for(int i=0; i<N; i++) {
        // cerco nodo più vicino che non ho già visitato
        while(!distanze.empty()) {
            n = distanze.top().second;
            // è up-to-date o è una useless entry? l'ho già visitato?
            if(D[n] == distanze.top().first && v[n] != 1) break;  
            distanze.pop();  // se no lo tolgo e continuo a cercare
        }
        if(distanze.empty()) break;  // non ho niente da controllare
        distanze.pop();
        // visitato
        v[n] = 1;

        // controllo tutti nodi adiacenti, se posso migliorare distanza lo faccio
        for(int j=0; j<adj[n].size(); j+=2) {  // controllo solo i numeri pari della lista, i dispari sono i pesi
            if(v[adj[n][j]] != 1 && adj[n][j+1] + D[n] < D[adj[n][j]]) {
                D[adj[n][j]] = adj[n][j+1] + D[n];
                distanze.push({D[adj[n][j]], adj[n][j]});
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