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
	
}

int conta(int N, vector<int> D);

int main() {
	// se vuoi leggere da file decommenta queste due linee
	// assert(freopen("input.txt", "r", stdin));
	// assert(freopen("output.txt", "w", stdout));

	int n;
	cin >> n;

	vector<int> d(n);
	for (auto &x : d)
		cin >> x;

	int ans = conta(n, d);
	cout << ans << '\n';
}