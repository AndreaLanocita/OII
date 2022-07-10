#include <bits/stdc++.h>

using namespace std;

// Dijikstra algo:
// init: Metto dst del source = 0
// L'algo deve passare per ogni nodo, quindi faccio tutto in un for per ogni nodo
// 1 - trovo il nodo con distanza minore NON VISITATO e lo segno come visitato
// 2 - per ogni nodo adiacente controllo se la distanza già segnata è minore della distanza del
// precedente + il costo dello spigolo, in quel caso la sostituisco

// In questo caso devo tenere conto del tempo, ogni volta che arrivo ad una strada controllo
// se posso percorrerla o no mentre cerco gli adiacenti
// Se non posso percorrere nessuna strada (finisco il for mentre trovo gli adiacenti) passo all'istanza
// successiva 
// Se finisco ad un nodo con distanza = dst_max ((N-1)*101, massimo costo spigolo*numero dei nodi-1. 
// Caso limite in cui mettiamo tutti i nodi in fila) printo -1 e termino il programma

int N, strade;
int tempo;
int nodi[100000][4];
int dst[10000];
bool visitato[10000] = {0};
int tempo_rimanente[10000];
int dst_max;

// ritorna l'index del nodo con distanza minore
// nella prima istanza ritorna per forza il primo nodo perché è l'unico con distanza 0
int min_node() {
    int min_dst = dst_max;
    int min_nodo = 0;

    for(int i=0; i<N; i++) {
        if(dst[i] < min_dst && visitato[i] == 0) {
            min_dst = dst[i];
            min_nodo = i;
        }
    }
    return min_nodo;
}

int dijikstra() {
    int min_nodo;
    int adj;

    for(int i=0; i<N-1; i++) {
        min_nodo = min_node();
        visitato[min_nodo] = 1;
        
        // Non chiede il modo + veloce, solo un modo
        if(min_nodo==N-1) break;

        for(int j=0; j<strade; j++) {
            // per trovare i nodi adiacenti individuo in nodo[][] le strade che hanno nodo[][0] (l'inizio)
            // uguale a "min_nodo" e prendo nodo[][1] (la fine)
            if(nodi[j][0] == min_nodo) {
                adj = nodi[j][1];
                // Controllo se posso percorrere la strada. Se tempo rimanente di min_nodo - costo della strada è minore
                // di 0 controllo nodi[j][3]. Se è uguale a 1 skippo.
                if(tempo_rimanente[min_nodo] - nodi[j][2] < 0 && nodi[j][3] == 1) continue;

                // Controllo se la dst dell'adiacente è maggiore della distanza del precedente (min_nodo) +
                // il costo della strada (nodi[j][2])
                if(dst[adj] > dst[min_nodo] + nodi[j][2]) {
                    // Se si, cambio dst[adj] e tempo_rimanente[adj] = tempo_rimanente[min_nodo] - nodi[j][2]
                    dst[adj] = dst[min_nodo] + nodi[j][2];
                    tempo_rimanente[adj] = tempo_rimanente[min_nodo] - nodi[j][2];
                }
            }
        }
    }

    if(dst[N-1] == dst_max) {
        cout << -1;
        return 0;
    }

    cout << dst[N-1];
    return 0;
}

int main() {
    cin >> N >> strade >> tempo;
    dst_max = 101*(N-1);
    for(int i=0; i<strade; i++) {
        // inizio - fine - costo - esplode
        cin >> nodi[i][0] >> nodi[i][1] >> nodi[i][2] >> nodi[i][3];
    }
    for(int i=1; i<N; i++) {
        dst[i] = dst_max;
    }
    dst[0] = 0;
    tempo_rimanente[0] = tempo;

    dijikstra();

    return 0;
}