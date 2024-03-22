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

// kosaraju, fenwick, segment

int bfs(int N, int visitato[], vector<int> adj[], int distanze[]) {
    queue<int> q;
    q.push(0); int n;

    while(!q.empty()) {     // --
        n = q.front();
        q.pop();

        for(int vicino: adj[n]) {
            if(visitato[n] == 1) continue;
            distanze[vicino] = distanze[n]+1;
            q.push(vicino);
            visitato[vicino] = 1;
        }
    }
    return 0;
}

int dijkstra(int N, int visitato[], int distanze[], vector<pair<int, int>> adj[]) {
    distanze[0] = 0;
    pq p; p.push({0, 0}); int n;
    for(int i=0; i<N; i++) {
        while(!p.empty()) {
            n = p.top().second;
            if(visitato[n] == 0) break;
            p.pop();
        }
        if(p.empty()) break;
        p.pop();

        for(pair<int, int> vicino: adj[n]) {
            if(visitato[vicino.second] == 1) continue;
            if(distanze[vicino.second] > distanze[n]+vicino.first) {
                distanze[vicino.second] = distanze[n]+vicino.first;
                p.push({distanze[vicino.second], vicino.second});
            }
        }
    }
}

// init, unionn, find, 
#define MAXN 100
int sizee[MAXN];
int e[MAXN];
int init(int n) {
    sizee[n] = 0;   // size è 0
    e[n] = n;
}

int find(int a) {
    if(e[a] == a) return a;
    return e[a] = find(a);
}

void unionn(int a, int b) {
    if(find(a) == find(b)) return ;
    a = find(a);
    b = find(b);
    if(sizee[a] < sizee[b]) {
        e[a] = b;
        sizee[a] += sizee[b];
    } else {
        e[b] = a;
        sizee[b] += sizee[a];
    }
}

int kruskal(int N, vector<pair<int, pair<int, int>>> lis) {
    sort(lis.begin(), lis.end());

    // init

    for(pair<int, pair<int, int>> el: lis) {
        if(find(el.second.first) == find(el.second.second)) continue;
        // union e aggiungo sol
    }
}

vector<int> rt;

int dfs(int n, vector<int> adj[], int visitato[]) {
    visitato[n] = 1;
    for(int vicino: adj[n]) {
        if(visitato[n] == 1) continue;
        dfs(vicino, adj, visitato);
    }
    rt.push_back(n);
}

int dfs1(int n, int counter, vector<int> adj[], int visitato[], vector<int> componenti[]) {
    visitato[n] = 1;
    componenti[counter].push_back(n);

    for(int vicino: adj[])
}

int ksoaraju(int N, vector<int> adj[], vector<int> adj2[]) {
    int visitato[N] = { };
    for(int i=0; i<N; i++) {
        if(visitato[i] == 1) continue;
        dfs(i, adj, visitato);
    }

    for(int i=0; i<N; i++) visitato[i] = 0;
    int nodo_cmp[N];
    vector<int> componenti[N];
    int n_componenti = 0;
    for(int i=N-1; i>=0; i++) {
        if(visitato[rt[i]] == 1) continue;
        dfs1()
        n_componenti++;
    }

}   

int real_size = 1;
vector<int> tree;
vector<int> lazy;
int st(int N, vector<int> &A) { // 1 based
    while(real_size<N) real_size *= 2;
    tree.assign(2*real_size, 0);   lazy.assign(2*real_size, -INFINITY);
    for(int i=real_size; i<A.size(); i++) tree[i] = A[i];
    for(int i=real_size-1; i>0; i--) tree[i] = tree[2*i] + tree[2*i+1];
}

int range_sum(int u, int l, int r, int x, int y) {
    // completamente escluso
    if(r<=x || l>=y) return 0;
    // completamente incluso
    if(l>=x && r<=y) return tree[u];
    return (
        range_sum(2*u, l, (l+r)/2, x, y) + range_sum(2*u+1, (l+r)/2, r, x, y)
    );
}

int point_set(int x, int index) {
    index += real_size;
    tree[index] = x;
    while(index > 1) tree[index/2] = tree[2*(index/2)] * tree[2*(index/2)+1];
}

int range_set(int u, int l, int r, int x, int y, int val) {
    // completamente escluso
    if(r<=x || l>=y) return 0;
    // completamente incluso
    if(l>=x && r<=y) {
        tree[u] = val*(r-l);
        if(2*u+1 < 2*real_size) {
            lazy[2*u] = val;
            lazy[2*u+1] = val;
        } 
    }

    range_set(2*u, l, (l+r)/2, x, y, val);
    range_set(2*u+1, (l+r)/2, r, x, y, val);
    tree[u] = tree[2*u+1] + tree[2*u];
    
    return 0;
}

int main() {

    return 0;
}