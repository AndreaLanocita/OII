#include <bits/stdc++.h>

using namespace std;

int main() {
    // se preferisci leggere e scrivere da file
    // ti basta decommentare le seguenti due righe:

    freopen("download_input_1.txt", "r", stdin);
    freopen("download_output.txt", "w", stdout);

    int T, t;
    cin >> T;

    for (t = 1; t <= T; t++) {
        int N, F, C;
        
        // scrivi in queste variabili la risposta
        int nf, nc;

        cin >> N >> F >> C;

        nf = N / F;
        N = N % F;
        nc = N / C;

        cout << "Case #" << t << ": " << nf << " " << nc << endl;
    }
}