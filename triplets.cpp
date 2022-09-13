#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define popb pop_back
#define vi vector<int>
#define pi pair<int, int>
#define vp vector<pi>
#define ll long long int
#define pl pair<ll, ll>
#define vl vector<ll>
#define vpl vector<pl>
#define omap map<int, int>
#define umap unordered_map<int, int>
#define pq priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>>

#define MAXN 250000

const int LOG_MAX = 18;
int up[MAXN+1][LOG_MAX];
int max_depth = 0;
int nodo = 0;

void dfs(int n, int precedente, vi adj[], int depth[], vi& candidati) {
	if(n!=0) depth[n] = depth[precedente]+1;
	if(adj[n].size()==1 && n!=0) candidati.pb(n);
	if(depth[n] > max_depth && adj[n].size()==1) {
		max_depth = depth[n];
		nodo = n;
	}

	for(int vicino: adj[n]) {
		// escludo il vicino
		if(vicino==precedente) continue;

		// completo tabella
		up[vicino][0] = n;
		for(int i=1; i<=LOG_MAX; i++) up[vicino][i] = up[up[vicino][i-1]][i-1];
		dfs(vicino, n, adj, depth, candidati);
	}
}

// k-th ancestor
int kth_a(int a, int k) {
    for(int i=0; i<=LOG_MAX; i++) {
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

int lca(int a, int b, int depth[]) {
    // a è più in basso
    if(depth[a] < depth[b]) swap(a, b);
    int k = depth[a] - depth[b];
    a = kth_a(a, k);

    // stesso nodo
    if(a==b) return a;

    for(int i=LOG_MAX; i>=0; i--) {
        if(up[a][i] == up[b][i]) break;
        a = up[a][i];
        b = up[b][i];
    }

    // risalgo dell'ultimo
    return up[a][0];
}

int distanza(int a, int b, int depth[]) {
	int n_lca = lca(a, b, depth);
	if(n_lca == a || n_lca == b) return max(depth[a], depth[b]) - min(depth[a], depth[b]);
	return depth[a] + depth[b] - 2*depth[n_lca];
}

int build(int N, std::vector<int> A, std::vector<int> B) {
	vi adj[N];
	int depth[N];
	vi candidati;
	candidati.reserve(N);
	
	for(int i=0; i<N-1; i++) {
		adj[A[i]].pb(B[i]);
		adj[B[i]].pb(A[i]);
	}

	candidati.pb(0);
	depth[0] = 0;
	dfs(0, -1, adj, depth, candidati);

	ll res = 0; int nodo2 = 0; int tmp = 0;
	for(int candidato: candidati) {
		if(candidato==nodo) continue;
		int distanzaa = distanza(nodo, candidato, depth);
		if(distanzaa > tmp) {
			tmp = distanzaa;
			nodo2 = candidato;
		} 
	}
	res += tmp;
	tmp = 0;
	for(int candidato: candidati) {
		if(candidato==nodo || candidato==nodo2) continue;
		int distanzaa = distanza(nodo, candidato, depth)+distanza(nodo2, candidato, depth);
		if(distanzaa > tmp) {
			tmp = distanzaa;
		} 
	}
	res += tmp;
	return res;
}

int build(int N, std::vector<int> A, std::vector<int> B);

int main() {
	// se vuoi leggere da file decommenta queste due linee
	// assert(freopen("input.txt", "r", stdin));
	// assert(freopen("output.txt", "w", stdout));

	int n;
	assert(std::cin >> n);

	std::vector<int> a(n - 1), b(n - 1);
	for (int i = 0; i < n - 1; ++i) {
		assert(std::cin >> a[i] >> b[i]);
	}

	int ans = build(n, move(a), move(b));
	std::cout << ans << '\n';
}