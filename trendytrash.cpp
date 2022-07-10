#include <bits/stdc++.h>

using namespace std;

int n_righe, n_colonne;

int init(int N, int M, int righe_counter[], int colonne_counter[], vector<string> &S) {
    // inizializzo i vettori counter, contano quanti 1 ci sono in una riga / colonna
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            if(S[i][j] == '1') {
                righe_counter[i] += 1;
                colonne_counter[j] += 1;
            }
        }
    }
    return 0;
}

int check_colonna(int N, int c, int colonne_counter[], int righe_counter[]) {
    if(n_righe == colonne_counter[c]) {  // in questa colonna ci sono solo 1
        // sto togliendo uno da ogni riga
        for(int i=0; i<N; i++) righe_counter[i] -= 1;
        return 1;
    }
    if(colonne_counter[c] == 0) {  // in questa colonna ci sono solo 0
        return 1;
    }

    return 0;
}

int check_riga(int M, int r, int colonne_counter[], int righe_counter[]) {
    if(n_colonne == righe_counter[r]) {  // in questa riga ci sono solo 1
        // sto togliendo uno da ogni colonna
        for(int i=0; i<M; i++) colonne_counter[i] -= 1;
        return 1;
    }
    if(righe_counter[r] == 0) {  // in questa colonna ci sono solo 0
        return 1;
    }

    return 0;
}

int pulisci(int N, int M, vector<string> S) {
    n_righe = N;
    n_colonne = M;
    
    int righe[N] = {}, colonne[M] = {}, righe_counter[N] = { }, colonne_counter[M] = { };
    int c_r = 1, c_c = 1, ri = 0, ci = 0, temp_c, temp_r;

    init(N, M, righe_counter, colonne_counter, S);

    while(c_r == 1 || c_c == 1) {
        // copio le variabili, mi servono per risparmiare tempo. Se ho tolto solo righe controllo solo le colonne e viceversa
        temp_c = c_c;
        temp_r = c_r;

        // reset variabili di controllo
        c_r = 0, c_c = 0;

        // variabile di controllo per trovare la prima riga / colonna agibile
        int controllo = 0;

        // ho tolto almeno una colonna nel loop precedente, controllo le righe
        if(temp_c == 1) {
            for(int i=ri; i<N; i++) {
                // conotrollo che quetsa riga non sia già eliminata
                if(righe[i] == 1) continue;

                // controllo se = 1 ho tolto la riga, faccio update
                if(check_riga(M, i, colonne_counter, righe_counter) == 1) {
                    righe[i] = 1;

                    // questa variabile è = 0 all'inizio del loop e cambia solo
                    // se sposto almeno un sacchetto
                    c_r = 1;
                    n_righe -= 1;
                }
                // prendo la prima riga agibile, da utilizzare nel prossimo loop
                else if(controllo == 0) {
                    ri = i;
                    controllo = 1;
                }
            }
        }
        
        // variabile di controllo per trovare la prima riga / colonna agibile
        controllo = 0;
        // ho tolto almeno una riga nel loop precedente, controllo le colonne
        if(temp_r == 1) {
            for(int h=ci; h<M; h++) {
                // conotrollo che quetsa colonna non sia già eliminata
                if(colonne[h] == 1) continue;

                // controllo se = 1 ho tolto la colonna, faccio update
                if(check_colonna(N, h, colonne_counter, righe_counter) == 1) {
                    colonne[h] = 1;

                    // copio in questa variabile, che è = 0 all'inizio del loop e cambia solo
                    // se sposto almeno un sacchetto
                    c_c = 1;
                    n_colonne -= 1;
                }
                else if(controllo == 0) {
                    ci = h;
                    controllo = 1;
                }
            }
        }

    }   
    
    return (n_righe * n_colonne);
}

int main() {
  int N, M;

  cin >> N >> M;

  vector<string> S(N);

  for(int i = 0; i < N; i++) {
    cin >> S[i];
  }

  cout << pulisci(N, M, S) << endl;

  return 0;
}