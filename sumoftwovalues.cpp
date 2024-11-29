#include <bits/stdc++.h> 

using namespace std;

#define vi vector<int>
#define pi pair<int, int>
#define vp vector<pi>
#define ll long long int
#define omap map<int, int>
#define umap unordered_map<int, int>

int trova(int x, vi &v, int N, int K) {
    for(int i=0; i<N; i++) {
        if(i==x) continue;
        if(v[i] == K-v[x]) return i;
    }
        

    return -1;
}

int main() {
    int N, K;
    cin >> N >> K;
    map<int, int> controllo;
    vi v(N);
    for(int i=0; i<N; i++) {
        cin >> v[i];
        controllo[v[i]] = 1;
    }

    for(int i=0; i<N; i++) {
        if(controllo.find(K-v[i]) != controllo.end()) {
            int j = trova(i, v, N, K)+1;
            if(j==0) continue;
            cout << i+1 << " " << j;
            return 0;
        }
    }

    cout << "IMPOSSIBLE";
    return 0;
}