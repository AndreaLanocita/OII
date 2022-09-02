#include <bits/stdc++.h> 
#include <climits>

using namespace std;

#define vi vector<int>
#define pi pair<ll, int>
#define pl pair<ll, ll>
#define vp vector<pi>
#define ll long long int
#define vl vector<ll>
#define umap unordered_map<ll, int>
#define omap map<int, ll>

ll MOD = 1000000007, summ; vl fenwick; int MAXN;

void add(ll index, ll val) {
    while(index < MAXN) {
        fenwick[index] = (fenwick[index] + (val % MOD)) % MOD;
        index += index & (-index);
    }
}

ll sum(int index) {
    summ = 0; 
    while(index > 0) {
        summ += fenwick[index];
        index -= index & (-index);
    }
    return summ%MOD;
}

bool cmp(pi a, pi b) {
    if(a.first < b.first || (a.first==b.first && a.second>b.second)) return true;
    return false;
}

int main() {
    cin.tie(0); ios::sync_with_stdio(false);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int N;
    cin >> N;
    int arr[N+1]; MAXN = N+1; fenwick.resize(N+1); vp ord;
    arr[0] = 0;

    for(int i=1; i<N+1; i++) {
        cin >> arr[i];
        ord.push_back({arr[i], i});
    }
    sort(ord.begin(), ord.end(), cmp);

    ll res = 0, prt;
    fenwick[0] = 0;

    for(int i=0; i<N; i++) {
        prt	= sum(ord[i].second-1)+1;
        res = (res + prt)%MOD;
        add(ord[i].second, prt);
    }
    cout << res;
    return 0;
}