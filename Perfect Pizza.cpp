#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    double P, Fattore, M, risultato, SommaTotale, Intermedio;
    vector<double> Somme;
    vector<double> Iniziale;

    cin >> N >> M;
    Somme.resize(N);

    // Loop tra i siti
    for (int i = 0; i < M; i++) {
        SommaTotale = 0;
        Iniziale.clear();

        // Loop in ciascun sito, tra gli ingredienti
        for (int h = 0; h < N; h++) {
            cin >> P;
            SommaTotale += P;
            Iniziale.push_back(P);
        }

        Fattore = 1000000 / SommaTotale;

        // Loop in ciascun sito, tra gli ingredienti
        for (int h = 0; h < N; h++) {
            Intermedio = Iniziale[h] * Fattore;
            Somme[h] = Somme[h] + Intermedio;
        }

    }

    for (int i = 0; i < N; i++) {
        risultato = Somme[i] / M;
        cout << (int) risultato;
        cout << " ";
    }

    return 0;
}