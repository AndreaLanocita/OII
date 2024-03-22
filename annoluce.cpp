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

#define MAXN 100000

vl distanze;
void mappatura(int N, int X[], int Y[], int Z[]) {
    distanze.reserve(N);
    for(int i=0; i<N; i++) distanze.pb((ll)X[i]*X[i] + (ll)Y[i]*Y[i] + (ll)Z[i]*Z[i]);
    sort(distanze.begin(), distanze.end());
}

int query(ll D, ll N) {
    ll l=0, r=N, mid;
    ll Dq = D*D;
    while(l<r) {
        mid = (l+r)/2;
        // non posso raggiungerlo --> controllo indietro
        if(distanze[mid] > Dq) r = mid;
        else l = mid+1;
    }
    return r;
}


int X[MAXN], Y[MAXN], Z[MAXN];

int main() {
    FILE *fr, *fw;
    int N, Q, i;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(1 == fscanf(fr, "%d", &N));
    for(i=0; i<N; i++)
        assert(3 == fscanf(fr, "%d%d%d", &X[i], &Y[i], &Z[i]));

    mappatura(N, X, Y, Z);

    assert(1 == fscanf(fr, "%d", &Q));
    for(i=0; i<Q; i++) {
        int D;
        assert(1 == fscanf(fr, "%d", &D));
        fprintf(fw, "%d\n", query(D, N));
    }

    fclose(fr);
    fclose(fw);
    return 0;
}
