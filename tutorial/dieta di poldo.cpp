#include <bits/stdc++.h>

using namespace std;

int N; // n panini
int peso[10000]; // peso panini
int sol[10000]; // mangio panino / non mangio panino

// CALCOLO IL MASSIMO NUMERO DI PANINI CHE MANGEREI NEL CASO IN CUI PRENDESSI ANCHE IL PANINO K (COME ULTIMO) --> NON
// TENGO CONTO DEI CASI, SO CHE IL PESO DEL PANINO K+1 DEVE ESSERE MAGGIORE DI QUELLO K PER POTERLO MANGIARE
// SCORRO IL VETTORE SOLUZIONI DA K A 0 CONTROLLANDO MANO A MANO I PESI FINO A QUANDO QUESTO NON SUCCEDE

int dp(int k) {

    // caso base
    if(k==-1) return 0;

    // controllo se ho già sol
    if(sol[k] != -1) return sol[k];

    //  calcolo
    int max = 1;    // in ogni caso prendo il panino
    for(int i=k-1; i>=0; i--) {
        dp(i);
        if(peso[i] > peso[k] && sol[i] + 1 > max) max = sol[i] + 1;
    }
    sol[k] = max;

    // return
    return sol[k];
}

int main() {
    int temp;
    ifstream indata; // indata is like cin
    ofstream outdata;
    indata.open("input.txt"); // opens the file

    indata >> N;
    for (int i=0; i<N; i++) { // keep reading until end-of-file
        indata >> temp; // sets EOF flag if no value found
        peso[i] = temp;
        sol[i] = -1;
        sol[i] = -1;
    }
    dp(N-1);
    indata.close();

    outdata.open("output.txt");

    temp = 0;
    for (int i=0; i<N; i++) { 
        if(sol[i] > temp) temp = sol[i];
    }
    outdata << temp << endl;
    outdata.close();

    return 0;
}