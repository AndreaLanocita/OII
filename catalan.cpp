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

#define MAXN 100000
#define MOD 129

ll C[MAXN] = { };
int catalan(int n) {
    C[0] = C[1] = 1;

    for(int i=2; i<=n; i++) {
        // sommatoria
        for(int j=0; j<i; j++) {
            C[n] = (C[n] + ((C[j]*C[i-1-j]) % MOD)) % MOD;
        }
    }
}

// oppure
ll C[MAXN] = { };
ll F[MAXN] = { };

int fattoriale(int n) {
    F[0] = F[1] = 1;
    for(int i=2; i<=2*n; i++) {
        F[i] = i*F[i-1];
    }
}

int catalan(int n) {
    C[0] = C[1] = 1;

    for(int i=2; i<=n; i++) {
        C[i] = F[2*n] / (F[n+1]*F[n]);
    }
}