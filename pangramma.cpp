#include <bits/stdc++.h>
#include <climits>

using namespace std;

#define ll long long
#define INF LLONG_MAX

const int MOD = 46337;

// uso un st per tenere i prodotti
vector<ll> st;
ll real_size = 1;
void add(ll index, ll val) {
    index += real_size;
    st[index] = (st[index]%MOD + val%MOD)%MOD;
    index /= 2;
    while(index > 0) {
        st[index] = (st[2*index]%MOD * st[2*index+1]%MOD)%MOD;
        index /= 2;
    }
    return ;
}

ll query(int index) {return st[1]%MOD;}

int conta(int N, int K, vector<int>& V) {
    vector<ll> visto(K+3, 0);
    ll a=0, b=1, res = 0, min_res = INF;    // b escluso
    visto[V[a]] = 1;
    ll counter_rimasti = K-1;

    while(real_size < K) real_size *= 2;
    st.assign(2*real_size, 1);

    while(b<N) {
        while(counter_rimasti != 0 && b<N) {
            if(visto[V[b]] == 0) counter_rimasti -= 1;
            visto[V[b]] += 1;
            b++;
        }
        while(counter_rimasti == 0 && a<b) {
            min_res = min(b-a, min_res);
            visto[V[a]] -= 1;
            a++;
            if(visto[V[a-1]] == 0) counter_rimasti += 1;
        }
    }

    // ora minn = minimo pangramma
    // --> cerco numero evidenziature
    a = 0; b= 1;
    vector<ll> visto1(K+3, 0);
    visto1[V[a]] = 1;
    counter_rimasti = K-1;

    while(b<N) {
        while(b-a<min_res && b<N) {
            if(visto1[V[b]] == 0) counter_rimasti -= 1;
            else add(V[b], 1);  // invece che la somma tengo il prodotto
            visto1[V[b]] += 1;  
            b++;
        }
        // trovato pangramma
        if(counter_rimasti == 0) res = (res%MOD + query(K)%MOD)%MOD;

        if(visto1[V[a]] == 1) counter_rimasti += 1;
        else add(V[a], -1);
        visto1[V[a]] -= 1;
        a++;
    }

    return res;
}

int main() {
    // Input da file:
    freopen("input.txt", "r", stdin);

    // Output su file:
    // freopen("output.txt", "w", stdout);

    size_t n, k;
    cin >> n >> k;
    vector<int> v(n);
    for(size_t i = 0; i < n; i++) {
        cin >> v[i];
    }
    cout << conta(n, k, v) << endl;
    return EXIT_SUCCESS;
}