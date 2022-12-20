#include <bits/stdc++.h> 

using namespace std;

#define vi vector<int>
#define pi pair<int, int>
#define vp vector<pi>
#define ll long long int
#define omap map<int, int>
#define umap unordered_map<int, int>

void dfs1(int n, vector<int> adj[], int h[], int pre) {
    if(n!=0) h[n] = h[pre]+1;
	for(int vicino: adj[n]) {
		if(vicino != pre) dfs1(vicino, adj, h, n);
	}
    return ;
}

vector<int> path;
int dfs(int n, vector<int> adj[], int h[], int pre, int target) {
    if(n==target) {
        path.push_back(n);
        return 1;
    }

	for(int vicino: adj[n]) {
		if(vicino != pre) {
            if(dfs(vicino, adj, h, n, target)==1) {
                path.push_back(n);
            }
        }
	}
    return 0;
}

int main() {
    int N, a, b;
    cin >> N >> a >> b;
    vector<int> adj[N];
    int h[N];

    int first, second;
    for(int i=0; i<N-1; i++) {
        cin >> first >> second;
        adj[first].push_back(second);
        adj[second].push_back(first);
    }
    
    h[0] = 0;
    dfs1(0, adj, h, -1);

    dfs(a, adj, h, -1, b);

    int lca, max_h = 0;
    for(int nodo: path) {
        if(h[nodo] > max_h) {
            lca = nodo;
            max_h = h[nodo];
        }
    }

    cout << lca;

    return 0;
}