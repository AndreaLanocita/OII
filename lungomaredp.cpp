#include <bits/stdc++.h>

using namespace std;

// L'idea del programma è che andare a fare il bagno è come resettare il massimo
// ma vale la pena di fare questo solo se la passerella è meno lunga di ciò che viene
// prima, dato che se no solo tornando indietro dalla passerella faresti la stessa strada

long long int ricorsiva(int a, int N, long long int D[], long long int P[], long long int preso[], long long int non_preso[], long long int L) {
	// ho già il risultato - se sono asimettrici il programma non funziona
	if((preso[a] != -1 && non_preso[a] !=-1) && a != N) return 0;
	
	// caso base
	if(a==0) {
		preso[a] = D[a] + P[a];
		non_preso[a] = D[a];
		return 0;
	}

	// fine, eccezione --> aggiungo il pezzo dalla spiaggia alla fine
	if(a==N) {
		ricorsiva(a-1, N, D, P, preso, non_preso, L);

		return min(
				L - D[a-1] + P[a-1],
				non_preso[a-1] + L - D[a-1]
			);
	}
	
	// ricorsivo
	ricorsiva(a-1, N, D, P, preso, non_preso, L);

	preso[a] = min(
		P[a-1] + D[a] - D[a-1] + P[a],
		non_preso[a-1] + D[a] - D[a-1] + P[a]
	);
	non_preso[a] = min(
		P[a-1] + D[a] - D[a-1],
		non_preso[a-1] + D[a] - D[a-1]
	);

	// qui non può mai esserci il return finale, che è nell'eccezione
	return 0;
}

long long int percorri(int N, long long int L, long long int D[], long long int P[]) {
	long long int preso[N];  // max distanza percorsa senza bagno se prendo questa spiaggia
	long long int non_preso[N];  // max distanza percorsa senza bagno se non prendo questa spiaggia

	fill(preso, preso + N, -1);
	fill(non_preso, non_preso+N, -1);
	ricorsiva(N, N, D, P, preso, non_preso, L);
	
	return preso[N-1];
}

static FILE *fr, *fw;

// Declaring variables
static int N;
static long long int L;
static long long int* D;
static long long int* P;
static long long int C;

int main() {
	fr = stdin;
	fw = stdout;

	// Reading input
	fscanf(fr, " %d %lld", &N, &L);
	D = (long long int*)malloc((N) * sizeof(long long int));
	for (int i0 = 0; i0 < N; i0++) {
		fscanf(fr, " %lld", &D[i0]);
	}
	P = (long long int*)malloc((N) * sizeof(long long int));
	for (int i0 = 0; i0 < N; i0++) {
		fscanf(fr, " %lld", &P[i0]);
	}

	// Calling functions
	C = percorri(N, L, D, P);

	// Writing output
	fprintf(fw, "%lld\n", C);

	fclose(fr);
	fclose(fw);
	return 0;
}