#include <bits/stdc++.h> 

using namespace std;

#define vi vector<int>
#define pi pair<int, int>
#define vp vector<pi>
#define ll long long int
#define omap map<int, int>
#define umap unordered_map<int, int>

int main() {
    int N;
    cin >> N;
    vector<pair<ll, ll>> r;
    ll xl, xr;
    cin >> xl >> xr;
    for(int i=0; i<N; i++) {
        pair<ll, ll> tmp;
        cin >> tmp.first >> tmp.second;
        r.push_back({tmp.first*xl+tmp.second, tmp.first*xr+tmp.second});
    }

    sort(r.begin(), r.end());
    
    for(int i=1; i<N; i++) {
        if(r[i-1].second>r[i].second) {
            cout << "YES" << endl;
            return 0;
        }
    }

    cout << "NO" << endl;
    return 0;
}