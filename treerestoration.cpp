#include <bits/stdc++.h> 

using namespace std;

#define pi pair<int, int>
#define vp vector<pi>
#define ll long long int
#define omap map<int, int>
#define umap unordered_map<int, int>
#define vi vector<int>

int vertici = 0;
int archi = 0;
void dfs_archi(int n, int visitato[], vi adj[]) {
    visitato[n] = 1;
    vertici++;
    for(int vicini: adj[n]) {
        archi++; 
        if(!visitato[vicini]) dfs_archi(vicini, visitato, adj);
    }

    return ;
}

int main() {
    int N, M;
    cin >> N >> M;
    ll Ca, Ct;
    cin >> Ca >> Ct;

    vi adj[N+1];
    for(int i=0; i<M; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    // conto comp. connessew
    ll counter = 0;
    int visitato[N+1] = {};
    vector<pair<int, int>> archicomp;   // n. vertici, n.archi
    for(int i=1; i<=N; i++) {
        if(visitato[i] == 1) continue;
        vertici = 0;
        archi = 0;
        dfs_archi(i, visitato, adj);
        archicomp.push_back({vertici, archi/2});
        counter++;
    }
    ll res = 0;
    if(counter != 1) {
        res += (Ca*(counter-1));
    }
    for(pair<int, int> p: archicomp) {
        res += (Ct * (((ll) p.second) - ((ll) p.first-1)));
    }
    cout << res;
    return 0;
}