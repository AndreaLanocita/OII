#include <bits/stdc++.h> 

using namespace std;

#define vi vector<int>
#define pi pair<int, int>
#define vp vector<pi>
#define ll long long int
#define omap map<int, int>
#define umap unordered_map<int, int>

ll nEmote(ll nSms, ll k) {
    if(nSms<=k) return ((nSms*(nSms+1))/2);
    return ((k*(k+1))-((2*k-1-nSms)*(2*k-nSms))/2-k);
}

ll solve(ll k, ll x) {
    ll l=1, r=2*k-1;
    while(l<r) {
        ll mid = (l+r)/2;
        if(nEmote(mid, k)<=x) l=mid+1;
        else r=mid;
    }
    if(nEmote(r-1, k)<x) return r;
    return r-1;
}

int main() {
    ll t, k, x;
    cin >> t;
    // nEmote(5, 4);
    for(ll i=0; i<t; i++) {
        cin >> k >> x;
        cout << solve(k, x) << endl;
    }
    
    return 0;
}