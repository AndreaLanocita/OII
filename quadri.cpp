#include <bits/stdc++.h>

using namespace std;

#define ll long long int

int quadri(int N, long long M, int V[]) {
    // Scrivete qui la vostra soluzione
    int res = -1;
    int i = 0, j = 0;
    ll sum = V[0];

    // anche solo il primo elemento va fuori limite
    if(sum > M) return 0;

    // se i supera j c'è un quadro che supera M --> ritorna 0
    // Se j è >= N-1 e la somma sta nel range sono arrivato alla fine senza dover togliere
    // più niente dalla somma
    while(j>=i && j<N-1) {
        // mando avanti quello di dx
        while(sum <= M && j < N-1) {
            j++;
            sum += V[j];
        }
        // la somma ora è maggiore di M, prima non lo era --> 
        // il risultato parziale è il numero di elementi che formano la somma prima dell'ultimo controllato
        // la somma degli elementi sarebbe j-i+1, senza l'ultimo tolgo 1
        if(res==-1) {   // non ho ancora trovato un valore di res
            if(sum <= M) res = j-i+1;   // corner case, arrivo ad N-1 ma la somma è valida
            else res = j-i;  
        }
        else {
            if(sum <= M) res = min(res, j-i+1);   // corner case, arrivo ad N-1 ma la somma è valida
            else res = min(res, j-i);
        } 

        // tolgo gli elementi di troppo
        while(sum > M && i<=j) {
            sum -= V[i];
            i++;
        }
    }

    if(j<i || res == -1) return 0;
    return min(res, (j-i+1));    // essendo alla fine non ho potuto aggiungere un elemento in più per superare M --> riaggiungo 1
}

static FILE *fr, *fw;

// Declaring variables
static int N;
static long long M;
static int* V;
static int B;

// Declaring functions
int quadri(int N, long long M, int* V);

int main() {
	fr = stdin;
	fw = stdout;

	// Iterators used in for loops
	int i0;

	// Reading input
	fscanf(fr, "%d %lld", &N, &M);
	V = (int*)malloc(N * sizeof(int));
	for (i0 = 0; i0 < N; i0++) {
	    fscanf(fr, "%d", &V[i0]);
	}

	// Calling functions
	B = quadri(N, M, V);

	// Writing output
	fprintf(fw, "%d\n", B);
	
	fclose(fr);
	fclose(fw);
	return 0;
}