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

int n1 = 0, distanza1 = 0;
int n2 = 0;

void dfs(int n, int pre, vi adj[], int distanza) {
	if(distanza > distanza1) {
		n1 = n; 
		distanza1 = distanza;
	}

	for(int vicino: adj[n]) {
		if(vicino==pre) continue;
		dfs(vicino, n, adj, distanza+1);
	}
	return ;
}

void dfs1(int n, int pre, vi adj[], int distanza, int distanze1[]) {
	distanze1[n] = distanza;
	if(distanza > distanza1) {
		n2 = n; 
		distanza1 = distanza;
	}

	for(int vicino: adj[n]) {
		if(vicino==pre) continue;
		dfs1(vicino, n, adj, distanza+1, distanze1);
	}
	return ;
}

void dfs2(int n, int pre, vi adj[], int distanza, int distanze2[]) {
	distanze2[n] = distanza;

	for(int vicino: adj[n]) {
		if(vicino==pre) continue;
		dfs2(vicino, n, adj, distanza+1, distanze2);
	}
	return ;
}

int build(int N, std::vector<int> A, std::vector<int> B) {
	vi adj[N];
	int distanze1[N], distanze2[N];
	
	for(int i=0; i<N-1; i++) {
		adj[A[i]].pb(B[i]);
		adj[B[i]].pb(A[i]);
	}

	dfs(0, -1, adj, 0);
	dfs1(n1, -1, adj, 0, distanze1);
	dfs2(n2, -1, adj, 0, distanze2);
	int res = 0;
	for(int i=0; i<N; i++) {
		if(i==n1 || i==n1) continue;
		if(distanze1[i]+distanze2[i] > res) res = distanze1[i]+distanze2[i];
	}

	return res+distanza1;
}

int main() {
	// se vuoi leggere da file decommenta queste due linee
	assert(freopen("input.txt", "r", stdin));
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