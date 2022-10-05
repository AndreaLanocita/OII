#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define popb pop_back
#define vi vector<int>
#define pi pair<int, int>
#define vp vector<pi>
#define ll long long int
#define pl pair<ll, ll>
#define vl vector<ll>
#define vpl vector<pl>
#define omap map<int, int>
#define umap unordered_map<int, int>
#define pq priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>>

long long somma(int l, int r);
long long subarray_massimo(int l, int r);
long long subarray_minimo(int l, int r);

long long trova(int N) {
    return subarray_massimo(0, 9999);
}


// long long trova(int N);

// static int N, chiamate = 0, lunghezza_massima = 0;
// static vector<int> v;

// long long somma(int a, int b) {
//     lunghezza_massima = max(lunghezza_massima, b - a + 1);
//     chiamate++;
//     long long tot = 0;
//     for (int i = a; i <= b; i++) tot += v[i];
//     return tot;
// }

// long long subarray_massimo(int a, int b) {
//     lunghezza_massima = max(lunghezza_massima, b - a + 1);
//     chiamate++;
//     long long ma = 0;
//     for (int i = a; i <= b; i++) {
//         for (int j = i; j <= b; j++) {
//             long long tot = 0;
//             for (int h = i; h <= j; h++) tot += v[h];
//             if (tot > ma) ma = tot;
//         }
//     }
//     return ma;
// }

// long long subarray_minimo(int a, int b) {
//     lunghezza_massima = max(lunghezza_massima, b - a + 1);
//     chiamate++;
//     long long mi = 0;
//     for (int i = a; i <= b; i++) {
//         for (int j = i; j <= b; j++) {
//             long long tot = 0;
//             for (int h = i; h <= j; h++) tot += v[h];
//             if (tot < mi) mi = tot;
//         }
//     }
//     return mi;
// }

// int main() {
//     // se preferisci leggere e scrivere da file
//     // ti basta decommentare le seguenti due righe:

//     // ifstream cin("input.txt");
//     // ofstream cout("output.txt");
//     cin >> N;
//     v.resize(N);
//     for (int i = 0; i < N; i++) cin >> v[i];
//     long long ans = trova(N);
//     cout << "La tua risposta e' " << ans << endl;
//     cout << "Hai effettuato " << chiamate << " chiamate" << endl;
//     cout << "La lunghezza massima tra le chiamate e' " << lunghezza_massima << endl;
//     return 0;
// }
