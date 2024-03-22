#include <bits/stdc++.h>

using namespace std;

#define MAXN 10000

int res = 0;
int dfs(int n, vector<int> adj[], int pre, int brav[], int B[]) {
    int somma = 0;
    for(int vicino: adj[n]) {
        if(vicino==pre) continue;
        somma += dfs(vicino, adj, n, brav, B);
    }
    brav[n] = max(somma, B[n]);
    return brav[n];
}

void dfs1(int n, vector<int> adj[], int pre, int brav[], int B[]) {
    // dovrebbe prendere anceh le foglie, dove brav == 0
    if(brav[n] <= B[n]) {
        res += B[n];
        return ;
    } 
    for(int vicino: adj[n]) {
        if(vicino==pre) continue;
        dfs1(vicino, adj, n, brav, B);
    }
    return ;
}

int recluta(int N, int B[], int C[]) {
    // faccio albero e cerco il capo
    vector<int> adj[N];
    int brav[N]; // somma delle bravure del subtree del nodo, escluso quel nodo
    int capo;
    for(int i=0; i<N; i++) {
        if(C[i]==-1) {
            capo = i;
            continue;
        } 
        adj[i].push_back(C[i]);
        adj[C[i]].push_back(i);
    }

    // faccio array dei subtree
    dfs(capo, adj, -1, brav, B);
    dfs1(capo, adj, -1, brav, B);
    return res;
}


int B[MAXN], C[MAXN];

int main() {
    cin.tie(0); ios::sync_with_stdio(false);
    FILE *fr, *fw;
    int N, i;
    
    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(1 == fscanf(fr, "%d", &N));
    for(i=0; i<N; i++)
        assert(2 == fscanf(fr, "%d %d", &B[i], &C[i]));
    
    fprintf(fw, "%d\n", recluta(N, B, C));
    fclose(fr);
    fclose(fw);
    return 0;
}
