#include <bits/stdc++.h> 

using namespace std;

#define vi vector<int>
#define pi pair<int, int>
#define vp vector<pi>
#define ll long long int
#define omap map<int, int>
#define umap unordered_map<int, int>

int sizee, MAXN;
void dfs(int n, int pre, vi adj[], vi &tree, int tsize[]) {
    tree.push_back(n);
    
    for(int vicino: adj[n]) {
        if(vicino==pre) continue;
        dfs(vicino, n, adj, tree, tsize);
        tsize[n] += tsize[vicino]+ 1;
    }

    return ;
}

void add(int index, int value, vi &fenwick) {
    while(index < MAXN+1) {
        fenwick[index] += value;
        index += index & (-index);
    }
    return ;
}

int summ;
int range_sum(int index, vi &fenwick) {
    summ = 0;
    while(index>0) {
        summ += fenwick[index];
        index -= index & (-index);
    }
    return summ;
}

int e, s;
void range_update(vi &fenwick, int cod[], int sizee[]) {
    cin >> e >> s;
    add(cod[e]+1, s, fenwick);
    add(cod[e]+sizee[e]+1, -s, fenwick);
}

void point_sum(vi &fenwick, int cod[], int wages[]) {
    cin >> e;
    cout << (range_sum(cod[e], fenwick) + wages[e]) << "\n";
    return ;
}

int main() {
    cin.tie(0); ios::sync_with_stdio(false);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int N, M, tmp; 
    cin >> N >> M >> tmp;
    MAXN = N;
    vi adj[N+1]; int wages[N+1]; int cod[N+1], tsize[N+1] = { }; vi tree, fenwick;

    wages[1] = tmp; 
    for(int i=2; i<N+1; i++) {	
        cin >> wages[i] >> tmp;
        adj[tmp].push_back(i);
    }

    tree.push_back(0);
    dfs(1, -1, adj, tree, tsize);

    // scorro array e segno index in cod
    for(int i=1; i<tree.size(); i++) cod[tree[i]] = i;

    // fenwick
    fenwick.assign(N+1, 0);

    // queries
    char q;
    for(int i=0; i<M; i++) {
        cin >> q;
        if(q=='p') range_update(fenwick, cod, tsize);
        if(q=='u') point_sum(fenwick, cod, wages);
    }

    return 0;
}