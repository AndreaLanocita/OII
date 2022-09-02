#include <bits/stdc++.h>
#include <climits>

using namespace std;

#define ll long long

struct tri {
	ll arrivo, costo, flag;
};

#define vp vector<tri>
#define ll long long

long long fuggi(int N, int M, vector <int> A, vector <int> B, vector <int> T, vector <int> R){
	vp adj[N+1]; ll tmp1; tri tmp;
	ll distanze[N+1]; int visitato[N+1] = { };
	for(int i=0; i<M; i++) {
		tmp.arrivo = B[i]; tmp.costo = T[i]; tmp.flag = R[i];
		adj[A[i]].push_back(tmp);
	}

	priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> q;	// costo, arrivo
	for(int i=1; i<N; i++) {
		distanze[i] = LLONG_MAX;
		q.push({LLONG_MAX, i});
	}
	 
	distanze[0] = 0; 
	q.push({0, 0});
	ll n;
	// come se non chiudesse nessuna via
	for(int i=0; i<N+1; i++) {
		// cerco più vicino
		while(!q.empty()) {
			n = q.top().second;
			if(visitato[n] == 0 && q.top().first == distanze[n]) break;
			q.pop();
		}
		if(q.empty()) break;
		q.pop();
		visitato[n] = 1;

		if(n==N-1) break;

		// aggiorno vicini
		for(tri vicino: adj[n]) {
			if(visitato[vicino.arrivo] != 0) continue;
			if(distanze[vicino.arrivo] > distanze[n] + vicino.costo) {
				distanze[vicino.arrivo] = distanze[n] + vicino.costo;
				q.push({distanze[vicino.arrivo], vicino.arrivo});
			}
		}
	}
	return distanze[N-1];
}