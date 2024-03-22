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

int res = 0;

int ricorsiva(int primo_valido, int precedente[], int successivo[], int tmp_res, vi& V) {
	if(tmp_res > res) res = tmp_res;
	int i = primo_valido;
	if(i==-1 || successivo[i] == -1) return -1;
	int j = successivo[successivo[i]];

	while(j!=-1) {
		int current = V[i] ^ V[precedente[j]] ^ V[j];

		while(current != 0) {
			if(successivo[successivo[i]] == -1 || successivo[i] == -1) return res;
			i = successivo[i]; j = successivo[j];
			if(j==-1 || i==-1) return 0;
			current = current ^ V[precedente[i]] ^ V[j];
		}
		// tolgo e vado avanti
		if(i<=primo_valido && primo_valido <= j) primo_valido = successivo[j];
		// cambio i precedenti e successivi
		int tmp1 = successivo[precedente[i]];
		int tmp2 = precedente[successivo[j]];
		if(precedente[i] != -1) successivo[precedente[i]] = successivo[j];
		if(successivo[j] != -1) precedente[successivo[j]] = precedente[i];
		ricorsiva(primo_valido, precedente, successivo, tmp_res+3, V);

		// rimetto come prima
		successivo[precedente[i]] = tmp1;
		precedente[successivo[j]] = tmp2;

		// vado avanti senza togliere
		i = successivo[i];
		if(i==-1 || successivo[i] == -1) return -1;
		j = successivo[successivo[i]];
	}
}

int conta(int N, vector<int> V) {
	int precedente[N], successivo[N];
	precedente[0] = -1; successivo[N-1] = -1;
	for(int h=1; h<N; h++) precedente[h] = h-1;
	for(int h=0; h<N-1; h++) successivo[h] = h+1;
	ricorsiva(0, precedente, successivo, 0, V);
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