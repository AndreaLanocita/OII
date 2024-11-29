// NOTE: it is recommended to use this even if you don't understand the following code.

#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define popb pop_back
#define vi vector<int>
#define pi pair<int, int>
#define vp vector<pi>
#define ll long long
#define pl pair<ll, ll>
#define vl vector<ll>
#define vpl vector<pl>
#define omap map<int, int>
#define umap unordered_map<int, int>
#define pq priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>>
#define int long long

const int MOD = 1e9 + 7;
#define MAXN 100000

ll dp[MAXN] = { };
int catalan(int n) {
    dp[0] = dp[1] = 1;

    for(int i=2; i<=n; i++) {
        // sommatoria
        for(int j=0; j<i; j++) {
            dp[i] = (dp[i] + ((dp[j]*dp[i-1-j]) % MOD)) % MOD;
        }
    }
    return 0;
}

signed main() {
    // uncomment the following lines if you want to read/write from files
    // ifstream cin("input.txt");
    // ofstream cout("output.txt");
    cin.tie(0); ios::sync_with_stdio(false);

    ll N;
    cin >> N;

    catalan(N+1);
    ll n = N;
    ll tmp;
    ll summ = 0;

    if((n-1)%2==0) tmp = (n-1)/2-1;
    else tmp = (n-1)/2;

    for(int i=0; i<=tmp; i++) {
        summ += ((dp[i]%MOD * dp[n-1-i]%MOD)%MOD);
    }

    cout << summ%MOD << endl;  // print the result
    return 0;
}
