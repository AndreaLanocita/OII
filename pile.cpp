#include <bits/stdc++.h>

using namespace std;

void solve(int t) {
    int N, sol, A, B, C, maxx;
    cin >> N;
    sol = 0;

    for (int i = 0; i < N; i++) {
        cin >> A >> B >> C;
        maxx = max(A, B);
        sol += max(maxx, C);
    }
    

    cout << "Case #" << t << ": " << sol << "\n";
}

int main() {
    // se preferisci leggere e scrivere da file
    // ti basta decommentare le seguenti due righe:

    freopen("pile_input_1.txt", "r", stdin);
    freopen("pile_output.txt", "w", stdout);

    int T;
    cin >> T;

    for (int t = 1; t <= T; t++) {
        solve(t);
    }

    return 0;
}