#include <bits/stdc++.h>
#include <climits>

using namespace std;

#define ll long long int

struct candela {
	int indice;
	ll miccia, base;
};

bool func(candela a, candela b) {
	if(a.miccia < b.miccia) return true;
	return false;
}

void brucia(int N, vector<int> &M, vector<int> &B, vector<long long> &T) {
	candela tmp;
	vector<candela> candele;
	for(int i=0; i<N; i++) {
		tmp.indice = i;
		tmp.miccia = M[i];
		tmp.base = B[i];
		candele.push_back(tmp);
	}
	sort(candele.begin(), candele.end(), func);

	stack<candela> s;
	vector<int> adj[N];
	// per ogni candela devo solo trovare la prima che la accende da dx e sx
	// da dx
	s.push(candele[candele.size()-1]);
	for(int i=candele.size()-2; i>=0; i--) {
		// questa candela accende l'ultima messa nello stack?
		// se non accende la prima dello stack, di sicuro non accende neanche le altre
		while((!s.empty() && candele[i].base >= s.top().miccia) || (!s.empty() && candele[i].miccia == s.top().miccia)) {
			// se si, tolgo dallo stack e aggiungo ad adj
			if(candele[i].miccia == s.top().miccia) {
				adj[candele[i].indice].push_back(s.top().indice);
				adj[s.top().indice].push_back(candele[i].indice);
			}
			else {
				adj[candele[i].indice].push_back(s.top().indice);
			} 
			s.pop();
		}

		// in ogni caso, aggiungo la nuova candela allo stack
		s.push(candele[i]);
	}
	
	stack<candela> q;
	q.push(candele[0]);
	T[0] = 0;
	for(int i=1; i<T.size(); i++) T[i] = LLONG_MAX;

	for(int i=1; i<candele.size(); i++) {
		while(!q.empty() && candele[i].base <= q.top().miccia) {
			adj[candele[i].indice].push_back(q.top().indice);
			q.pop();
		}

		q.push(candele[i]);
	}

	int n = 0, vicino;
	ll costo; 
	int visitato[N] = { };
	priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;	// distanza, indice arrivo
	pq.push({0, 0});
	for(int i=0; i<N; i++) {
		// trovo quello con distanza minore
		while(!pq.empty()) {
			n = pq.top().second;
			if(visitato[n] == 0 && pq.top().first == T[n]) break;
			pq.pop();
		}
		if(pq.empty()) break;
		pq.pop();
		visitato[n] = 1;

		// controllo gli adiacenti
		for(int i=0; i<adj[n].size(); i++) {
			vicino = adj[n][i];
			costo = abs(M[vicino] - M[n]) + T[n];
			if(costo < T[vicino] && visitato[vicino] == 0) {
				T[vicino] = costo;
				pq.push({T[vicino], vicino});
			} 
		}
	}

	for(int i=0; i<T.size(); i++) {
		if(T[i] == LLONG_MAX) T[i] = -1;
	}
}

void brucia(int N, vector<int> &M, vector<int> &B, vector<long long> &T);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
	int n;
	cin >> n;
	
	vector <int> m(n), b(n);
	vector <long long> t(n, 0);
	
	for (int i = 0; i < n; i++)
		cin >> m[i] >> b[i];
	
	brucia(n, m, b, t);
	for (int i = 0; i < n; i++)
		cout << t[i] << " ";
	cout << "\n";
	
	return 0;	
}