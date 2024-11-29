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
    int i=0;
    while(i!=N-1 && V[i+1]==V[i]) i++;
    if(i==N-1 || V[i+1] < V[i]) {
        L.push_back(N);
        return 1;
    }
    else {
        for(int j=0; j<N; j++) L.push_back(1);
        return 1;
    }
}