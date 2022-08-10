#include <bits/stdc++.h>

using namespace std;

vector<int> res_v;
int finale;

int dfs(int n, int precedente, int visitato[], vector<pair<int, int>> adj[]) {
    visitato[n] = 1;
    int res;

    for(pair<int, int> vicino: adj[n]) {
        // trovato un ciclo
        if(visitato[vicino.first] == 1 && vicino.first != precedente && vicino.second == 1) {
            finale = vicino.first;
            res_v.push_back(n);
            return 0;
        } 
        if(visitato[vicino.first] == 0 && vicino.second == 1) {
            res = dfs(vicino.first, n, visitato, adj);
            if(res == 0) {
                res_v.push_back(n);
                if(n == finale) return -1;
                return 0;
            } 
            if(res == -1) return -1;
        }
    }
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int N, M, tmp1, tmp2, tmp3;
    
    cin >> N >> M;
    vector<pair<int, int>> adj[N+1];
    int visitato[N+1] = { };

    for(int i=0; i<M; i++) {
        cin >> tmp1 >> tmp2 >> tmp3;
        adj[tmp1].push_back({tmp2, tmp3});
        adj[tmp2].push_back({tmp1, tmp3});
    }

    for(int i=1; i<N; i++) {
        if(visitato[i] == 0) {
            dfs(i, -1, visitato, adj);
            if(res_v.size() != 0) break;
        } 
    }

    cout << res_v.size() << endl;
    for(int i=res_v.size()-1; i>=0; i--) cout << res_v[i] << " ";
    return 0;
}