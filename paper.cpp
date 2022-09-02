#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>

// tarjan's algo for SCC --> conto gli elementi di quella a monte
int counter = 0, v, last, ress = 0;	// assegna ids
vi onStack, id, low;
stack<int> stackk;

void dfs(int n, vi adj[], int pre) {
	// inizializzo id = low
	id[n] = low[n] = counter++;

	// aggiungo il nodo allo stackk
	stackk.push(n);
	onStack[n] = 1;

	// controllo vicini
	for(int vicino: adj[n]) {
		// se non visitato visito
		if(id[vicino] == -1) dfs(vicino, adj, n);
		// controllo se fa parte stessa SCC
		if(onStack[vicino] == 1) low[n] = min(low[vicino], low[n]);
	}

	// controllo se sono arrivato alla fine della SCC
	if(low[n] == id[n]) {
		while(true) {
			// reset
			v = stackk.top();
			onStack[v] = 0;
			low[v] = id[n];	// why
			stackk.pop();

			// fine della SCC
			if(v == n) break;
		}
	}
	last = n;	// ultimo nodo chiuso --> parte SCC a monte
}

void conto(int n, vi adj[], int visitato[]) {
	visitato[n] = 1;
	if(low[n] == low[last]) ress++;
	counter++;

	for(int vicino: adj[n]) {
		if(visitato[vicino] == 1) continue;
		conto(vicino, adj, visitato);
	}
}

int paper(int N, int M, int A[], int B[]) {
	vi adj[N+1];

	id.assign(N+1, -1); low.resize(N+1); onStack.assign(N+1, 0); 

    for(int i=0; i<M; i++) {
		adj[A[i]].push_back(B[i]);
	}

	for(int i=1; i<N+1; i++) 
		if(id[i] == -1) 
			dfs(i, adj, -1);

	// controllo numero elementi SCC a monte
	int visitato[N+1] = { };
	counter = 0;
	conto(last, adj, visitato);

	if(counter != N) return 0;	// partendo da SCC a monte faccio dfs totale per controllare che tutti i nodi siano raggiungibili
	return ress;
}

static FILE *fr, *fw;

// Declaring variables
static int N;
static int M;
static int* A;
static int* B;
static int res;

// Declaring functions
int paper(int N, int M, int* from, int* to);

int main() {
	fr = stdin;
	fw = stdout;

	// Iterators used in for loops
	int i0;

	// Reading input
        fscanf(fr, "%d %d", &N, &M);
	A = (int*)malloc(M * sizeof(int));
	B = (int*)malloc(M * sizeof(int));
	for (i0 = 0; i0 < M; i0++) {
            fscanf(fr, "%d %d", &A[i0], &B[i0]);
	}

	// Calling functions
	res = paper(N, M, A, B);

	// Writing output
        fprintf(fw, "%d\n", res);
	
	fclose(fr);
	fclose(fw);
	return 0;
}

