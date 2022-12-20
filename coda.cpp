#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define vi vector<int>

void add(int index, int val, vector<ll>& fenwick) {
    while(index < fenwick.size()) {
        fenwick[index] += val;
        index += (index & (-index));
    }
    return ;
}

ll psum(int index, vector<ll>& fenwick) {
    ll res = 0;
    while(index > 0) {
        res += fenwick[index];
        index -= (index & (-index));
    }
    return res;
}

ll range_sum(int a, int b, vector<ll>& fenwick, int X) {
    return psum(b, fenwick) - psum(a, fenwick);
}

vector<int> cucina(int N, int K, int X, vector<int> H) {
    vector<int> R(X);
    vector<ll> fenwick;
    fenwick.assign(X+1, 0);

    // riempio arr
    for(int i=0; i<H.size(); i++) {
        add(H[i]+1, 1, fenwick);
    }

    for(int i=0; i<X; i++) {
        R[i] = min((ll)(X-i), range_sum(i, X, fenwick, X));
    }

    return R;
}

// int main() {
//     // se preferisci leggere e scrivere da file ti basta decommentare le seguenti due righe:
//     // freopen("coda.input1.txt", "r", stdin);
//     // freopen("output.txt", "w", stdout);

//     int N, K, X;
//     cin >> N >> K >> X;

//     vector<int> H(N);
//     for (int& h : H) {
//         cin >> h;
//     }

//     vector<int> res = cucina(N, K, X, move(H));
//     for (int r : res) {
//         cout << r << ' ';
//     }
//     cout << endl;

//     return 0;
// }