#include <bits/stdc++.h>

using namespace std;

// dfs con counter, se incontro un già visitato interrompo
// e rimuovo ricorsivamente tutti i visitati
vector<int> ordine;
int N, M, A, B;

pair<int, int> checkDirected(vector<int> &inDegree, vector<int> &outDegree) {
    int start = -1, end = -1;
    for(int i=1; i<=N; i++) {
        if(inDegree[i] - outDegree[i] > 1) return {-1, -1}; 
        if(inDegree[i] - outDegree[i] == 1 && end == -1) end = i;
        else if(outDegree[i] - inDegree[i] == 1 && start == -1) start = i;
        else if(outDegree[i] - inDegree[i] != 0) return {-1, -1};
    }
    return {start, end};
}

int checkUndirected(vector<int> &n_unvisited, vector<int> &odd) {
    // it's an undirected graph
    // counter of odd vertices, max can be two. I need them as they are going to be the starting and ending point
    for(int i=1; i<=N; i++) {
        if(n_unvisited[i] % 2 == 1) {
            odd.push_back(i);
            if(odd.size() > 2) return -1;
        }
    }
    if(odd.size() == 1) return -1;
    return 0;
}

vector<int> ordine;
int N, M, A, B;

int dfsUndirected(int nodo, unordered_map<int, int> adj[]) {
    int next;
    // dfs fino a quando nonn rimaniamo bloccati
    while(adj[nodo].size() > 0) {  
        // tolgo l'edge dalla mappa
        next = adj[nodo].begin()->first;
        adj[next].erase(nodo);
        adj[nodo].erase(next);

        dfsUndirected(next, adj);  
    }

    // siamo bloccati, aggiungiamo il nodo alla soluzione e torniamo indietro
    ordine.push_back(nodo);
    return 0;
}

int dfsDirected(int nodo, vector<int> adj[], vector<int> &n_unvisited) {
    int tmp;
    // dfs fino a quando nonn rimaniamo bloccati
    while(n_unvisited[nodo] != -1) {    // l'ho reso 0 based dato ceh deve essere anche l'index di adj[N]
        n_unvisited[nodo] -= 1;
        dfsDirected(adj[nodo][n_unvisited[nodo]+1], adj, n_unvisited);  // ho riaggiunto l'1 che avevo rimosso
    }

    // siamo bloccati, aggiungiamo il nodo alla soluzione e torniamo indietro
    ordine.push_back(nodo);
    return 0;
}

int main() {
    int tmp1, tmp2;
    cin >> N >> M >> A >> B;
    
    vector<int> adj[N+1];
    // number of unvisted edges for each vertex + index in the adj list of the adjacent edge to visit for each node --> it should be 0 based --> no edges = -1
    vector<int> n_unvisited(N+1, -1);

    for(int i=0; i<M; i++) {
        cin >> tmp1 >> tmp2;
        adj[tmp1].push_back(tmp2);
        adj[tmp2].push_back(tmp1);

        n_unvisited[tmp1]++;
        n_unvisited[tmp2]++;
    }

    // check if there is an eulerian path / circuit
    vector<int> odd;
    if(checkUndirected(n_unvisited, odd) == -1) return -1;

    // dfs
    // dfs(A, adj, n_unvisited);

    // cout con \n
    return 0;
}