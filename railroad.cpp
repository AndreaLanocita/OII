#include <bits/stdc++.h>

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

ll mincammino(int N, int M, vector<int> &X, vector<int> &Y, vector<int> &P, vector<ll> &D) {
    ll v[N] = { }; // per ogni nodo, visitato
    ll n; // indice nodo che controllo in questo momento, parto da sorgente
    ll flag = 0;
    ll res_parz = 0;

    // precalcolo, metto tutto in una lista di adiacenza
    vector<pair<ll, int>> adj[N];  // posti pari = nodo arrivo, dispari = costo;
    for(int i=0; i<M; i++) {
        adj[X[i]].push_back({Y[i], P[i]});
        adj[Y[i]].push_back({X[i], P[i]});
    }

    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> distanze;    // distanza, nodo di arrivo
    distanze.push({0, 0});
    D[0] = 0;
    for(int i = 1; i<N; i++) D[i] = LLONG_MAX;
    
    // dijikstra
    while(1) {
        // cerco nodo più vicino che non ho già visitato
        while(!distanze.empty()) {
            n = distanze.top().second;
            if(v[n] != 1) break;  // l'ho già visitato?
            distanze.pop();  // se no lo tolgo e continuo a cercare
        }
        if(distanze.empty()) break;  // non ho niente da controllare
        distanze.pop();
        if(n==N-1) {
            // ho trovato un altor path
            if(flag==1 && D[N-1] != res_parz) {
                return D[N-1]-res_parz;
            }
            res_parz = D[N-1];
            D[N-1] = LLONG_MAX;
            flag = 1;
            continue;
        }
        // visitato
        v[n] = 1;

        // controllo tutti nodi adiacenti, se posso migliorare distanza lo faccio
        for(pair<ll, int> vicino: adj[n]) {  // controllo solo i numeri pari della lista, i dispari sono i pesi
            if(v[vicino.first] != 1 && vicino.second + D[n] < D[vicino.first]) {
                D[vicino.first] = vicino.second + D[n];
                distanze.push({D[vicino.first], vicino.first});
            } 
        }
    }
    return -1;
}

int main() {
    //  uncomment the following lines if you want to read/write from files
    ifstream cin("input.txt");
    ofstream cout("output.txt");

    int N, M;
    cin >> N >> M;

    vector<int> A(M), B(M), C(M);
    vector<ll> D(N);
    for (int i = 0; i < M; i++) {
        cin >> A[i] >> B[i] >> C[i];
    }

    cout << mincammino(N, M, A, B, C, D) << endl; // print the result
    return 0;
}
