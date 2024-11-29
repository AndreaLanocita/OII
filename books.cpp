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

void ricorsiva(int n, vi& pila, int counter) {
    for(int i=0; i<n/2; i++) {  // indici
        cout << 1 << " " << 0 << " " << counter << endl;
    }
    pila.push_back(n/2);
}

int main() {
    int n;
    cin >> n;

    vi pila;
    int counter = 0;
    pila.push_back(1);

    counter++;
    ricorsiva(n, pila, counter);
    // n = (n+1)/2;

    // sposto tutti sopra
    int rimasti = n-(n/2);
    cout << rimasti << " " << 0 << " " << 1 << endl;

    // li giro
    for(int i=0; i<rimasti; i++) {
        cout << 1 << " " << 1 << " " << 2 << endl;
    }

    // li rimetto sopra
    cout << rimasti << " " << 2 << " " << 1 << endl;

    cout << n << " " << 1 << " " << 0 << endl;

}
