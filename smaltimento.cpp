#include <bits/stdc++.h>
#include <climits>

using namespace std;

#define pb push_back
#define popb pop_back
#define vi vector<int>
#define pi pair<vi, int>
#define vp vector<pi>
#define ll long long int
#define pl pair<ll, ll>
#define vl vector<ll>
#define vpl vector<pl>
#define omap map<int, int>
#define umap unordered_map<int, int>
#define pq priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>>

#define INF LLONG_MAX

ll res = 0;
void dfs(int n, vector<vi> adj[], int d[]) {
	for(vi processi: adj[n]) {
		// trovato fine
		if(processi.size() == 0) {
			d[n] = 1;
			break;
		}

		parziale = 0;
		for(int vicino: processi.first) {
			if(antenati.find(vicino) != antenati.end()) {
				flag = 1;
				break;
			} 
			dfs(vicino, adj, d);
			// failsafe
			if(d[vicino]==INF) {
				parziale = INF;
				break;
			}
			parziale += d[vicino];
		}
		if(flag==0) d[n] = min(d[n], parziale+1);
		flag = 0;
	}
	res+=1;
	return ;
}

long long smaltisci(int N, int M, vector<int> A, vector<vector<int>> B) {
	// tengo un set nella pq con gli antenati di quel nodo
	// prima di andare ad un nodo controllo che non faccia parte del set
	// quando vado ad un vicino aggiorno il suo set --> rimane linearitmico (ma lo spazio diventa esponenziale)
	
	// subtask 4-5: dijikstra normale, con array visitato[]
	// subtask 6: dijikstra normale senza visitato

	// come distanze devo usare quelle della pq, però così potrei avere degli
	// elementi duplicati

	vector<vi> adj[N];	// tengo vettore che rappresenta i risultati del processo + costo è k
	for(int i=0; i<M; i++) {
		adj[A[i]].pb(B[i]);
	}
	ll d[N];
	for(int i=0; i<N; i++) d[i] = INF;
	

	return res;
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