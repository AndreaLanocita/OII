#include <bits/stdc++.h>

using namespace std;

int solve() {
    int N, dentro, fuori;
    cin >> N;

    int risposta = 0;  // memorizza qui la risposta
    dentro, fuori = 0;

    for (int i=0; i<N; i++) {
        int variazione;
        cin >> variazione;

        if((dentro == 0 && variazione < 0) || (fuori == 0 && variazione > 0)) {
            risposta++;
        }
        if(variazione<0) {
            fuori++;
            if(dentro != 0) dentro--;
        }
        else {
            dentro++;
            if(fuori != 0) fuori--;
        }
    }

    return risposta;
}

int main() {
    // se preferisci leggere e scrivere da file
    // ti basta decommentare le seguenti due righe:

    freopen("tornello_input_1.txt", "r", stdin);
    freopen("tornello_output.txt", "w", stdout);

    int T, t;
    scanf("%d", &T);

    for (t = 1; t <= T; t++) {
        cout << "Case #" << t << ": " << solve() << endl;
    }
}