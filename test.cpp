#include <bits/stdc++.h>

using namespace std;

int N=3;
int M=1000;
long long massimo = 0;

int succ(long long numero, int cifra) {
    int cifre = ((int) log10(numero)) + 1;
    return numero + cifra*pow(10, cifre);
}

bool isSafe(long long numero) {
    int prev = 0;
    int cifre = ((int) log10(numero)) + 1;

    // controllo che n cifre non sia maggiore di N
    if (cifre > N) return false;

    // controllo che nessuna consecutiva cifra sia uguale
    for(int i=cifre; i>0; i--) {
        int temp = numero/pow(10, i-1);
        if(i==1) {
            if(numero == prev) return false;
        }
        else if(temp == prev) return false;
        prev = numero/(pow(10, i-1));
        numero = numero - pow(10, i-1) * prev;
    }

    return true;
}

int main() {
    cout << isSafe(996);
    return 0;
}