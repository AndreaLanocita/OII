#include <bits/stdc++.h> 

using namespace std;

#define vi vector<int>
#define pi pair<int, int>
#define vp vector<pi>
#define ll long long int
#define omap map<int, int>
#define umap unordered_map<int, int>

void inserisci(multiset<ll> &s) {
    ll x;
    cin >> x;
    s.insert(x);
}

void lesss(multiset<ll> &s) {
    ll x, k;
    cin >> x >> k;
    multiset<ll>::iterator it = s.upper_bound(x);
    
    for(int i=0; i<k; i++) {
        if(it == s.begin()) {
            cout << -1 << endl;
            return ;
        }
        it--;
    }
    cout << *it << endl;
}

void more(multiset<ll> &s) {
    ll x, k;
    cin >> x >> k;
    multiset<ll>::iterator it = s.lower_bound(x);
    if(it == s.end()) {
        cout << -1 << endl;
        return ;
    }


    for(int i=0; i<k-1; i++) {
        it++;
        if(it == s.end()) {
            cout << -1 << endl;
            return ;
        }
    }
    cout << *it << endl;
}

int main() {
    int Q;
    multiset<ll> s;
    cin >> Q;

    for(int i=0; i<Q; i++) {
        int t;
        cin >> t;
        if(t==1) inserisci(s);
        if(t==2) lesss(s);
        if(t==3) more(s);
    }
    return 0;
}