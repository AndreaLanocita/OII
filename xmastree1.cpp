/*
 * This template is valid both in C and in C++,
 * so you can expand it with code from both languages.
 * NOTE: it is recommended to use this even if you don't
 * understand the following code.
 */

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

// constraints
#define MAXN 200000

// input data
int N, i;
int A[MAXN];
vi stato;

ll res = 0;
int dfs1(int n, int pre, vi adj[]) {
    if(stato[n] == 0) res += A[n];

    for(int vicino: adj[n]) {
        if(vicino==pre) continue;
        dfs1(vicino, n, adj);
    }
    return 0;
}

int dfs(int n, int pre, int somma, vi adj[]) {
    int flag = 0;

    // è la foglia, controllo somma (e se è spento) e decido che fare
    if(adj[n].size() == 1 && n!=0) {
        // quello sopra è acceso, se la somma è negativa spengo
        if(stato[pre] == 0 && somma + A[n] < 0) {
            stato[n] = -1;
            return -1;
        }
        // quello sopra è spento, se il valore della foglia è minore 
        // della somma spengo questa (e accendo sopra)
        if(stato[pre] == -1 && A[n] < somma) {
            stato[n] = -1;
            return -1;
        }
        return 0;
    }

    for(int vicino: adj[n]) {
        if(vicino==pre) continue;
        if(dfs(vicino, n, somma+A[n], adj) == -1) {
            // cambia da come era prima
            flag++;
            if(stato[n] == 0) stato[n] = -1;
            else stato[n] = 0;
        } 
    }
    return -(flag%2);
}

int main() {
//  uncomment the following lines if you want to read/write from files
    freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    assert(1 == scanf("%d", &N));
    vi adj[N];
    for(i=0; i<N-1; i++) {
        int a, b;
        assert(2 == scanf("%d %d", &a, &b));
        
        adj[a].pb(b);
        adj[b].pb(a);
    }
    for(i=0; i<N; i++) {
        assert(1 == scanf("%d", &A[i]));
    }
    stato.assign(N, 0);
    dfs(0, -1, 0, adj);
    dfs1(0, -1, adj);
    printf("%lld\n", res); // print the result
    return 0;
}
