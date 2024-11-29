// NOTE: it is recommended to use this even if you don't understand the following code.

#include <bits/stdc++.h>

using namespace std;
int visitato[1000][1000];
long long res = 0;
long long MOD = 10e9+7;

int dfs(int n, int pre, vector<pair<int, int>> adj[], int mcurrent) {
    for(pair<int, int> nextt: adj[n]) {
        if(visitato[n][nextt.first]!=0 && pre !=-1) visitato[pre][n] += (2*visitato[n][nextt.first]+1);
        if(visitato[n][nextt.first]!=0 || (mcurrent + 1 != nextt.second && mcurrent != -1)) continue;

        int temp;
        if(pre!=-1)temp = dfs(nextt.first, n, adj, mcurrent+1) % MOD;
        else temp = dfs(nextt.first, n, adj, nextt.second) % MOD;
        
        if(pre!=-1)visitato[pre][n] = (visitato[pre][n] + ((2*temp+1)%MOD))%MOD;
        else res = (res + ((2*temp+1)%MOD)) % MOD;
    }

    if(pre==-1) return 0;   //succede solo all'inizio
    return visitato[pre][n]%MOD;
}

int main() {
    // uncomment the following lines if you want to read/write from files
    // ifstream cin("input.txt");
    // ofstream cout("output.txt");

    int N, M;
    cin >> N >> M;
    
    vector<int> A(M), B(M), C(M);
    vector<pair<int, int>> adj[N];  
    for (int i = 0; i < M; i++) {
        cin >> A[i] >> B[i] >> C[i];
        adj[A[i]].push_back({B[i], C[i]});
        adj[B[i]].push_back({A[i], C[i]});
    }

    for(int i=1; i<N; i++) dfs(i, -1, adj, -1);

    cout << res+M << endl; // print the result
    return 0;
}
