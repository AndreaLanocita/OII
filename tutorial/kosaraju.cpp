#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>

vi ordine;

void dfs1(int n, vi adj[], int visitato[]) {
    visitato[n] = 1;
    for(int vicino: adj[n]) 
        if(visitato[vicino] == 0) dfs1(vicino, adj, visitato);
    
    ordine.push_back(n);
}

void dfs2(int n, vi adj[], int scc[], int counter) {
    scc[n] = counter;

    for(int vicino: adj[n])
        if(scc[vicino] == 0) dfs2(vicino, adj, scc, counter);
}

int main() {
    int N, M, tmp1, tmp2, visitato[N] = { }, scc[N] = { };
    cin >> N >> M;

    vi adj[N];
    vi adj_rev[N];
    for(int i=0; i<M; i++) {
        cin >> tmp1 >> tmp2;
        adj[tmp1].push_back(tmp2);
        adj_rev[tmp2].push_back(tmp1);
    }

    for(int i=0; i<N; i++)
        if(visitato[i] == 0) dfs1(i, adj, visitato);

    int counter = 1;
    for(int i=ordine.size()-1; i>=0; i--) {
        if(scc[i] == 0) dfs2(i, adj_rev, scc, counter);
        counter++;
    }
}