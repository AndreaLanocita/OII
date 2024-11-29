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
    for(int i=0; i<N; i++) {
        if(lunghezze[i]<=div) {
            finale[counter] = lunghezze[i];
            tot-=lunghezze[i];
            res += (finale[counter]*finale[counter]);
            counter++;
            if(M-counter<=0) break;
            div = tot /(M-counter);
        }
    }
    
    if(M!=counter) resto = tot % (M-counter);
    // propago il resto dopo counter, quelli <= non possono essere modificati
    while(counter<M) {
        finale[counter] = div;
        if(resto!=0) {
            finale[counter]++;
            resto--;
        } 
        res += (finale[counter]*finale[counter]);
        counter++;
    }

    cout << res << endl; 
    return 0;
    // check1
}