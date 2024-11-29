#include <bits/stdc++.h> 

using namespace std;

#define vi vector<int>
#define pi pair<int, int>
#define vp vector<pi>
#define ll long long int
#define omap map<int, int>
#define umap unordered_map<int, int>

int main() {
    ll N, M;
    cin >> N >> M;
    vector<ll> lunghezze(N);
    ll tot = 0;
    for(int i=0; i<N; i++) {
        cin >> lunghezze[i];
        tot += lunghezze[i];
    } 

    ll div = tot/M;
    sort(lunghezze.begin(), lunghezze.end());
    vector<ll> finale(M); int counter=0;
    ll res =0; ll resto;
    int breakpoint;
    for(int i=0; i<N; i++) {
        if(lunghezze[i]<=div) {
            long long x = lunghezze[i];
            tot-=lunghezze[i];
            res += (x*x);
            counter++;
            if(M-counter<=0) {
                cout << res << endl;
                return 0;
            }
            div = tot /(M-counter);
        } else {
            breakpoint = i;
            break;
        }
    }

    for(int i = N-i; i > breakpoint; i--) {
        long long r = lunghezze[i]%div;
        int k = lunghezze[i]/div;
        res += r * (div+1)*(div+1);
        res += (k-r) * div * div;
        counter += k;
        tot -= lunghezze[i];
        if(M-counter <= 0) {
            cout << res << endl;
            return 0;
        }
        div = tot/(M-counter);
    }
    
    cout << res << endl; 
    return 0;
    // check1
}