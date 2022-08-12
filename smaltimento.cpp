#include <bits/stdc++.h>

using namespace std;

#define ll long long

int inizio, res, counter;
// DA RIFARE
int dfs(int nodo, unordered_map<int, int> adj[], int visitato[], vector<vector<int>> &B) {
	// segno il primo arco che risulta sicuramente in un ciclo come impraticabile
	counter = 0;
	for(auto i=adj[nodo].begin(); counter<adj[nodo].size(); i++) {
		counter++;
		for(int vicino: B[(*i).first]) {
			// è un ciclo
			if(visitato[vicino] != 0) {
				adj[nodo].erase((*i).first);	// per sicurezza
				inizio = vicino;
				return -1;
			}
			res = dfs(vicino, adj, visitato, B);
			if(res == -1) {
				if(nodo == inizio) {
					adj[nodo].erase((*i).first);
					continue;
				} 
				if(adj[nodo].size() > 1) {
					adj[nodo].erase((*i).first);
					return -2;
				} 
				return -1;
			} 
			if(res == -2) {
				if(nodo == inizio) continue;
				return -2;
			} 
		}
	}
	return 0;
}

int nodo;
ll costo=0, tmp;
int dp(int nodo, unordered_map<int, int> adj[], vector<vector<int>> &B, vector<ll> distanze) {
	// ho il res
	if(distanze[nodo] != -1) return distanze[nodo];

	counter = 0;
	for(auto i=adj[nodo].begin(); counter<adj[nodo].size(); i++) {
		counter++;
		// controllo se sono alla fine (caso base)
		if(B[(*i).first].size() == 0) {
			distanze[nodo] = 1;
			return 1;
		} 

		tmp = 0;
		for(int vicino: B[(*i).first]) {
			tmp += dp(vicino, adj, B, distanze) + 1;	// per ciascuno (*i).first, il costo è uguale al costo delle sostanze che produce +1 
		}
		distanze[nodo] = min(distanze[nodo], tmp);	// prendo il miglior (*i).first
	}
	return distanze[nodo];
}

long long smaltisci(int N, int M, vector<int> A, vector<vector<int>> B) {
	unordered_map<int, int> adj[N];
	vector<ll> distanze(N, -1);
	int visitato[N] = { };

	for(int i=0; i<M; i++) {
		// per ogni nodo mi salvo i processi a cui va, a cui posso poi accedere con B[]
		adj[A[i]][i] = 1;
	}
	dfs(0, adj, visitato, B);	// rimuovo cicli
	return dp(0, adj, B, distanze);
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