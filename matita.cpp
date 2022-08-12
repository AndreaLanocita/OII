#include <bits/stdc++.h>

using namespace std;

vector<int> ordine;
int N, M, A, B;

int dfs(int nodo, unordered_map<int, int> adj[]) {
    int next;
    // dfs fino a quando nonn rimaniamo bloccati
    while(adj[nodo].size() > 0) {  
        // tolgo l'edge dalla mappa
        next = adj[nodo].begin()->first;
        adj[next].erase(nodo);
        adj[nodo].erase(next);

        dfs(next, adj);  
    }

    // siamo bloccati, aggiungiamo il nodo alla soluzione e torniamo indietro
    ordine.push_back(nodo);
    return 0;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int tmp1, tmp2;
    cin >> N >> M >> A >> B;
    
    unordered_map<int, int> adj[N+1];   //we use a map to erase edges in O(1)

    for(int i=0; i<M; i++) {
        cin >> tmp1 >> tmp2;
        adj[tmp1][tmp2] = 1;
        adj[tmp2][tmp1] = 1;
    }

    dfs(A, adj);
    for(int i=ordine.size()-1; i>0; i--) {
        cout << ordine[i] << " " << ordine[i-1] << "\n";
    }

    return 0;
}