#include <bits/stdc++.h>

using namespace std;

int N, M;
int massimo = 0;

int div(long long numero) {
    int cifre;
    long long temp = numero;
    int prev = 0;

    // controllo che tutte le cifre siano divisori di 3, se no rimedio
    cifre = (int) log10(numero) + 1;
    for(int i=cifre; i>0; i--) {
        if(i==1 && temp%3 != 0) {
            if (temp<3) numero = numero + (3 - temp%3);
            else numero = numero + temp%3;
        }
        if((temp/10) % 3 != 0) {
            if(temp/10 < 3) numero = numero + pow(10, i-1) * (3 - ((temp/10) % 3));
            else numero = numero + pow(10, i-1) * ((temp/10) % 3);
        }

        if(temp==0) numero = numero+3;
        else if((int) log10(temp) + 1 <= i-1) numero = numero + pow(10, i-1) * 3;

        temp = temp - pow(10, i-1) * (temp/10);
    }
    return numero;
}

bool isSafe(long long numero) {
    int cifre;
    int prev = 0;

    // controllo che nessuna consecutiva cifra sia uguale
    cifre = (int) log10(numero) + 1;
    for(int i=cifre; i>0; i--) {
        if(i==1 && numero == prev) return false;
        if(numero/10 == prev) return false;
        prev = numero/10;
        numero = numero - pow(10, i-1) * (numero/10);
    }

    return true;
}

long long occulta(long long numero) {
    int temp;
    // controllo sia valido, se non è multiplo di tre aggiungo mod 3, tutte cifre !=
    numero = div(numero);
    if(isSafe(numero) == false) return occulta(numero+3);

    // Controllo se + cifre di N
    if(numero >= pow(10, N)) return massimo;

    // per ogni valido controllo se mod M maggiore max
    temp = numero % M;
    if(temp > massimo) massimo = temp;

    // Genero numero aggiungendo sempre tre
    return occulta(numero+3);
}


int main() {
    FILE *fr, *fw;
    int T, i;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(1 == fscanf(fr, "%d", &T));
    for (i=0; i<T; i++) {
        assert(2 == fscanf(fr, "%d %d", &N, &M));
        occulta(3);
        fprintf(fw, "%d ", massimo);
    }

    fprintf(fw, "\n");
    fclose(fr);
    fclose(fw);
    return 0;
}