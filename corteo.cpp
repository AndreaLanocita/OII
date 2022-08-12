#include <bits/stdc++.h>

using namespace std;

// chiama questa funzione per spostare un corteo (non la devi implementare!)
// chi = 1..2
// dove = 0..N-1
void sposta(int chi, int dove);

queue<int> q;
int visitato[1050][1050];	// gli stati che non si devono ripetere sono quelli in cui entrambi i nodi sono nelle stesse posizioni

int bfs(int a, vector<int> adj[], vector<vector<int>> &distanze, int visitatoo[]) {
	distanze[a][a] = 0;
	q.push(a);
	visitatoo[a] += 1;	// aumento di 1 per non doverlo ri-inizializzare ogni volta
	int nodo;
	while(!q.empty()) {
		nodo = q.front();
		q.pop();

		for(int vicino: adj[nodo]) {
			if(visitatoo[vicino] > a) continue;
			distanze[a][vicino] = distanze[a][nodo] + 1;
			visitatoo[vicino] += 1;
			q.push(vicino);
		}
	}
	return 0;
}

queue<pair<int, int>> nextt;
int bfss(int t, int dt, int s, int ds, int minn, vector<int> adj[], vector<vector<int>> &distanze) {
	// uno stato è una coppia di nodi invece che un singolo
	visitato[t][s] = 1;
	nextt = { };
	nextt.push({t, s});
	int nodo_t, nodo_s;
	while(!nextt.empty()) {
		nodo_t = nextt.front().first;
		nodo_s = nextt.front().second;
		nextt.pop();

		if(nodo_t==dt && nodo_s==ds) return 1;

		for(int vicino_t: adj[nodo_t]) {
			// controllo che la distanza sia accettabile e il nodo non sia visitato
			if(distanze[vicino_t][nodo_s] >= minn && visitato[vicino_t][nodo_s] == 0) {
				visitato[vicino_t][nodo_s] = 1;
				nextt.push({vicino_t, nodo_s});
			}
		}

		for(int vicino_s: adj[nodo_s]) {
			// controllo che la distanza sia accettabile e il nodo non sia visitato
			if(distanze[nodo_t][vicino_s] >= minn && visitato[nodo_t][vicino_s] == 0) {
				visitato[nodo_t][vicino_s] = 1;
				nextt.push({nodo_t, vicino_s});
			}
		}
	}

	return -1;
}

int pianifica(int N, int M, int P1, int D1, int P2, int D2, int A[], int B[]) {
	vector<int> adj[N];
	vector<vector<int>> distanze(N, vector<int>(N));

	for(int i=0; i<M; i++) {
		adj[A[i]].push_back(B[i]);
		adj[B[i]].push_back(A[i]);
	}
	// calcolo distanze tra nodi
	int visitatoo[N] = { };
	for(int i=0; i<N; i++) bfs(i, adj, distanze, visitatoo);

	// b search
	int l=0, r=min(distanze[P1][P2], distanze[D1][D2])+1, mid;
	while(l<r) {
		mid = (l+r)/2;
		// funziona, alziamo l
		for(int i=0; i<N; i++) fill(begin(visitato[i]), begin(visitato[i])+N+1, 0);
		if(bfss(P1, D1, P2, D2, mid, adj, distanze) == 1) l=mid+1;
		else r=mid;
	}
	return r-1;
}

int pianifica(int N, int M, int P1, int D1, int P2, int D2, int A[], int B[]);

void sposta(int chi, int dove) {
	assert(chi == 1 || chi == 2);
	printf("%d %d\n", chi, dove);
}

int main() {
	int N, M, P1, D1, P2, D2, *A, *B, i;
	
	assert(2 == scanf("%d %d", &N, &M));
	assert(2 == scanf("%d %d", &P1, &D1));
	assert(2 == scanf("%d %d", &P2, &D2));
	
	A = (int*)malloc(M * sizeof(int));
	B = (int*)malloc(M * sizeof(int));

	for (i = 0; i < M; i++)
		assert(2 == scanf("%d %d", &A[i], &B[i]));
	
	printf("%d\n", pianifica(N, M, P1, D1, P2, D2, A, B));
}