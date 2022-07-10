#include <stdio.h>
#include <assert.h>

#define MAXN 100000

// NB quando sfanghi una voce la rimuovi dal negativo e aggiungi al positivo, devi 
// moltiplicarla per due 

int sfangate(int N, int V[]) {
    // Mettete qui il codice della soluzione
    return 42;
}


int V[MAXN];

int main() {
    FILE *fr, *fw;
    int N, i;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(1 == fscanf(fr, "%d", &N));
    for(i=0; i<N; i++)
        assert(1 == fscanf(fr, "%d", &V[i]));

    fprintf(fw, "%d\n", sfangate(N, V));
    fclose(fr);
    fclose(fw);
    return 0;
}