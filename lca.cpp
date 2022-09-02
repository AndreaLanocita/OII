#include <bits/stdc++.h> 

using namespace std;

#define vi vector<int>
#define pi pair<int, ll>
#define vp vector<pi>
#define ll long long int

#define MAXN 100500

// tiene il nodo
int up[MAXN][50];  // should be log2(MAXN)+1
ll peso[MAXN][50];  // should be log2(MAXN)+1
int log_max;
ll depth[MAXN];
ll minn[MAXN][50];
ll maxx[MAXN][50];

void dfs(int n, int pre, vp adj[]) {
    if(n!=0) depth[n] = depth[pre]+1;

    // visito vicini
    for(pi vicino: adj[n]) {
        if(vicino.first==pre) continue;

		up[vicino.first][0] = n;
		peso[vicino.first][0] = vicino.second;	// peso per arrivare al precedente
		minn[vicino.first][0] = vicino.second;
		maxx[vicino.first][0] = max((ll)0, vicino.second);
		for(int i=1; i<=log_max; i++) {
			// divido a metà, la prima parte sarà un ancestor
			up[vicino.first][i] = up[up[vicino.first][i-1]][i-1];
			// somma tra le due parti, i due salti logaritmici che faccio
			peso[vicino.first][i] = peso[up[vicino.first][i-1]][i-1] + peso[vicino.first][i-1];
			minn[vicino.first][i] = min(minn[up[vicino.first][i-1]][i-1], minn[vicino.first][i-1]);
			// massimo tra il primo cammino, il secondo cammino e la somma tra i due
			maxx[vicino.first][i] = max(maxx[vicino.first][i-1], max(peso[vicino.first][i], maxx[up[vicino.first][i-1]][i-1]));
    	}
        dfs(vicino.first, n, adj);
    }
}

