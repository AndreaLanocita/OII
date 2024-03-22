#include <bits/stdc++.h> 

using namespace std;

#define vi vector<int>
#define pi pair<int, int>
#define vp vector<pi>
#define ll long long int
#define omap map<int, int>
#define umap unordered_map<int, int>

int check(int a, int b, vi adj[], int N, int K) {
    int aus[N+1] = { };
    int counter = 0;
    for(int i: adj[a]) {
        if(i==b) continue;
        aus[i] = 1;
    }
    for(int i: adj[b]) {
        if(i==a) continue;
        if(aus[i] == 1) counter++;
    }
    if(counter >= K) return 1;
    return 0;
}

int main() {
    int N, M, K;
    cin >> N >> M >> K;
    vector<int> adj[N+1];
    for(int i=0; i<M; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    // selezioniamo il primo pivot
    for(int i=1; i<N+1; i++) {
        // selezioniamo il secondo tra gli amici dei suoi amici
        for(int j: adj[i]) {
            // possibile pivot, controlliamo se lo sono
            for(int h: adj[j]) {
                // devono avere k amici amici in comune
                if(check(i, h, adj, N, K)) {
                    cout << "YES";
                    return 0;
                }
            }
        }
    }
    cout << "NO";
    return 0;
}