#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define popb pop_back
#define vi vector<int>
#define pi pair<int, int>
#define vp vector<pi>
#define ll long long int
#define pl pair<ll, ll>
#define vl vector<ll>
#define vpl vector<pl>
#define omap map<int, int>
#define umap unordered_map<int, int>
#define pq priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>>

struct tri {
    ll arrivo, id, pos;
    tri() : arrivo(0), id(0), pos(0) {};
    tri(ll arrivo, ll id, ll pos) : arrivo(arrivo), id(id), pos(pos) {};
};

// dovrei tenere una lista di costo, id, pos per ogni posto
// e se lo visito azzerarla

// oppure faccio metodo figo con cui costruisco il grafo mano a mano che vado avanti,
// aggiungendo per ogni fermata in cui arrivo il percorso ad ogni linea successiva non già aggiunta
// --> aggiungendo ogni linea solo una volta
// N.b. devo segnarmi anche la fermata da cui faccio partire la linea, dato che potrebbero esserci
// delle fermate precedenti non toccate

int pianifica(int N, int L, vector<vector<int>> F) {
    vector<tri> adj[N];
    int maxk = 0;
    for(int i=0; i<L; i++) {
        for(int j=0; j<F[i].size()-1; j++) adj[F[i][j]].push_back({F[i][j+1], i, j});
        int tmp = F[i].size();
        maxk = max(maxk, tmp);
    }

    vector<tri> d(N);
    d[0] = {0, -1, -1}; pq p; p.push({0, 0}); int n = 0;
    for(int i=1; i<N; i++) d[i] = {LLONG_MAX, -1, -1};

    for(int i=0; i<N; i++) {
        if(p.empty()) break;
        n = p.top().second;
        p.pop();

        for(tri vicino: adj[n]) {
            // devo aggiungere uno
            if(d[n].id != -1 && (vicino.id != d[n].id || vicino.pos != d[n].pos + 1)) {
                // provo a migliorare
                if(d[n].arrivo + 1 <= d[vicino.arrivo].arrivo) {
                    d[vicino.arrivo].arrivo = d[n].arrivo + 1;
                    d[vicino.arrivo].id = vicino.id;    // cambio linea
                    d[vicino.arrivo].pos = vicino.pos;

                    p.push({d[vicino.arrivo].arrivo, vicino.arrivo});
                }
            }
            else {
                // dovrebbe essere sempre vero ma non si sa mai
                if(d[n].arrivo <= d[vicino.arrivo].arrivo) {
                    d[vicino.arrivo].arrivo = d[n].arrivo;
                    d[vicino.arrivo].id = vicino.id;    
                    d[vicino.arrivo].pos = vicino.pos;
                    p.push({d[vicino.arrivo].arrivo, vicino.arrivo});
                }
            }
        }
    }

    if(d[N-1].arrivo == LLONG_MAX) return -1;
    else return d[N-1].arrivo;

}

int main() {
    ios_base::sync_with_stdio(false);
    // se preferisci leggere e scrivere da file ti basta decommentare le seguenti due righe:
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int N, L;
    cin >> N >> L;

    vector<vector<int>> F(L);
    for (int i = 0; i < L; i++) {
        int K;
        cin >> K;
        F[i].resize(K);
        for (int j = 0; j < K; j++) {
            cin >> F[i][j];
        }
    }

    cout << pianifica(N, L, F) << endl;

    return 0;
}