// k-th ancestor
int kth_a(int a, ll k) {
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
    ll k = depth[a] - depth[b];
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

void inizia(int N, int T, int A[], int B[], int C[]) {
	vp adj[N];

	for(int i=0; i<N-1; i++) {
		adj[A[i]].push_back({B[i], C[i]});
		adj[B[i]].push_back({A[i], C[i]});
	}

	log_max = (int)ceil(log2(N))+2;
    dfs(0, -1, adj); 
	return ;
}

int n_lca;
long long int distanza1(int u, int v) {
	n_lca = lca(u, v);
	if(n_lca == u || n_lca == v) return max(depth[u], depth[v]) - min(depth[u], depth[v]);
	return depth[u] + depth[v] - 2*depth[n_lca];
}

ll ress;
long long int distanza2(int u, int v) {
	if(depth[u] < depth[v]) swap(u, v);
	int a = u; int b = v;
	if(a==b) return 0;

	// a è più in basso
    ll k = depth[a] - depth[b];
	ress = 0;
    for(int i=0; i<=log_max; i++) {
        if(k & (1 << i)) {
            // sposto l'1 vs sx di quella potenza di due
            // & returns true se almeno uno dei bit controllati
            // è 1 in entrambi
			ress += peso[a][i];
            a = up[a][i];
            // dato che l'array è inizializzato a 0, tutti gli
            // ancestor a cui non si arriva da un nodo portano al root
        }   
    }

	if(a==b) return ress;

    for(int i=log_max; i>=0; i--) {
        if(up[a][i] == up[b][i]) continue;
		ress += peso[a][i] + peso[b][i];
        a = up[a][i];
        b = up[b][i];
    }

	

    // risalgo dell'ultimo
    return ress + peso[a][0] + peso[b][0];
}

long long int minimo(int u, int v) {
	if(depth[u] < depth[v]) swap(u, v);
	int a = u; int b = v;
	if(a==b) return 0;

	// a è più in basso
    ll k = depth[a] - depth[b];
	ress = LLONG_MAX;
    for(int i=0; i<=log_max; i++) {
        if(k & (1 << i)) {
            // sposto l'1 vs sx di quella potenza di due
            // & returns true se almeno uno dei bit controllati
            // è 1 in entrambi
			ress = min(minn[a][i], ress);
            a = up[a][i];
            // dato che l'array è inizializzato a 0, tutti gli
            // ancestor a cui non si arriva da un nodo portano al root
        }   
    }

	if(a==b) return ress;

    for(int i=log_max; i>=0; i--) {
        if(up[a][i] == up[b][i]) continue;
		ress = min(ress, min(minn[a][i], minn[b][i]));
        a = up[a][i];
        b = up[b][i];
    }

    // risalgo dell'ultimo
    return min(ress, min(minn[a][0], minn[b][0]));
}

long long int massimo(int u, int v) {
	if(depth[u] < depth[v]) swap(u, v);
	int a = u; int b = v;
	if(a==b) return 0;

	// a è più in basso
    ll k = depth[a] - depth[b];
	ress = LLONG_MAX;
    for(int i=0; i<=log_max; i++) {
        if(k & (1 << i)) {
            // sposto l'1 vs sx di quella potenza di due
            // & returns true se almeno uno dei bit controllati
            // è 1 in entrambi
			ress = min(minn[a][i], ress);
            a = up[a][i];
            // dato che l'array è inizializzato a 0, tutti gli
            // ancestor a cui non si arriva da un nodo portano al root
        }   
    }

	if(a==b) return ress;

    for(int i=log_max; i>=0; i--) {
        if(up[a][i] == up[b][i]) continue;
		ress = min(ress, min(minn[a][i], minn[b][i]));
        a = up[a][i];
        b = up[b][i];
    }

    // risalgo dell'ultimo
    return min(ress, min(minn[a][0], minn[b][0]));
}


static FILE *fr, *fw;

// Declaring variables
static int N;
static int Q;
static int T;
static int* A;
static int* B;
static int* C;
static int* U;
static int* V;
static long long int* res;

// Declaring functions
void inizia(int N, int T, int A[], int B[], int C[]);
long long int distanza1(int u, int v);
long long int distanza2(int u, int v);
long long int minimo(int u, int v);
long long int massimo(int u, int v);
void run(int Q, int T, int U[], int V[], long long int res[]);

// Functions ad-hoc for this grader
void run(int Q, int T, int U[], int V[], long long res[]) {
  for (int i = 0; i < Q; i++) {
    if (T == 0)
      res[i] = distanza1(U[i], V[i]);
    else if (T == 1)
      res[i] = distanza2(U[i], V[i]);
    else if (T == 2)
      res[i] = minimo(U[i], V[i]);
    else if (T == 3)
      res[i] = massimo(U[i], V[i]);
    else
      assert(!"Invalid value for T");
  }
}

int main() {
    fr = stdin;
    fw = stdout;

	// Reading input
	fscanf(fr, " %d %d %d", &N, &Q, &T);
	A = (int*)malloc((N-1) * sizeof(int));
	B = (int*)malloc((N-1) * sizeof(int));
	C = (int*)malloc((N-1) * sizeof(int));
	for (int i0 = 0; i0 < N-1; i0++) {
		fscanf(fr, " %d %d %d", &A[i0], &B[i0], &C[i0]);
	}
	U = (int*)malloc((Q) * sizeof(int));
	V = (int*)malloc((Q) * sizeof(int));
	for (int i0 = 0; i0 < Q; i0++) {
		fscanf(fr, " %d %d", &U[i0], &V[i0]);
	}

	// Calling functions
	inizia(N, T, A, B, C);
	res = (long long int*)malloc((Q) * sizeof(long long int));
	run(Q, T, U, V, res);

	// Writing output
	for (int i0 = 0; i0 < Q; i0++) {
		fprintf(fw, "%lld ", res[i0]);
	}
	fprintf(fw, "\n");

    fclose(fr);
    fclose(fw);
    return 0;
}
