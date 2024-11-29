#include <bits/stdc++.h> 

using namespace std;

#define vi vector<int>
#define pi pair<int, int>
#define vp vector<pi>
#define ll long long int

#define MAXN 10000

// tiene il nodo
int up[MAXN][200];  // should be log2(MAXN)+1
int log_max;
int depth[MAXN];

void dfs(int n, int pre, vi adj[]) {
    if(n==0) {
        up[0][0] = 0;
        depth[0] = 0;
    } 
    else {
        up[n][0] = pre;
        depth[n] = depth[pre]+1;
    } 

    for(int i=1; i<=log_max; i++) {
        // divido a metà, la prima parte sarà un ancestor
        up[n][i] = up[up[n][i-1]][i-1];
    }

    // visito vicini
    for(int vicino: adj[n]) {
        if(vicino==pre) continue;
        dfs(vicino, n, adj);
    }
}

// k-th ancestor
int kth_a(int a, int k) {
    for(int i=0; i<=log_max; i++) {
        if(k & (1 << i)) {
            // sposto l'1 vs sx di quella potenza di due
            // & returns true se almeno uno dei bit controllati
            // è 1 in entrambi
            a = up[a][i];

            // dato che l'array è inizializzato a 0, tutti gli
            // ancestor a cui non si arriva da un nodo portano al root
        }   
    }
    return a;
}

int lca(int a, int b) {
    // a è più in basso
    if(depth[a] < depth[b]) swap(a, b);
    int k = depth[a] - depth[b];
    a = kth_a(a, k);

    // stesso nodo
    if(a==b) return a;

    for(int i=log_max; i>=0; i--) {
        if(up[a][i] == up[b][i]) continue;
        a = up[a][i];
        b = up[b][i];
    }

    // risalgo dell'ultimo
    return up[a][0];
}

int init(int N, vi adj[]) {
    log_max = (int)ceil(log2(N));
    dfs(0, -1, adj); 
}