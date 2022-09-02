#include <bits/stdc++.h>

using namespace std;

int cb = 0;
int caso_base(int n, vector<pair<int, int>> adj[], int visitato[]) {
    visitato[n] = 1;
    for(pair<int, int> vicino: adj[n]) {
        if(visitato[vicino.first] == 1) continue;
        // contro senso
        if(vicino.second == -1) cb++;
        caso_base(vicino.first, adj, visitato);
    }

    return 0;
}

int dp(int n, vector<pair<int, int>> adj[], vector<pair<int, int>> &sol, int visitato[]) {
    visitato[n] = 1;
    for(pair<int, int> vicino: adj[n]) {
        if(visitato[vicino.first] == 1) continue;
        if(vicino.second == -1) sol[vicino.first] = {sol[n].first - 1, vicino.first};
        else sol[vicino.first] = {sol[n].first + 1, vicino.first};
        dp(vicino.first, adj, sol, visitato);
    }

    return 0;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int N, tmp1, tmp2;
    cin >> N;

    vector<pair<int, int>> adj[N+1];
    int visitato[N+1] = { };
    for(int i=0; i<N-1; i++) {
        cin >> tmp1 >> tmp2;
        adj[tmp1].push_back({tmp2, 1});
        adj[tmp2].push_back({tmp1, -1});
    }

    vector<pair<int, int>> sol(N+1);    // sol, indice

    // calcolo il caso base
    caso_base(1, adj, visitato);
    sol[1] = {cb, 1};
    int visitatoo[N+1] = { };
    dp(1, adj, sol, visitatoo);

    sort(sol.begin(), sol.end());
    int res = sol[1].first;
    cout << res << "\n";
    for(int i=1; sol[i].first == res && i<N+1; i++) {
        cout << sol[i].second << " "; 
    }
    return 0;
}