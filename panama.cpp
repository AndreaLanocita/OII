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

// input data
int N, Q;
vector<ll> V;
ll res;

ll get_sum(int l, int r) {
    ll maxx = 0;
    res = LLONG_MIN;
    for(int i=l; i<=r; i++) {
        if((i-l)%2==0) maxx = max(V[i], maxx+V[i]);
        else maxx = max(-V[i], maxx-V[i]);
        if(maxx > res) res = maxx;
    }
    return res;
}

int main() {
    //  uncomment the following lines if you want to read/write from files
    ifstream cin("input.txt");
    //  ofstream cout("output.txt");

    cin >> N >> Q;
    V.resize(N + 1);
    for (int i = 1; i <= N; i++) cin >> V[i];
    ll ress;

    for (int i = 0; i < Q; i++) {
        int t;
        cin >> t;
        if (t == 1) {
            int a, b;
            cin >> a >> b;
            V[a] = b;
        } else {
            ress = LLONG_MIN;
            int l, r;
            cin >> l >> r;
            if(l<r)  ress = get_sum(l+1, r);
            ress = max(ress, get_sum(l, r));
            cout << ress << endl;
        }
    }

    return 0;
}
