#include <bits/stdc++.h>

using namespace std;

#define ll long long

struct Node {
	long long val;	// somma
	long long lazy;
	Node(): val((long long)0), lazy((long long)0) {};
	
	void join(Node &l, Node &r) {
		val = l.val + r.val;
	}
};

long long real_size, n;
vector<Node> nodes;
vector<pair<pair<int, int>, int>> history;	// {l, r}, val

void build(ll u, ll l, ll r, vector<int> &a) {
	// se il range è = 1, sono in una foglia
	if(r-l <= 1) {
		if(l<a.size()) {	// il numero esiste e non è solo un -INF
			nodes[u].val = a[l];
		}
	}
	// se non sono in una foglia calcolo ricorsivamente i due figli
	else {
		build(u*2, l, (l+r)/2, a);
		build(u*2+1, (l+r)/2, r, a);
		nodes[u].join(nodes[2*u], nodes[2*u+1]);
	}
}

void inizia(int N, vector<int> A){
	real_size = 1;
	while(real_size < N) {
		real_size *= 2;
	}

	nodes.assign(2*real_size, Node());

	build(1, 0, real_size, A);
}

void check(ll u, ll l, ll r) {
	if(nodes[u].lazy == 0) return ;
	nodes[u].val += (nodes[u].lazy * (r-l));

	// non sono in una foglia
	if(2*u+1 < nodes.size()) {
		nodes[2*u].lazy += nodes[u].lazy;
		nodes[2*u+1].lazy += nodes[u].lazy;
	}
	nodes[u].lazy = 0;
	return ;
}

void range_update(ll u, ll l, ll r, ll x, ll y, ll val) {
	check(u, l, r);
	if(l>= y || r<= x) return ;
	if(l >= x && r <= y) {
		nodes[u].val += ((r-l) * val);

		if(2*u+1 < nodes.size()) {
			nodes[2*u].lazy += val;
			nodes[2*u+1].lazy += val;
		}

		return ;
	}

	range_update(2*u, l, (r+l)/2, x, y, val);
	range_update(2*u+1, (r+l)/2, r, x, y, val);
	nodes[u].join(nodes[2*u], nodes[2*u+1]);
	return ;
}

void incrementa(int l, int r, int x){
	range_update(1, 0, real_size, l, r, x);
	history.push_back({{l, r}, x});
}

void reset(ll u, ll l, ll r, ll x, ll y, ll x1, ll y1, long long val) {
	// controllo sia completamente escluso almeno da uno dei due
	if((l>= y || r<= x) || (l>= y1 || r<= x1)) return ;
	check(u, l, r);

	// controllo sia completamente incluso in entrambi
	if((l >= x && r <= y) && (l >= x1 && r <= y1)) {
		nodes[u].val += ((r-l) * val);

		if(r-l>1) {
			nodes[2*u].lazy += val;
			nodes[2*u+1].lazy += val;
		}

		return ;
	}

	// è parzialmente incluso in entrambi
	reset(2*u, l, (r+l)/2, x, y, x1, y1, val);
	reset(2*u+1, (r+l)/2, r, x, y, x1, y1, val);
	nodes[u].val = nodes[2*u].val + nodes[2*u+1].val;
}

void resetta(int l, int r, int v){
	// history[val+1] --> NB non sempre l'intervallo è compreso
	for(int i=v; i<history.size(); i++) {
		reset(1, 0, real_size, l, r, history[i].first.first, history[i].first.second, -history[i].second);
	}
	return ;
}

long long range_query(ll u, ll l, ll r, ll x, ll y) {
	check(u, l, r);
	if(l>= y || r<= x) return 0;
	if(l >= x && r <= y) return nodes[u].val;

	return (range_query(2*u+1, (r+l)/2, r, x, y) + range_query(2*u, l, (r+l)/2, x, y));
}

long long somma(int l, int r){
	return range_query(1, 0, real_size, l, r);
}