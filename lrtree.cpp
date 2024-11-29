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

long long fact[2*MAXN+1];

long long catalan(int n) {
    return (fact[2*n]/(fact[n]*fact[n+1]));
}

signed main() {
    // uncomment the following lines if you want to read/write from files
    // ifstream cin("input.txt");
    // ofstream cout("output.txt");
    cin.tie(0); ios::sync_with_stdio(false);

    int N;
    cin >> N;

    int n = N;
    int tmp;
    int summ = 0;
    fact[0] = fact[1] = 1;
    for(int i=2; i<2*N+1; i++) fact[i]=((fact[i-1]%MOD)*(i%MOD))%MOD;

    cout << catalan(n-2)+catalan(n-1) << endl;  // print the result
    return 0;
}