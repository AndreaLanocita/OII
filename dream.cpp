#include <bits/stdc++.h>

using namespace std;

#define ll long long 

ll MOD = 666013;
ll sum = 0;
ll counter; 

long long fast_exp(int numero, int esponente) {
    // caso base
    if(esponente == 0) return 1;
    // caso ricorsivo
    long long ricorsione = fast_exp(numero, esponente/2);
    ricorsione = (ricorsione % MOD * ricorsione % MOD)%MOD;
    // l'esponente è dispari --> esponente = esponente / 2 + esponente / 2 + 1 --> res = res_precedente^(esponente/2) * res_precedente^(esponente/2) * numero
    if(esponente % 2 == 1) return (ricorsione%MOD * numero % MOD)%MOD;
    // l'esponente è pari --> esponente = esponente / 2 + esponente / 2 --> res = res_precedente^(esponente/2) * res_precedente^(esponente/2)
    return ricorsione%MOD;
}

void ricorsiva(ll numero, ll cifre) {
    ll r = cifre / 2 - 1, l = r+1;
    ll numero_tmp;

    while(r>=0) {
        for(int i=1; i<10; i++) {
            if(r==0 && i==9) continue;
            numero_tmp = numero;
            numero_tmp = (numero_tmp%MOD + (fast_exp(10, l)%MOD)) % MOD;
            numero_tmp = (numero_tmp%MOD + (fast_exp(10, r)%MOD)) % MOD;
            sum = (sum%MOD + numero_tmp%MOD)%MOD;
            
            counter--;
            if(counter==0) return ; 
        }
        l++; r--;
    }
}

int main() {
    cin.tie(0); ios::sync_with_stdio(false);
	// uncomment the following lines if you want to read/write from files
	// ifstream cin("input.txt");
	// ofstream cout("output.txt");

	ll K, X;
    cin >> K >> X;
    counter = K;

    // insert your code here
    ll numero = (fast_exp(10, X-1)%MOD + 1)%MOD;
    sum = (sum%MOD + numero%MOD)%MOD;
    counter--;
    if(counter!=0) ricorsiva(numero, X);

    cout << sum << endl; // print the result
    return 0;
}
