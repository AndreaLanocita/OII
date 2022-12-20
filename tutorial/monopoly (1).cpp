#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF 1000
#define MAXK 1000
#define MAXN 1000
ll dp[MAXK+1][MAXN][3];
bool visited[MAXK+1][MAXN][3];

// input data
int N, K;
vector<int> T;

ll top_down(int k, int n, int l)
{
    if (visited[k][n][l]) return dp[k][n][l];
    visited[k][n][l] = true;
    if (k == 0){
        if (n == 0) return 0;
        return -INF;
    }
    if (l == 0){
        ll massi = -INF;
        for (int i = 2; i<=12; i++){
            massi = max(massi, top_down(k-1, ((N-i)%N + N)%N, 2) + T[((N-i)%N + N)%N]);
        }
        dp[k][n][l] = massi;
        return massi;
    }
    ll massi = -INF;
        for (int i = 3; i<12; i++){
            massi = max(massi, top_down(k-1, ((N-i)%N + N)%N, 2) + T[((N-i)%N + N)%N]);
        }
        for (int i = 2; i<=12; i+=2){
            massi = max(massi, top_down(k, ((N-i)%N + N)%N, l-1) + T[((N-i)%N + N)%N]);
        }
    dp[k][n][l] = massi;
    return massi;

}



int main() {

    cin >> N >> K;
    T.resize(N);
    for (int i = 0; i < N; i++) { cin >> T[i]; }
    for (int k = 0; k<=K; k++){
        for (int n= 0; n<N; n++){
            for (int l=0; l<3; l++) visited[k][n][l] = false;
        }
    }
    ll a = -INF;
    for (int i = 0; i<N; i++) a = max(a, top_down(K, i, 2));
    cout << a;
    
    return 0;
}


int bottom_up(int N, int K, vector<int>& V) {
    pair<int, int> sol[N][K][3];
    sol[0][0][0] = 0;
    stack<pair<int, int>> s;  // casella, doppio lancio
    s.push({0, 0});

    int n, solo_doppio;
    n = s.top().first;
    solo_doppio = s.top().second();
    s.pop();

    
    
}