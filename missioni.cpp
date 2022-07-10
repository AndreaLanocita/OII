#include <bits/stdc++.h>

using namespace std;

struct Missione {
    int durata;
    int fine;
};

Missione missioni[101];
int soluzioni[366]; // uno per ogni giorno

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");

    int n;
    in >> n;

    for(int i=0; i<n; i++) {
        in >> missioni[i].durata >> missioni[i].fine;
    }

    for(int i=0; i<n; i++) {    // per ogni missione
        // cerco la soluzione migliore:
        // partendo dall'ultimo giorno che mi permetta di terminare quella missione (sottraggo la durata)
        // aggiungo uno al numero di missioni massime precedenti (quelle che posso fare facendo anche questa missione)
        // se è maggiore delle missioni massime che posso fare quel giorno (già segnate nel vettore)
        
        // nelle istanze successive del ciclo, continuo a muovermi indietro per i giorni della missione e ripeto l'operazione

        // l'eventuale sovrapposizione di missioni non è un problema in quanto il max n di missioni per un giorno
        // viene calcolato ogni volta a partire da uno di un giorno precedente che permetta di concludere la missione

        // Inoltre, partendo dal giorno prima all'ultimo giorno possibile per iniziare la missione, il ciclo for continua a diminuire
        // fino a zero (aggiungendo ogni volta la durata in modo da dare il tempo di "completare la missione") per controllare i valori
        // da cui prendere le missioni massime precedenti, quindi il risultato è sempre ottimo

        for(int j=missioni[i].fine - missioni[i].durata; j>=0; j--) {
            if(soluzioni[j] + 1 > soluzioni[j+missioni[i].durata]) {
                // le missioni massime del giorno prima dell'inizio + 1 
                // è maggiore delle missioni massime del giorno della fine, allora lo cambio
                soluzioni[j+missioni[i].durata] = soluzioni[j] + 1;
            }
        }
    }

    int max = soluzioni[0];
    for(int i=0; i<366; i++) {
        if(soluzioni[i] > max)
            max = soluzioni[i];
    }
    out << max;
}