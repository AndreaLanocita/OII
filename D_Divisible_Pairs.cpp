#include <bits/stdc++.h> 

using namespace std;

#define vi vector<int>
#define pi pair<int, int>
#define vp vector<pi>
#define ll long long int
#define omap map<int, int>
#define umap unordered_map<int, int>

int solve(int n, int x, int y, int v[]) {
    vector<int> moduli[n];
    vector<int> moduli_indice[n];
    for(int i=0; i<n; i++) {
        moduli[v[i]%x].push_back(v[i]);
        moduli_indice[v[i]%x].push_back(i);

    } 
    
    int res = 0;
    for(int i=0; i<n; i++) {
        int mod_richiesto = x-(v[i]%x);
        auto a = lower_bound(moduli_indice[mod_richiesto].begin(), moduli_indice[mod_richiesto].end(), i);
        auto b = moduli_indice[mod_richiesto].begin();
        int indice = a-b;
        for(int j=indice; j++; j<moduli[mod_richiesto].size()) {
            if((abs((v[i]-moduli[mod_richiesto][j]))%y)==0) res++;
        }
    }
    return res;
}

int main() {
    int t; cin >> t;
    for(int i=0; i<t; i++) {
        int n, x, y; cin >> n >> x >> y;
        int v[n];
        for(int j=0; j<n; j++) cin >> v[j];
        cout << solve(n, x, y, v) << endl;
    }
    return 0;
}