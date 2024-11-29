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
ll N;
long long D;

int main() {
//  uncomment the following lines if you want to read/write from files
//  ifstream cin("input.txt");
//  ofstream cout("output.txt");

   cin >> N >> D;

    // insert your code here
    ll cost = pow(10, N-1);
    ll n = cost / D;
    vi a;
    
    if(n*D<cost) n+=1;
    if(D*(n+1) >= cost*10) {
        cout << 0 << " " << 0;
        return 0;
    } 

    ll tmp = D*n;
    ll tmp1 = D*(n+1);
    cout << tmp << ' ' << D*(n+1) << '\n'; // print the result
    return 0;
}
