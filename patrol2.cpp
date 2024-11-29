#include <bits/stdc++.h>
#include <climits>

using namespace std;

int mincammino(int N, int M, vector<int> &A, vector<int> &B, vector<int> &C) {
    int v[N] = { }; // per ogni nodo, visitato
    int n; // indice nodo che controllo in questo momento, parto da sorgente
    int D[N];

    // precalcolo, metto tutto in una lista di adiacenza
    vector<int> adj[N];  // posti pari = nodo arrivo, dispari = costo;
    for(int i=0; i<M; i++) {
        adj[A[i]].push_back(B[i]);
        adj[B[i]].push_back(A[i]);
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
            if(v[n] != 1) break;  
            distanze.pop();  // se no lo tolgo e continuo a cercare
        }
        if(distanze.empty()) break;  // non ho niente da controllare
        distanze.pop();
        if(n==N-1) break;
        // visitato
        v[n] = 1;

        // controllo tutti nodi adiacenti, se posso migliorare distanza lo faccio
        for(int j=0; j<adj[n].size(); j++) {  // controllo solo i numeri pari della lista, i dispari sono i pesi
            // mi trovo dove è la guardia
            if(C[(D[n]+1) % C.size()] == adj[n][j]) {
                if(v[adj[n][j]] != 1 && D[adj[n][j]] > D[n] + 2) {
                    D[adj[n][j]] = D[n] + 2;    // di sicuro ci posso andare due dopo
                    distanze.push({D[adj[n][j]], adj[n][j]});
                } 
            } else {
                if(v[adj[n][j]] != 1 && D[adj[n][j]] > D[n] + 1) {
                    D[adj[n][j]] = 1 + D[n];
                    distanze.push({D[adj[n][j]], adj[n][j]});
                } 
            }
            
        }
    }
    return D[N-1];
}

int main() {
    // uncomment the following lines if you want to read/write from files
    // ifstream cin("input.txt");
    // ofstream cout("output.txt");

    int N, M, L;
    cin >> N >> M >> L;

    vector<int> A(M), B(M);
    for (int i = 0; i < M; ++i) cin >> A[i] >> B[i];

    vector<int> C(L);
    for (auto &x : C) cin >> x;

    // insert your code here

    cout << mincammino(N, M, A, B, C) << endl;  // print the result
    return 0;
}
