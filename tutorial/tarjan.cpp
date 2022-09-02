#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define pi pair<int, int>

int UNVISITED = -1, v;
int dfsNumberCounter;   // counts all of the visited elements across all of the dfs, serves to give unique ids to nodes
int numSCC; // counts the number of strongly directed components
// ==-1 if univisited, otherwise unique id of the node; lowest id across all of the nodes in that strongly connected component;
// stack of nodes visited during this dfs; check if a node is part of the stack in O(1);
vi id, low, S, onStack; 
// bonus, vettore extra per trovare monte e foce
vi ordine;

void dfs(int n, vector<pi> adj[]) {
    // assign a unique id, which is initially the same as the lowest value of the node's SCC
    // since we haven't found one
    low[n] = id[n] = dfsNumberCounter++;

    // add the node to the stack
    S.push_back(n);
    onStack[n] = 1;

    for (pi vicino: adj[n]) {
        if(id[vicino.first] == UNVISITED) dfs(vicino.first, adj);
        // the node can be reached through a path (it's adjacent) and is part of the stack
        // has been visited in this dfs --> they are part of the same SCC --> update the node's
        // low id to the lowest low of the two. low is propagated, same low value == same SCC
        if(onStack[vicino.first]) low[n] = min(low[n], low[vicino.first]);
    }

    // since ids are given out in the order in which I visit a node and ids given before are lower,
    // once I find a node with the same low value and id, that's where the SCC started
    if (low[n] == id[n]) {
        // remove all of the nodes in the SCC from the stack
        while (1) {
            v = S.back();   
			low[v] = id[n];
            S.pop_back();
            onStack[v] = 0; 

            if(n==v) break;
        }
    }
    // ordine di chiusura nodi
    ordine.push_back(n);
}

int main() {
    int N, M, tmp1, tmp2, tmp3;
    cin >> N >> M;
    vector<pi> adj[N];

    id.assign(N, UNVISITED);
    low.assign(N, 0);
    onStack.assign(N, 0);

    for(int i=0; i<M; i++) {
        cin >> tmp1 >> tmp2 >> tmp3;
        adj[tmp1].push_back({tmp2, tmp3});
        adj[tmp2].push_back({tmp1, tmp3});
    }

    dfsNumberCounter = numSCC = 0;

    for (int i = 0; i < N; i++)
        if (id[i] == UNVISITED) dfs(i, adj);
}

