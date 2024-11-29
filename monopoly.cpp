#include <bits/stdc++.h> 

using namespace std;

#define vi vector<int>
#define ll long long int
#define pi pair<ll, int>
#define vp vector<pi>
#define omap map<int, int>
#define umap unordered_map<int, int>

#define MAXX 1005
#define INF INT_MAX

pi sol[MAXX][MAXX][4];
vector<ll> V;

void ricorsiva(ll n, ll k, ll l, ll N, ll K) {
    // caso base
    if(k==0) {
        if(n!=0) sol[n][k][l] = {-INF, 0}; // non sono sulla casella iniziale
        else sol[n][k][l] = {0, 0};
        return ;
    }

    // ho il res
    if(sol[k][n][l].first != -INF) return ;

    // calcolo
    for(int i=2; i<13; i+=2) {
        // vado un turno indietro, ho di nuovo 3 lanci
        ricorsiva((1000*N+n-i)%N, k-1, 3, N, K);

        if(l>0) ricorsiva((1000*N+n-i)%N, k, l-1, N, K);

        // ho usato un doppio lancio
        if(l>0) {
            if(sol[n][k][l].first < sol[k][(1000*N+n-i)%N][l-1].first + V[n]) {
                sol[k][n][l].first = sol[k][(1000*N+n-i)%N][l-1].first + V[n];
                if(i==2 || i==12) sol[k][n][l].second = 1;  // il prossimo deve essere per forza uno dei doppi lanci
                else sol[k][n][l].second = 0;
            }
        } 

        // vado un turno indietro 
        ll temp = sol[k-1][(1000*N+n-i)%N][3].first + V[n];
        if(sol[k-1][n-i][l].second == 0) {
            if(sol[k][n][l].first < temp) {
                sol[k][n][l].first = temp;
                if(i==2 || i==12) sol[k][n][l].second = 1;  // il prossimo deve essere per forza uno dei doppi lanci
                else sol[k][n][l].second = 0;
            }
        } 
    }

    for(int i=1; i<13; i+=2) {
        // vado un turno indietro, ho di nuovo 3 lanci
        ricorsiva((1000*N+n-i)%N, k-1, 3, N, K);

        // vado un turno indietro 
        ll temp = sol[k-1][(1000*N+n-i)%N][3].first + V[n];
        if(sol[k-1][n-i][l].second == 0) {
            if(sol[k][n][l].first < temp) {
                sol[k][n][l].first = temp;
                sol[k][n][l].second = 0;
            }
        } 
    }

    return ;
}

int main() {
    ll N, K;
    cin >> N >> K;

    V.resize(N);
    for(int i=0; i<N; i++) cin >> V[i];

    // inizializzo
    for(int i=0; i<=K; i++) {
        for(int j=0; j<=N; j++) {
            sol[i][j][0].first = -INF; sol[i][j][0].second = 0;
            sol[i][j][1].first = -INF; sol[i][j][1].second = 0;
            sol[i][j][2].first = -INF; sol[i][j][2].second = 0;
            sol[i][j][3].first = -INF; sol[i][j][3].second = 0;
        }
    }

    ll res = -INF;
    for(int i=0; i<N; i++) {
        ricorsiva(i, K, 3, N, K);
        res = max(res, sol[K][N][3].first);
    } 
    cout << res;

    return 0;
}