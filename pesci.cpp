#include <bits/stdc++.h>

using namespace std;

void solve(int t) {
    int N, K, sol, uova;
    cin >> N >> K;

    // aggiungi codice...
    sol = N; 
    uova = N/K;
    while(uova != 0) {
        sol += uova;
        uova = uova/K;
    }
    
    cout << "Case #" << t << ": " << sol << endl;
}

int main() {
    // se preferisci leggere e scrivere da file
    // ti basta decommentare le seguenti due righe:

    freopen("pesci_input_1.txt", "r", stdin);
    freopen("pesci_output.txt", "w", stdout);

    int T;
    cin >> T;

    for(int t = 1; t <= T; t++) {
        solve(t);
    }
}