#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define popb pop_back
#define vi vector<int>
#define pi pair<int, int>
#define vp vector<pi>
#define ll long long int
#define pl pair<ll, ll>
#define vl vector<ll>
#define vpl vector<pl>
#define omap map<int, int>
#define umap unordered_map<int, int>
#define pq priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>>

int conta(int N, vector<int> V) {
	int precedente[N], successivo[N], i = 0, j=2, current, primo_valido = 0, res = 0;
	precedente[0] = -1; successivo[N-1] = -1;
	for(int h=1; h<N; h++) precedente[h] = h-1;
	for(int h=0; h<N-1; h++) successivo[h] = h+1;

	while(j!=-1) {
		current = V[i] ^ V[precedente[j]] ^ V[j];

		while(current != 0) {
			if(successivo[successivo[i]] == -1 || successivo[i] == -1) return res;
			i = successivo[i]; j = successivo[j];
			if(j==-1 || i==-1) return res;
			current = current ^ V[precedente[i]] ^ V[j];
		}
		if(i<=primo_valido && primo_valido <= j) primo_valido = successivo[j];

		// cambio i precedenti e successivi
		if(precedente[i] != -1) successivo[precedente[i]] = successivo[j];
		if(successivo[j] != -1) precedente[successivo[j]] = precedente[i];

		// ricomincio da capo
		res += 3;
		i = primo_valido;
		if(i==-1 || successivo[i] == -1) break;
		j = successivo[successivo[i]];
	}
	return res;
}

int main() {
	// se vuoi leggere da file decommenta queste due linee
	assert(freopen("input.txt", "r", stdin));
	// assert(freopen("output.txt", "w", stdout));

	int n;
	cin >> n;

	vector<int> d(n);
	for (auto &x : d)
		cin >> x;

	int ans = conta(n, d);
	cout << ans << '\n';
}