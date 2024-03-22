#include <bits/stdc++.h> 

using namespace std;

#define vi vector<int>
#define pi pair<int, int>
#define vp vector<pi>
#define ll long long int
#define omap map<int, int>
#define umap unordered_map<int, int>

string res;

int check(int n, int inizio, int fine, vi adj[], char c[]) {

}

int main() {
    int N, M;
    cin >> N >> M;
    char c[N];
    for(int i=0; i<N; i++) {    
        cin >> c[i];
    }
    vi adj[N];

    for(int i=0; i<M; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int Q;
    cin >> Q;
    for(int i=0; i<Q; i++) {
        if(i!=0) {} res.clear();
        int a, b;
        cin >> a >> b;
        check(0, a, b, adj, c);
    }

    return 0;
}