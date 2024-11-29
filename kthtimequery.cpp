#include <bits/stdc++.h> 

using namespace std;

#define vi vector<int>
#define pi pair<int, int>
#define vp vector<pi>
#define ll long long int
#define omap map<int, int>
#define umap unordered_map<int, int>

int main() {
    int N, Q;
    cin >> N >> Q;
    vi v(N);
    map<int, vi> m;
    for(int i=0; i<N; i++) {
        cin >> v[i];
        m[v[i]].push_back(i+1);
    }

    for(int i=0; i<Q; i++) {
        int x, k;
        cin >> x >> k;
        
        if(m.find(x) == m.end() || m[x].size()<k) {
            cout << -1 << endl;
            continue;
        }
        cout << m[x][k-1] << endl;
    }
    return 0;
}