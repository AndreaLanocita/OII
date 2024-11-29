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
vi sommasotto;
ll res;
void dfs1(int n, int pre, ll sum, vi adj[]) {
    priority_queue<int> pq;

    for(int vicino: adj[n]) {
        if(vicino==pre) continue;

        dfs1(vicino, n, sum+A[n], adj);
        if(sommasotto[vicino] < 0) pq.push(sommasotto[vicino]);
    }
}

int main() {
//  uncomment the following lines if you want to read/write from files
//  freopen("input.txt", "r", stdin);
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

    sommasotto.resize(N);
    
    printf("%lld\n", sol); // print the result
    return 0;
}
