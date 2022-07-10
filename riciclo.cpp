#include <bits/stdc++.h>

using namespace std;

int counter = 0;
int recursive(long long number, int binary[], int depth) {
	// riempie l'array con il corrispettivo di number in binario, ma al contrario (il primo elemento è 2^0...)
    int remainder;

    remainder = number % 2;

    // sono arrivato alla fine
    if(number == 1) {
        binary[depth] += remainder;
        if(depth > counter) counter = depth;
        return 0;
    }

    number = number / 2;
    // non ho finito, vado avanti
    recursive(number, binary, depth+1);

    // finisce la ricorsione, aggiungo e ritorno
    binary[depth] += remainder;
    return 0;
}

// numero camion, numero tipi tipi rifiuti, portata massima camion, numero rifiuti di quel tipo
long long riciclo(int N, int M, vector<int> T, vector<int> P) {
	int binary[35] = { };	 // log2(10^10) = 33.22
	long long res = 0, capienza;
	int inizio_rifiuti = 0; // il tipo di rifiuto da cui iniziare a controllare, il primo != 0

	// per ogni numero, porto in binario e riempio un array che indica le potenze di due che possono
	// essere contenute nei camion. Ad es. se i camion avessero portata 4, 5 --> binary[1, 0, 2]
	for(long long i=0; i<N; i++) {
		recursive(T[i], binary, 0);
	}

	// itero all'interno di binary, riempio i cambio partendo dalla potenza più piccola salendo
	// per ciascuna, riempio a partire dai sacchetti con il peso più basso
	for(int i=0; i<counter+1; i++) {
		// itero nei sacchetti che possono stare in questa potenza di due
		// tiene conto del fatto che ci stanno più rifiuti più piccoli in una potenza di due più grande
		if(inizio_rifiuti<i) capienza = pow(2, i-inizio_rifiuti)*binary[i];
		else capienza = binary[i];

		for(int j=inizio_rifiuti; j<i+1 && j<M; j++) {
			// ci stanno tutti i rifiuti di quel tipo

			if(capienza >= P[j]) {
				capienza -= P[j];
				res += P[j];

				P[j] = 0;
				inizio_rifiuti = j+1;

				// passiamo alla categoria di rifiuti successiva, dobbiamo dividere la capienze * 2
				capienza /= 2;
				binary[i] = capienza;
			}
			else {	// non ci stanno tutti
				P[j] -= capienza;
				res += capienza;
				
				// binary[i] = 0;
				// dato che non ci stanno questi, di sicuro non ci stanno i prossimi
				break;
			}
		}
		// sono alla fine dei rifiuti
		if(inizio_rifiuti == M) return res;
	}

  	return res;
}

int main() {
	int N, M;

	cin >> N >> M;

	vector<int> T(N), P(M);

	for (int i = 0; i < N; i++) {
	cin >> T[i];
	}
	for (int i = 0; i < M; i++) {
	cin >> P[i];
	}

	cout << riciclo(N, M, T, P) << endl;

	return 0;
}
