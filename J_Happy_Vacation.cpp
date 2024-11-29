#include <bits/stdc++.h> 

using namespace std;

#define vi vector<int>
#define pi pair<int, int>
#define vp vector<pi>
#define ll long long int
#define omap map<int, int>
#define umap unordered_map<int, int>

bool a(ll p, ll h[], ll M, ll N) {
    int n=0; ll mancanti = N;
    ll felicita[N+1] = {}; felicita[0] = LLONG_MAX;
    while(M>0 && mancanti!=0) {
        if(n==0) {
            n = 1;
            felicita[n] += h[n];
            if(felicita[n]>=p) mancanti--;
            M--;
        } else {
            if(felicita[n-1]<p) {
                int c = (p-felicita[n-1]) / h[n-1];
                if((p-felicita[n-1]) % h[n-1] != 0) c++;
                M-=(2*c);
                felicita[n-1] = p;
                felicita[n] += h[n]*c;
                mancanti--;
                if(felicita[n]>=p) mancanti--;
            } else {
                if(n==N) {
                    // n = n-1;
                    int c = (p-felicita[n]) / h[n];
                    if((p-felicita[n]) % h[n] != 0) c++;
                    M-=(2*c);
                    mancanti--;
                } else {
                    n = n+1;
                    felicita[n] += h[n];
                    if(felicita[n]>=p) mancanti--;
                    M--;
                }   
            }
        }
        // if(M<(p-felicita[n])/h[n]) return 0;
    }
    if(M>=0 && mancanti==0) return 1;
    return 0;
}

int solve(ll N, ll M) {
    ll h[N+1]; ll maxx = -1;
    for(int i=1; i<N+1; i++) {
        cin >> h[i];
        if(h[i]>maxx) maxx = h[i];
    } 

    ll l=0, r=M*maxx+1;
    ll mid;
    while(l<r) {
        mid =(l+r)/2;
        if(a(mid, h, M, N)) l = mid+1;
        // rispetta la condizione --> ce ne sono troppi --> abbasso il prezzo
        else r = mid;
    }
    return r-1; // return r;
}


int main() {
    int T;
    cin >> T;
    for(int i=0; i<T; i++) {
        ll N, M;
        cin >> N >> M;
        cout << solve(N, M) << endl;
    }
    return 0;
}