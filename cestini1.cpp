#include <bits/stdc++.h>

using namespace std;

void inizia(int N, int M, string S, map<int, vector<char>>& cestini) {
    for(int i=0; i<N; i++) {
        cestini[0].push_back(S[i]);
    }
}

void sposta(int a, int b, map<int, vector<char>>& cestini) {
    cestini[b].push_back(cestini[a][cestini[a].size()-1]);
    cestini[a].pop_back();
}

int controlla(int a, int i, map<int, vector<char>>& cestini) {
    return cestini[a][i];
}

void solve(int t) {
    int N, M, Q;
    cin >> N >> M >> Q;

    string S;
    cin >> S;

    map<int, vector<char>> cestini;

    // Aggiungi codice se vuoi
    inizia(N, M, S, cestini);

    string risposta;

    for (int i = 0; i < Q; i++) {
        char type;
        int a, b;
        cin >> type >> a >> b;

        if (type == 's') {
            sposta(a, b, cestini);
        } else {
            risposta.push_back(controlla(a, b, cestini));
        }
    }


    cout << "Case #" << t << ": " << risposta << endl;
}

int main() {
    // se preferisci leggere e scrivere da file
    // ti basta decommentare le seguenti due righe:

    freopen("cestini_input_3.txt", "r", stdin);
    freopen("cestini_output_3.txt", "w", stdout);

    int T;
    cin >> T;

    for (int t = 1; t <= T; t++) {
        solve(t);
    }

    return 0;
}