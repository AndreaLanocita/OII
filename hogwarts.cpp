#include <bits/stdc++.h>
#include <climits>

using namespace std;

int raggiungi(int N, int M, int A[], int B[], int inizio[], int fine[]) {
	// dijikstra
	int V[N] = { };	// visitato
	int D[N];	// distanze
	int n = 0;	// nodo che controllo

	// inizializzo
	vector<pair<int, pair<int, int>>> adj[N];	// {arrivo, {inizio, fine}}
	for(int i=0; i<M; i++) {
		adj[A[i]].push_back({B[i], {inizio[i], fine[i]}});
		adj[B[i]].push_back({A[i], {inizio[i], fine[i]}});
	}

	// distanza, arrivo
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> distanze;
	distanze.push({0, 0});
	D[0] = 0;
	for(int i=1; i<N; i++) D[i] = INT_MAX;
	
	for(int i=0; i<N; i++) {
		if(n == N-1) return D[N-1];

		// cerco nodo più vicino non visitato
		while(!distanze.empty()) {
			n = distanze.top().second;
			// è up-to-date? l'ho già visitato?
			if(D[n] == distanze.top().first && V[n] == 0) break;
			// se è useless la tolgo e continuo a cercare
			distanze.pop();
		}
		// queue vuota, o sono arrivato o non posso arrivare
		if(distanze.empty()) break;
		distanze.pop();

		// lo visito
		V[n] = 1;
		// controllo i nodi adiacenti
		for(int j=0; j<adj[n].size(); j++) {	
			// controllo se non ho visitato il nodo e se posso migliorare la sua distanza
			if(V[adj[n][j].first] == 0 && adj[n][j].second.second > D[n] && max(adj[n][j].second.first, D[n]) + 1 < D[adj[n][j].first]) {
				D[adj[n][j].first] = max(adj[n][j].second.first, D[n]) + 1;
				distanze.push({D[adj[n][j].first], adj[n][j].first});
			}
		}
	}

	if(D[N-1] == INT_MAX) return -1;
	return D[N-1];
}

static FILE *fr, *fw;

// Declaring variables
static int N;
static int M;
static int* A;
static int* B;
static int* inizio;
static int* fine;
static int tempo;

// Declaring functions
int raggiungi(int N, int M, int A[], int B[], int inizio[], int fine[]);

int main() {
	fr = stdin;
	fw = stdout;

	// Reading input
	fscanf(fr, " %d %d", &N, &M);
	A = (int*)malloc((M) * sizeof(int));
	B = (int*)malloc((M) * sizeof(int));
	inizio = (int*)malloc((M) * sizeof(int));
	fine = (int*)malloc((M) * sizeof(int));
	for (int i0 = 0; i0 < M; i0++) {
		fscanf(fr, " %d %d %d %d", &A[i0], &B[i0], &inizio[i0], &fine[i0]);
	}

	// Calling functions
	tempo = raggiungi(N, M, A, B, inizio, fine);

	// Writing output
	fprintf(fw, "%d\n", tempo);

	fclose(fr);
	fclose(fw);
	return 0;
}
