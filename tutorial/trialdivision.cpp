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

// per trovare i fattori primi di un numero

vi fattori;

void trova_fattori(ll n) {
    fattori.clear();
    // trial division
    for(ll i=2; i*i<=n; i++) {
        while(n%i==0) {
            // i è un fattore primo di n
            n /= i;
            fattori.pb(i);
        }
    }
    if(n>1)fattori.pb(n);
}