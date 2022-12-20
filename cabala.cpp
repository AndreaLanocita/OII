#include <bits/stdc++.h>

using namespace std;

int N, M;
long long massimo = 0;
long long res;
int v[3] = {3, 6, 9};

// ncifre = 0, 1, 2
long long occulta(long long numero, int ultima_cifra, int ncifre) {
    // controllo il modulo
    if(numero % M > massimo) {
        massimo = numero % M;
        res = numero;
    } 

    // aggiungo cifra
    for(int i=0; i<3; i++) {
        if(ncifre == N) break;
        if(i==ultima_cifra) continue;
        occulta(numero * 10 + v[i], i, ncifre+1);
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
        assert(2 == fscanf(fr, "%d %d", &N, &M));
        massimo = 0, res = 0;
        occulta(3, 0, 1);
        occulta(6, 1, 1);
        occulta(9, 2, 1);
        fprintf(fw, "%d ", massimo);
    }

    fprintf(fw, "\n");
    fclose(fr);
    fclose(fw);
    return 0;
}