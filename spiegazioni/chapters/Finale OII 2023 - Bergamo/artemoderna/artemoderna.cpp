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

bool ordina(int N, vector<int> V, vector<int> &L) {
    int prec=0;
    for(int i=1; i<N+1; i++) {
        if(i==N) {
            L.push_back(i-prec);
            prec += L[L.size()-1];
        }
        else if(V[i-1]<V[i]) {
            L.push_back(i-prec);
            prec += L[L.size()-1];
        }
    }
    prec=0;
    for(int i=0; i<L.size()-1; i++) {
        if(V[L[i+1]+L[i]+prec-1]<V[prec]) return 0;
        prec+=L[i];
    }
    return 1;
}