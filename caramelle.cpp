#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define ll long long int

vi fattori;
vi nfattori;
vi nperm(INT_MAX, 0);
vi perm;

void trova_fattori(ll n) {
    nfattori.clear(); nfattori.resize(INT_MAX, 0);
    fattori.clear();
    // trial division
    for(ll i=2; i*i<=n; i++) {
        while(n%i==0) {
            // i è un fattore primo di n
            n /= i;
            if(nfattori[i] == 0) fattori.push_back(i);
            nfattori[i]++;
        }
    }
    if(n>1){
        if(nfattori[n] == 0) fattori.push_back(n);
        nfattori[n]++;
    } 

    for(int el: fattori) {
        if(nfattori[el] > nperm[el]) {
            if(nperm[n] == 0) perm.push_back(n);
            nperm[el] = nfattori[el];
        } 
    }
}

int solve(){
    int N;
    cin >> N;
    vector<int> V(N);
    for(int &x: V){
        cin >> x;
    }

    for(int i=0; i<N; i++) trova_fattori(V[i]);

    int res = 0;
    for(int el: perm) {
        res += pow(el, nperm[el]);
    }
    return res;
}

int main(){
    freopen("caramelle_input_1.txt", "r", stdin);
    freopen("caramelle_output_1.txt", "w", stdout);

    int T;
    cin >> T;
    for (int i = 0; i < T; i++){
        cout << "Case #" << i+1 << ": " << solve() << endl;
    }
    return 0;
}