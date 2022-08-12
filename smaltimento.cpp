#include <bits/stdc++.h>

using namespace std;

int inizio, res;
int dfs(int nodo, int adj[], int proibito[]) {
	// segno il primo arco che risulta sicuramente in un ciclo come impraticabile
	for(int vicino: adj[nodo].keys()) {
		// è un ciclo
		if(counter[vicino] != 0) {
			adj[nodo].erase(vicino);	// per sicurezza
			inizio = vicino;
			return -1;
		}
		res = dfs(vicino, adj, proibito);
		if(res == -1) {
			if(nodo == inizio) {
				adj[nodo].erase(vicino);
				continue;
			} 
			if(adj[nodo].size() > 1) {
				adj[nodo].erase(vicino);
				return -2;
			} 
			return -1;
		} 
		if(res == -2) {

			return -2;
		} 
	}
}

long long smaltisci(int N, int M, vector<int> A, vector<vector<int>> B) {
	unordered_map<int, int> adj[N];
	unordered_map<int, int> visitato[N];	// nodo, id
	int distanze[N];

	for(int i=0; i<M; i++) {
		// per ogni nodo mi salvo i processi a cui va, a cui posso poi accedere con B[]
		adj[A[i]][i] = 1;	
	}

	queue<pair<int, int>> q;	// nodo, id processo. Se k>2 dò ai processi id differenti
	q.push({0, 0});

}

long long smaltisci(int N, int M, vector<int> A, vector<vector<int>> B);

int main() {
	int N, M;

	cin >> N >> M;

	vector<int> A(M), K(M);
	vector<vector<int>> B(M);

	for (int i = 0; i < M; i++) {
	cin >> A[i] >> K[i];

	B[i].resize(K[i]);
	for (int j = 0; j < K[i]; j++) {
		cin >> B[i][j];
	}
	}

	cout << smaltisci(N, M, A, B) << "\n";
}