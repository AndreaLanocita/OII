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

long long costruisci(int N, int M, vector<long long>& H, vector<int>& A, vector<int>& B, vector<int>& C) {
    vpl adj[N];
    for(int i=0; i<M; i++) adj[A[i]].pb({B[i], C[i]});

    ll distanze[N]; int visitato[N] = { };
    for(int i=0; i<N; i++) distanze[i] = H[i];

    pq p;
    for(int i=0; i<N; i++) p.push({H[i], i});

    ll res = 0; int n;
    for(int i=0; i<N; i++) {
        while(!p.empty()) {
            n = p.top().second;
            if(visitato[n]==0 || distanze[n] == p.top().first) break;
            p.pop();
        }
        if(p.empty()) break;
        p.pop();

        visitato[n] = 1;
        res += distanze[n];
        for(pl vicino: adj[n]) {
            if(visitato[vicino.first] == 1) continue;
            if(distanze[vicino.first] > distanze[n] + vicino.second) {
                distanze[vicino.first] = distanze[n] + vicino.second;
                p.push({distanze[vicino.first], vicino.first});
            }
        }
    }

    return res;
}

long long costruisci(int N, int M, vector<long long>& H, vector<int>& A, vector<int>& B, vector<int>& C);

int main() {
    // Input da file:
    freopen("input.txt", "r", stdin);

    // Output su file:
    // freopen("output.txt", "w", stdout);

    int n, m;
    cin >> n >> m;
    vector<long long> h(n);
    vector<int> a(m), b(m), c(m);

    for(size_t i = 0; i < n; i++) {
        cin >> h[i];
    }
    for(size_t j = 0; j < m; j++) {
        cin >> a[j] >> b[j] >> c[j];
    }
    cout << costruisci(n, m, h, a, b, c) << endl;
    return 0;
}