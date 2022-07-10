#include <bits/stdc++.h>

using namespace std;

void solve(int t) {
    int N, L, D, t_rimasto, pos;
    cin >> N >> L >> D;

    int sol[N][2];  // punti, tempo rimasto
    vector<int> X(N), P(N), S(N);
    for (int i = 0; i < N; i++) {
        cin >> X[i] >> P[i] >> S[i];
    }

    t_rimasto = D;
    
    for(int i=0; i<N; i++) {
        // i = 0

        // posso prendere l'ostacolo senza andare fuori tempo
        if(X[i] <= sol[i-1][1]-(X[i] - X[i-1])) {
            sol[i][0] = sol[]
        }  
    }
    

    cout << "Case #" << t << ": " << 1 << "\n";
}

int main() {
    // se preferisci leggere e scrivere da file
    // ti basta decommentare le seguenti due righe:

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int T;
    cin >> T;

    for (int t = 1; t <= T; t++) {
        solve(t);
    }

    return 0;
}