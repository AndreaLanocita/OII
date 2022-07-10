#include <bits/stdc++.h>

using namespace std;

long long calc(long long n, long long mod, long long esp) {
    long long half, res;

    if (esp==0) return mod-1;
    if (esp==1) return n%mod;

    if(esp%2 != 0) {
        half = calc(n, mod, esp/2) * calc(n, mod, esp/2+1);
    }
    else {
        half = calc(n, mod, esp/2); half = half*half;
    }
    res = half % mod;
    return res;
}

void decifra(int N, int d, int L, int* messaggio, char* plaintext) {
    // Esempio di implementazione con un solo carattere da decifrare.
    // Mettiamo il risultato della decifrazione in plaintext[0] e il
    // carattere di fine stringa in plaintext[1].
    for(int i=0; i<L; i++) {
        plaintext[i] = calc(messaggio[i], N, d);
    }
    plaintext[L] = '\0';
}

