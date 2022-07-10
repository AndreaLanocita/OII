#include <bits/stdc++.h>

using namespace std;

int check(int numero, int sillabe, string parola, int N) {
    // usa str.find()
    
    for(int i=0; i<sillabe/2; i++) {
        for(int j=i*numero; j<i*numero+numero; j++) {
            if(parola[j] != parola[N-numero*(i+1)+(j-numero*i)]) return 0;
        }
    }
    cout << numero;
    return 1;
}


int main() {
    int N, sol;
    string parola;

    cin >> N >> parola;

    for(int h=N-1; h>=N/2; h--) {
        if(parola[h] == parola[0] && N%(N-h) == 0) {
            if(check(N-h, N/(N-h), parola, N) == 1) return 0;
        }
    }

    cout << N;
    return 0;
}