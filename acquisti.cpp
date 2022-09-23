#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define vi vector<int>
#define pi pair<int, int>
#define pl pair<ll, int>
#define pq priority_queue<pl, vector<pl>, greater<pl>>

bool comp(pl a, pl b) {
    if(a.second<b.second) return true;
    return false;
}

vector<long long> calcola(int T, int M, vector<long long> S, vector<long long> P) {
    vector<long long> R(M);
    ll peso_corrente = 0, primo_souvenir = 0;
    vector<pl> valigie(M);

    // aggiungo indici alle valigie
    for(int i=0; i<M; i++) valigie[i] = {P[i], i};

    // sort dei pesi, ma non hanno indici
    sort(P.begin(), P.end());
    sort(valigie.begin(), valigie.end());

    // devo rendere P e valigie su stesso ordine
    // resetto valigie a zero
    for(int i=0; i<M; i++) valigie[i].first = 0;


    for(int i=0; i<M; i++) {
        // valigia più piccola
        for(int j=primo_souvenir; j<T; j++) {
            // parto dal souvernir più piccolo e valigia più piccola
            
                // ci stanno tutti?
                if(peso_corrente+(S[j]*j)<=P[i]) {
                    // ho aggiunto tutti questi, parto dal prossimo
                    primo_souvenir++;
                    // li aggiungo tutti 
                    valigie[i].first += S[j];
                    // aggiungo al peso corrente
                    peso_corrente += (S[j]*j);
                }

                // non ci stanno tutti, aggiungo quelli che ci stanno
                // e vado alla valigia successiva
                else {
                    ll numero = (P[i]-peso_corrente) / j;
                    valigie[i].first += numero;
                    // tolgo quelli che ho già messo --> non li rimetto nella successiva
                    S[j] -= numero;
                    // aggiungo al peso
                    peso_corrente += (j*numero);
                    // vado alla valigia dopo
                    break;
                }
        }
    }

    // psum array
    for(int i=1; i<M; i++) valigie[i].first += valigie[i-1].first;
    // torno ad ordine inizale
    sort(valigie.begin(), valigie.end(), comp);

    // riempio R
    for(int i=0; i<M; i++) R[i] = valigie[i].first;
    

    return R;
}

// int main() {
//     ios::sync_with_stdio(false);
//     // se preferisci leggere e scrivere da file ti basta decommentare le seguenti due righe:
//     freopen("input.txt", "r", stdin);
//     // freopen("output.txt", "w", stdout);

//     int T, M;
//     cin >> T >> M;

//     vector<long long> S(T), P(M);

//     for (long long& x : S) cin >> x;
//     for (long long& x : P) cin >> x;

//     auto R = calcola(T, M, S, P);

//     for (long long x : R) cout << x << ' ';
//     cout << endl;

//     return 0;
// }