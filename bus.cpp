#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define vi vector<int>
#define pi pair<int, int>
#define pl pair<ll, int>
#define pq priority_queue<pl, vector<pl>, greater<pl>>
#define vpi vector<pi>

#define MAXK 350000

ll fine;

struct tri {
    ll arrivo, id, pos;
    tri() : arrivo(0), id(0), pos(0) {};
    tri(ll a, ll b, ll c) : arrivo(a), id(b), pos(c) {};
};

int dfs(ll n, int visitato[], vector<tri> adj[], ll counter, ll currentid, ll pos_fermata, ll maxcounter) {
    visitato[n] = 1;
    if(n==fine-1 && counter <= maxcounter) return 1;

    for(tri vicino: adj[n]) {
        if(visitato[vicino.arrivo] == 1) continue;

        if(currentid==-1) {
            // funziona
            if(dfs(vicino.arrivo, visitato, adj, 0, vicino.id, vicino.pos, maxcounter)==1) return 1;
        }
        // cmabio linea
        else if(currentid != vicino.id || vicino.pos < pos_fermata) {
            if(counter+1 > maxcounter) continue;
            if(dfs(vicino.arrivo, visitato, adj, counter+1, vicino.id, vicino.pos, maxcounter)==1) return 1;
        } 
        // stessa linea
        else {
            if(dfs(vicino.arrivo, visitato, adj, counter, currentid, vicino.pos, maxcounter)==1) return 1;
        } 
    }
    return -1;
}

int dfs1(ll n, int visitato[], vector<tri> adj[]) {
    visitato[n] = 1;
    if(n==fine-1) return 1;

    for(tri vicino: adj[n]) {
        if(visitato[vicino.arrivo] == 1) continue;
        if(dfs1(vicino.arrivo, visitato, adj)==1) return 1;
    }

    return -1;
}

int pianifica(int N, int L, vector<vector<int>> F) {
    vector<tri> adj[N]; // arrivo, id
    ll precedente;
    int visitato[N] = { };

    for(int i=0; i<L; i++) {
        precedente = F[i][0];
        for(int j=1; j<F[i].size(); j++) {
            adj[precedente].push_back({F[i][j], i, j});
            precedente = F[i][j];
        }
    }
    fine = N;

    // è possibile da 1 raggiungere in qualche modo N-1?
    if(dfs1(0, visitato, adj)==-1) return -1;
    for(int i=0; i<N; i++) visitato[i] = 0;

    // binary search sulla dfs
    ll l = 0, r = N+1000, mid;
    while(l<r) {
        mid = (l+r)/2;
        // funziona, abbasso
        if(dfs(0, visitato, adj, 0, -1, 0, mid) == 1) r = mid;
        else l = mid+1;

        for(int i=0; i<N; i++) visitato[i] = 0;
    }

    return r;
}

// int main() {
//     ios_base::sync_with_stdio(false);
//     // se preferisci leggere e scrivere da file ti basta decommentare le seguenti due righe:
//     // freopen("bus.input1.txt", "r", stdin);
//     // freopen("output.txt", "w", stdout);

//     int N, L;
//     cin >> N >> L;

//     vector<vector<int>> F(L);
//     for (int i = 0; i < L; i++) {
//         int K;
//         cin >> K;
//         F[i].resize(K);
//         for (int j = 0; j < K; j++) {
//             cin >> F[i][j];
//         }
//     }

//     cout << pianifica(N, L, F) << endl;

//     return 0;
// }
