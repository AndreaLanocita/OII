#include <bits/stdc++.h>

using namespace std;

// provo con b_search

int check(long long int bound, int N, long long int L, long long int D[], long long int P[]) {
	long long int percorso = D[0];

	for(int i=0; i<N-1; i++) {
		// vale la pena di andare in spiaggia? Se si, posso?
		if(percorso > P[i] && P[i] + percorso <= bound) percorso = P[i];

		// vado avanti alla spiaggia dopo
		percorso += (D[i+1] - D[i]);

		if(percorso > bound) return 0;
	}
	// sono alla ultima spiaggia ed è tutto valido
	// vale la pena di andare in spiaggia? Se si, posso?
	if(percorso > P[N-1] && P[N-1] + percorso <= bound) percorso = P[N-1];

	// vado alla fine
	percorso += (L - D[N-1]);

	if(percorso > bound) return 0;

	return 1;
}

long long int percorri(int N, long long int L, long long int D[], long long int P[]) {
	long long int l=0, r=L;
	long long int mid;

	while(l<r) {
		mid = (r+l)/2;
		// rispetta la condizione, posso ridurre la distanza
		if(check(mid, N, L, D, P) == 1) r = mid;

		// non rispetta la condizione, aumento
		else l = mid+1;
	}

	return r;
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