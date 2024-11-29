#include <bits/stdc++.h> 

using namespace std;

#define vi vector<int>
#define pi pair<int, int>
#define vp vector<pi>
#define ll long long int
#define omap map<int, int>
#define umap unordered_map<int, int>
#define INF INT_MAX

// da sistemare salvando l'intervallo in cui ho il potere nella deque
// e cambiandolo ogni volta che mi muovo ad un adiacente

int main() {
    int H, W;
    cin >> H >> W;
    int M[H][W];
    for(int i=0; i<H; i++) {
        for(int j=0; j<W; j++) {
            char temp;
            cin >> temp;
            if(temp=='.') M[i][j] = 1;
            else M[i][j] = 0;
        }
    }

    int N=W*H;
    vp adj[N];
    for(int i=0; i<H; i++) {
        for(int j=0; j<W; j++) {
            if(i!=H-1) {
                if(M[i+1][j]) adj[H*i+j].push_back({H*(i+1)+j, 0});
                else adj[H*i+j].push_back({H*(i+1)+j, 1});
            } 
            if(i!=0) {
                if(M[i-1][j]) adj[H*i+j].push_back({H*(i-1)+j, 0});
                else adj[H*i+j].push_back({H*(i-1)+j, 1});
            }
            if(j!=W-1) {
                if(M[i][j+1]) adj[H*i+j].push_back({H*i+j+1, 0});
                else adj[H*i+j].push_back({H*i+j+1, 1});
            } 
            if(j!=0) {
                if(M[i][j-1]) adj[H*i+j].push_back({H*i+j-1, 0});
                else adj[H*i+j].push_back({H*i+j-1, 1});
            }
        }
    }

    int d[N];
    for(int i=0; i<N; i++) d[i] = INF;
    d[0] = 0;
    deque<pair<int, int>> dq;    // d, v, potenza
    // se spendo uno mi segno 1 in potere, poi ritorno a zero a quello dopo
    dq.push_back({0, 0});
    while(!dq.empty()) {
        int n = dq.front().first;
        int potere = dq.front().second;
        dq.pop_front();
        for(pair<int, int> e: adj[n]) {
            int w = e.second;
            int u = e.first;
            if(potere) w=0;
            if(d[n]+w<d[u]) {
                d[u] = d[n]+w;
                if(w==1) dq.push_back({u, 1});
                else dq.push_front({u, 0});
            }
        }
    }

    cout << d[N-1];
    return 0;
}