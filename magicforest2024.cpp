// NOTE: it is recommended to use this even if you don't understand the following code.

#include <bits/stdc++.h>

using namespace std;

#define MOD 10000000007
#define ll long long

struct archi {
    int a, b, c;

    archi(int d, int e, int f) : a(d), b(e), c(f) {};
    archi() : a(0), b(0), c(0) {};
};

int main() {
    int N, M;
    cin >> N >> M;
    
    vector<pair<int, int>> adj[N+1]; // da 1 a N
    vector<archi> lis[2]; // +1 perché potrebbe essere un ciclo
    lis[0].resize(4*M+100); lis[1].resize(4*M+100);
    ll res = 0, lung=0, tmp=0, flag;
    for (int i = 0; i < 2*M; i+=2) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({c, b});
        adj[b].push_back({c, a});

        lis[0][i] = archi(a, b, c);
        lis[0][i+1] = archi(b, a, c);
        res = (res%MOD+1)%MOD;
        lung= (lung%MOD+2)%MOD;
    }

    // faccio ogni istanza come max_raggiunto + 1
    // si dimostra che la complessità in questo modo rimane ottimale
    // dato che vanno calcolati tutti
    for(int i=0; ; i++) {
        flag = 1;
        for(int j=0; j<lung; j++) {
            archi arco = lis[0][j];
            for(pair<int, int> arco2: adj[arco.b]) {
                if(arco2.first == arco.c+1) {
                    lis[1][tmp] = archi(arco.a, arco2.second, arco2.first);
                    res = (res%MOD+1)%MOD;
                    tmp = (tmp%MOD+1)%MOD;
                    flag = 0;
                } 
            }
        }
        if(flag==1) break;

        for(int j=0; j<tmp; j++) {
            lis[0][j] = lis[1][j];
        }
        lung = tmp;
        tmp = 0;
    }

    cout << res << endl; // print the result
    return 0;
}
