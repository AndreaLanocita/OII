#include <bits/stdc++.h> 

using namespace std;

#define vi vector<int>
#define pi pair<int, int>
#define vp vector<pi>
#define ll long long int
#define omap map<int, int>
#define umap unordered_map<int, int>

// da rifare senza adj con kruskal

void solve(int N, int P) {
    vi v(N);
    for(int i=0; i<N; i++) cin >> v[i];
    vp adj[N];
    for(int i=0; i<N; i++) {
        int minn = v[i];
        int gcdd = v[i];
        for(int j=i+1; j<N; j++) {
            if(v[j]<minn) minn=v[j];
            gcdd = gcd(gcdd, v[j]);
            int tmp1 = INT_MAX; int tmp2 = INT_MAX;
            if(i+1==j) tmp1 = P;
            if(gcdd==minn) tmp2=minn;
            if(tmp1==INT_MAX && tmp2==INT_MAX) continue;

            adj[i].push_back({j, min(tmp1, tmp2)});
            adj[j].push_back({i, min(tmp1, tmp2)});
        }
    }

    int nodo = 0, n_raggiunti = 0, sol = 0;
    int visitato[N] = { };     // per ciascun nodo, raggiunto o no?
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> vicini;
    
    while(n_raggiunti<N) {  // quando visitiamo tutti i nodi abbiamo un mst
        visitato[nodo] = 1;
        // aggiungo alla pq nuovi archi usabili
        for(pair<int, ll> vicino: adj[nodo]) {
            // se non ho già raggiunto il nodo aggiungo arco a pq
            if(visitato[vicino.first] == 0) vicini.push({vicino.second, vicino.first});
        }

        // scelgo il nuovo arco da aggiungere
        pair<ll, int> arco;
        while(!vicini.empty()) {
            arco = vicini.top();
            // controllo se ho visitato il nodo, di sicuro lo visito
            // per primo con l'insieme di archi che risulta nella minore distanza
            if(visitato[arco.second] == 0) break;
            vicini.pop();
        }
        nodo = arco.second;
        if(vicini.empty()) break;
        vicini.pop();

        // salvo l'arco
        sol += arco.first;
        n_raggiunti++;
    }

    cout << sol << endl;
}

int main() {
    int t;
    cin >> t;
    for(int i=0; i<t; i++) {
        int n, p;
        cin >> n >> p;
        solve(n, p);
    }
    return 0;
}