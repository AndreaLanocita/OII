#include <bits/stdc++.h> 

using namespace std;

#define vi vector<int>
#define pi pair<int, int>
#define vp vector<pi>
#define ll long long int
#define omap map<int, int>
#define umap unordered_map<int, int>

int dfs(int n, vector<int> adj[], int visitato[]) {
    visitato[n] = 1;
	for(int vicino: adj[n]) {
		if(visitato[vicino] == 0) dfs(vicino, adj, visitato);
	}
}

int main() {
    int N;
    cin >> N;
    vector<int> adj[N];
    int visitato[N] = { };

    int first, second;
    for(int i=0; i<N; i++) {
        cin >> first >> second;
        adj[first].push_back(second);
        adj[second].push_back(first);
    }

    int res = 0;
    for(int i=0; i<N; i++) {
        if(visitato[i] == 0) dfs(i, adj, visitato);
        res++;
    }

    return 0;
}