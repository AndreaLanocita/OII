// NOTE: it is recommended to use this even if you don't understand the following code.

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

#define MAXN 5000

// union find + sort parziale (con map come counter)
int r[MAXN];
int p[MAXN];

void make_set(int x) {
    r[x] = 0;
    p[x] = x;
}

int find(int x) {
    if(x==p[x]) return x;
    return p[x] = find(p[x]);
}

void unionn(int a, int b) {
    a = find(a);
    b = find(b);

    if(a==b) return;
    if(r[a] < r[b]) {
        // a più basso --> a sotto b
        p[a] = b;
    }
    else {
        p[b] = a;
        if(r[a]==r[b]) r[b]++;
    }
    return ;
}

struct arco {
    int a, b;
};

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
//  uncomment the following lines if you want to read/write from files
//    ifstream cin("input.txt");
//  ofstream cout("output.txt");

    int N, K;
    cin >> N >> K;

    vector<int> P(N);
    for (int i = 0; i < N; i++) cin >> P[i];

    vector<int> L(K);
    for (int i = 0; i < K; i++) cin >> L[i];


    // faccio i disjoint set
    for(int i=0; i<N; i++) make_set(i);

    // faccio la lista di archi
    vector<arco> archi;
    archi.reserve(N*K+1);
    for(int i=0; i<N; i++) {
        for(int j=0; j<K; j++) {
            if(i+L[j] >= N) continue;   // oltre il limite
            archi.push_back({i, i+L[j]});
        }
    }

    // faccio mst
    for(arco arco: archi) {
        if(find(arco.a) == find(arco.b)) continue;
        unionn(arco.a, arco.b);
    }

    // faccio mappa {vettore da ordinare, counter=0}
    unordered_map<int, pair<vi, int>> m;
    set<int> radici;
    for(int i=0; i<N; i++) {
        int findd = find(i);
        m[findd].first.pb(P[i]);
        m[findd].second = 0;
        radici.insert(findd);
    }

    // sort parziale di ogni componente connessa
    for(int radice: radici) sort(m[radice].first.begin(), m[radice].first.end());

    for(int i=0; i<N; i++) {
        int findd = find(i);
        P[i] = m[find(i)].first[m[findd].second];
        m[findd].second++;
    }

	for(int i = 0; i < N; i++) {
		cout << P[i] << ' ';
	}
    cout << endl;

    return 0;
}
