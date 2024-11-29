#include <bits/stdc++.h>
#include <climits>

using namespace std;

#define pb push_back
#define popb pop_back
#define vi vector<int>
#define pi pair<int, int>
#define vp vector<pi>
#define ll long long int
#define pl pair<ll, ll>
#define vl vector<ll>
#define vpl vector<pl>
#define omap map<int, int>
#define umap unordered_map<int, int>
#define pq priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>>

void mincammino(int N, int M, vector<int> X, vector<int> Y, vector<int> P, vector<int> &D) {
    int v[N] = { }; // per ogni nodo, visitato
    int n; // indice nodo che controllo in questo momento, parto da sorgente

    // precalcolo, metto tutto in una lista di adiacenza
    vector<pi> adj[N];  // posti pari = nodo arrivo, dispari = costo;
    for(int i=0; i<M; i++) {
        adj[X[i]].push_back({Y[i], P[i]});
        adj[Y[i]].push_back({X[i], P[i]});
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> distanze;    // distanza, nodo di arrivo
    distanze.push({0, 0});
    D[0] = 0;
    for(int i = 1; i<N; i++) D[i] = INT_MAX;
    
    // dijikstra
    for(int i=0; i<N; i++) {
        // cerco nodo più vicino che non ho già visitato
        while(!distanze.empty()) {
            n = distanze.top().second;
            if(v[n] != 1) break;  // l'ho già visitato?
            distanze.pop();  // se no lo tolgo e continuo a cercare
        }
        if(distanze.empty()) break;  // non ho niente da controllare
        distanze.pop();
        // visitato
        v[n] = 1;

        // controllo tutti nodi adiacenti, se posso migliorare distanza lo faccio
        for(pi vicino: adj[n]) {  // controllo solo i numeri pari della lista, i dispari sono i pesi
            if(v[vicino.second] != 1 && vicino.first + D[n] < D[vicino.second]) {
                D[vicino.second] = vicino.first + D[n];
                distanze.push({D[vicino.second], vicino.second});
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