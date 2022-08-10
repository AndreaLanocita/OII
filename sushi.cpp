#include <bits/stdc++.h>

using namespace std;

int sushi(int N, int B, vector<int> A) {
	int sol[B+5] = { };
	/* per contare le ripetizioni, vedo quale punto del vettore sol, inizializzato
	come se fossi arrivato a 0, raggiungo aggiungendo ciascun piatto dall'ultimo punto in cui
	sono arrivato */
	deque<int> caselle;	// aggiungo all'inizio, tolgo dalla fine --> FIFO
	sol[0] = 1;
	caselle.push_back(0);
	int res = 0, size_tmp, aggiunti, controllati = 1, controllati_tmp = 0;

	while(sol[B] != 1 && !caselle.empty()) {
		res++;
		for(int i=0; i<N; i++) {
			aggiunti = 0;
			size_tmp = caselle.size();
			for(int j=0; j<size_tmp; j++) {
				if(caselle[j+aggiunti]+A[i]<=B && sol[caselle[j+aggiunti]+A[i]] == 0) {
					sol[caselle[j+aggiunti]+A[i]] = 1;
					caselle.push_front(caselle[j+aggiunti]+A[i]);
					aggiunti++;
					controllati_tmp++;
				}
			}
		}

		for(int j=0; j<controllati; j++) caselle.pop_back();
		controllati = controllati_tmp;
		controllati_tmp = 0;
	}
	
	if(sol[B] == 1) return res;
	return -1;
}

int main() {
	// se preferisci leggere e scrivere da file
	// ti basta decommentare le seguenti due righe:

	// ifstream cin("input.txt");
	// ofstream cout("output.txt");

	int N, B;
	cin >> N >> B;

	vector<int> A(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	cout << sushi(N, B, A) << endl;

	return 0;
}
