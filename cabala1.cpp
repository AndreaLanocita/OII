#include <bits/stdc++.h>

using namespace std;

int N, M;
int massimo = 0;

int succ(long long numero, int cifra) {
    int cifre = ((int) log10(numero)) + 1;
    return numero + cifra*pow(10, cifre);
}

int isSafe(long long numero) {
    int cifre = ((int) log10(numero)) + 1;

    // controllo che n cifre non sia maggiore di N
    if (cifre > N) return -2;
    
    return true;
}

// tenere cifre ed incrimentarlo ogni volta, togliere sia isSafe che succ e fare tutto in occulta

long long occulta(long long numero, int ultima) {
    // controllo se massimo è il massimo ottenibile, in quel caso concludo
    if(massimo == M-1) return -1;

    // controllo sia valida
    if(isSafe(numero) == -1) return 0;
    if(isSafe(numero) == -2) return -2;

    // controllo se mod > massimo
    if(numero%M > massimo) massimo = numero%M;

    // genero numeri successivi
    int res;
    if(ultima != 3) {
        res = occulta(succ(numero, 3), 3);
        if(res == -1) return -1;
        if(res==-2) return 0;
    }
    
    if(ultima != 6) {
        res = occulta(succ(numero, 6), 6);
        if(res == -1) return -1;
        if(res==-2) return 0;
    }

    if(ultima != 9) {
        res = occulta(succ(numero, 9), 9);
        if(res == -1) return -1;
        if(res==-2) return 0;
    }

    return 0;
}


int main() {
    FILE *fr, *fw;
    int T, i;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(1 == fscanf(fr, "%d", &T));
    for (i=0; i<T; i++) {
        massimo = 0;
        assert(2 == fscanf(fr, "%d %d", &N, &M));
        occulta(3, 3);
        occulta(6, 6);
        occulta(9, 9);
        fprintf(fw, "%d ", massimo);
    }

    fprintf(fw, "\n");
    fclose(fr);
    fclose(fw);
    return 0;
}