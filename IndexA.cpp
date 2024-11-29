#include <bits/stdc++.h> 

using namespace std;

#define vi vector<ll>
#define pi pair<int, int>
#define vp vector<pi>
#define ll long long int
#define omap map<int, int>
#define umap unordered_map<int, int>
#define MAXN 2000
#define MAXM 2000

ll res[MAXN][MAXM];
ll solve(ll index, ll counter, vi &v) {
    if(counter==-1) return 0;
    if(res[index][counter]!=LLONG_MIN) return res[index][counter];

    ll parziale=LLONG_MIN;
    parziale = max(parziale, solve(index-1, counter-1, v)+((ll) v[index])*((ll)counter+1));
    if(index-1>counter-1) parziale = max(parziale, solve(index-1, counter, v));

    return res[index][counter] = parziale;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int M, N;
    cin >> N >> M;
    vi v(N);
    for(int i=0; i<N; i++) {
        cin >> v[i];
        for(int j=0; j<M; j++) res[i][j]=LLONG_MIN;
    }
    cout << solve(N-1, M-1, v);

    // res[0][0] = 0;
    // for(ll index=0; index<N; index++) {
    //     for(ll counter=0; counter<=index; counter++) {
    //         // lo prendo
    //         if(counter>0) res[index][counter] = max(res[index][counter], res[index-1][counter-1]+ ((ll) v[index])*((ll)counter+1));
    //         else res[index][counter] = ((ll) v[index])*((ll)counter+1);
    //         // non lo prendo
    //         res[index][counter] = max(res[index][counter], res[index-1][counter]);
    //     }
    // }
    // cout << res[N-1][M-1];
    return 0;
}