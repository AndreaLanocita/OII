#include <bits/stdc++.h>
#include <climits>

using namespace std;

#define MAXN 100000
#define MAXM 100000

int up[MAXN][50];
int maxx[MAXN][50];
int depth[MAXN];
int max_log;

int dfs(int n, int pre, vector<int> adj[], int *briganti) {
    if(n==0) up[n][0] = 0;
    depth[n] = 0 ? n==0 : depth[pre]+1;

    for(int vicino: adj[n]) {
        if(vicino==pre) continue;
        up[vicino][0] = n;
        maxx[vicino][0] = max(briganti[vicino], briganti[n]);
        for(int i=1; i<=max_log; i++) {
            // forse da aggiungere max(bringanti[vicino])
            maxx[vicino][i] = max(maxx[vicino][i-1], maxx[up[vicino][i-1]][i-1]); 
            up[vicino][i] = up[up[vicino][i-1]][i-1];
        }
        dfs(vicino, n, adj, briganti);
    }
    return 0;
}

int res = INT_MIN;
int kth(int n, int k) {
    for(int i=0; i<=max_log; i++) {
        if(k & (1<<i)) {
            res = max(res, maxx[n][i]);
            n = up[n][i];
        }
    }
    return n;
}

int d;
int lca(int a, int b, int* briganti) {
    // controllo che a sia più basso
    if(depth[a] < depth[b]) swap(a, b);
    if(a==b) return 0;

    // kth ancestor --> stesso livello
    d = depth[a] - depth[b];
    a = kth(a, d);

    // sono uguali? Trovato lca
    if(a==b) return res;

    // porto su insieme
    for(int i=max_log; i>=0; i--) {
        if(up[a][i] == up[b][i]) continue;

        // codice
        res = max(res, max(maxx[a][i], maxx[b][i]));

        a = up[a][i];
        b = up[b][i];
    }

    // controllo che non sia max il lca
    return max(maxx[a][0], max(maxx[b][0], res));
}

void solve(int N, int Q, int *briganti, int *A, int *B, int *start, int *end, int *sol){
	vector<int> adj[N];
    max_log = (int)ceil(log2(N))+1;

	for(int i=0; i<N-1; i++) {
		adj[A[i]].push_back(B[i]);
		adj[B[i]].push_back(A[i]);
	}

    // precalcolo
    dfs(0, -1, adj, briganti);

    for(int i=0; i<Q; i++) {
        res = INT_MIN;
        sol[i] = lca(start[i], end[i], briganti);
    }
}

void solve(int N, int Q, int *briganti, int *A, int *B, int *start, int *end, int *sol);

int main()
{
    int N, Q ;
    cin >> N >> Q;
    int pesi[N] ;
    int a[N] , b[N] ;
    int qA[N], qB[N] ;
    int sol[N] ;
   
    int i;
    for( i = 0 ; i < N ; i++ ) cin >> pesi[i];
    for( i = 0 ; i < N-1 ; i++ ) cin >> a[i] >> b[i];
    for( i = 0 ; i < Q ; i++ ) cin >> qA[i] >> qB[i];
    solve(N,Q,pesi,a,b,qA,qB,sol);
    for( i = 0 ; i < Q ; i++ ) cout << sol[i] << " ";
    
    return 0;
}