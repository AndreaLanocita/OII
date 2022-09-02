#include <bits/stdc++.h>

using namespace std;

#define ll long long int

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    ifstream cin("input.txt");
    ofstream cout("output.txt");

    int N, M, tmp1, tmp2;
    ll tmp3;
    cin >> N >> M;

    vector<pair<int, ll>> adj[N+1];  // arrivo, peso 
    for(int i=0; i<M; i++) {
        cin >> tmp1 >> tmp2 >> tmp3;
        adj[tmp1].push_back({tmp2, tmp3});
        adj[tmp2].push_back({tmp1, tmp3});
    }
    
    int nodo = 1, n_raggiunti = 0, sol = 0;
    vector<pair<int, int>> S;   // archi scelti
    int visitato[N+1] = { };     // per ciascun nodo, raggiunto o no?
    // insieme di archi che portano a nodi raggiungibili
    priority_queue<pair<ll, pair<int, int>>, vector<pair<ll, pair<int, int>>>, greater<pair<ll, pair<int, int>>>> vicini;
    
    while(n_raggiunti<N) {  // quando visitiamo tutti i nodi abbiamo un mst
        visitato[nodo] = 1;

        // aggiungo alla pq nuovi archi usabili
        for(pair<int, ll> vicino: adj[nodo]) {
            // se non ho già raggiunto il nodo aggiungo arco a pq
            if(visitato[vicino.first] == 0) vicini.push({vicino.second, {nodo, vicino.first}});
        }

        // scelgo il nuovo arco da aggiungere
        pair<ll, pair<int, int>> arco;
        while(!vicini.empty()) {
            arco = vicini.top();
            // controllo se ho visitato il nodo, di sicuro lo visito
            // per primo con l'insieme di archi che risulta nella minore distanza
            if(visitato[arco.second.second] == 0) break;
            vicini.pop();
        }
        nodo = arco.second.second;
        if(vicini.empty()) break;
        vicini.pop();

        // salvo l'arco
        S.push_back(arco.second);
        sol += arco.first;
        n_raggiunti++;
    }

    cout << sol << "\n";
    for(int i=0; i<S.size(); i++) {
        cout << S[i].first << " " << S[i].second << "\n"; 
    }
    return 0;
}