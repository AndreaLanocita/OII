#include <bits/stdc++.h>
#include <climits>

using namespace std;

static long long MAX = LLONG_MAX;

struct Node{
	long long mi;
	long long val;
    long long lazy_set;
    long long lazy_add;

	Node() : mi(MAX), val(0), lazy_add(0), lazy_set(LLONG_MIN) {};

	void join(Node &l, Node &r) {
        mi = min(l.mi, r.mi);
		val = l.val + r.val;
	}
};

int n, real_size;	// real_size è anche l'indice del primo nodo dell'ultimo livello
vector<Node> nodes;

void is_lazy(int u, int l, int r) {
	if(nodes[u].lazy_add == 0 && nodes[u].lazy_set == LLONG_MIN) return;

	if(nodes[u].lazy_set != 0) {
		// aumento direttamente il nodo e propago ai figli nel lazy
		nodes[u].mi = nodes[u].lazy_set;	
		// se cambio l'interno range di numeri in n --> la somma dei numeri sarà il numero di nodi incluso nel range * n
		nodes[u].val = nodes[u].lazy_set*(r-l);

		if(2*u+1 < nodes.size()) {
			// non voglio che si stackino lazy updates
			nodes[2*u].lazy_add = 0;
			nodes[2*u+1].lazy_add = 0;
			
			nodes[2*u].lazy_set = nodes[u].lazy_set;
			nodes[2*u+1].lazy_set = nodes[u].lazy_set;
		}

		nodes[u].lazy_set = LLONG_MIN;

		// while(u > 1) {
		// 	u /= 2;
		// 	nodes[u].join(nodes[2*u], nodes[2*u+1]);
		// }
	}
	
	if(nodes[u].lazy_add != 0) {
		// aumento direttamente il nodo e propago ai figli nel lazy
		nodes[u].mi += nodes[u].lazy_add;
		// se aggiungo n a tutte le foglie in un range, il singolo nodo aumenta di n*range
		nodes[u].val += nodes[u].lazy_add*(r-l);

		// non sono in una foglia, ho dei figli
		if(2*u+1 < nodes.size()) {
			// per fare add prima devo per forza aver fatto eventuali set, se no si sballa tutto
			is_lazy(2*u, l, (l+r)/2);
			is_lazy(2*u+1, (l+r)/2, r);

			// non si devono stackare lazy_updates
			nodes[2*u].lazy_add += nodes[u].lazy_add;
			nodes[2*u+1].lazy_add += nodes[u].lazy_add;
		}

		nodes[u].lazy_add = 0;

		// NON SERVE in lazy prop
		// while(u > 1) {
		// 	u /= 2;
		// 	nodes[u].join(nodes[2*u], nodes[2*u+1]);
		// }
	}
	

	return;
}

void build(int u, int l, int r, vector<long long> &a) {
	// se il range è = 1, sono in una foglia
	if(r-l <= 1) {
		if(l<a.size()) {	// il numero esiste e non è solo un -INF
			nodes[u].mi = a[l];	// l è incluso, r no --> il nodo è l
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

void init(vector<long long> a) {
	// n è la lunghezza della sequenza di numeri, realsize la potenza di due subito dopo
	n = a.size();

	real_size = 1;
	while(real_size < n) {
		real_size *= 2;
	}

	nodes.assign(2*real_size, Node());

	build(1, 0, real_size, a);
}

long long get_sum(int u, int l, int r, int x, int y) {
	// tengo conto del nodo, quindi mi serve che sia up-to-date
	is_lazy(u, l, r);

	// controllo se è completamente escluso
	if(l >= y || r <= x) return 0;

	// completamente incluso
	if(l>=x && r<=y) return nodes[u].val;

	// parzialmente incluso, somma dei due figli
	return (get_sum(2*u, l, (r+l)/2, x, y) + get_sum(2*u+1, (l+r)/2, r, x, y));
}

long long get_sum(int l, int r) {
	return get_sum(1, 0, real_size, l, r);
}

void add(int u, int l, int r, int x, int y, long long n) {
	// tengo conto del nodo, quindi mi serve che sia up-to-date
	is_lazy(u, l, r);

	// no overlap, nothing to do
	if(l >= y || r <= x) return;

	// full overlap, update node & lazy children
	// sia la somma che il minimo aumenteranno di x
	if(l >= x && r <= y) {
		// aumento direttamente il nodo e propago ai figli nel lazy
		nodes[u].mi += n;
		// se aggiungo n a tutte le foglie in un range, il singolo nodo aumenta di n*range
		nodes[u].val += n*(r-l);

		if(2*u+1 < nodes.size()) {
			// per fare add prima devo per forza aver fatto eventuali set, se no si sballa tutto
			is_lazy(2*u, l, (l+r)/2);
			is_lazy(2*u+1, (l+r)/2, r);
			
			// non si devono stackare lazy_updates
			nodes[2*u].lazy_add += n;
			nodes[2*u+1].lazy_add += n;
		}

		// NON SERVE PERCHE DOVUNQUE C'E UN PARZIALE OVERLAP FACCIO GIA IL JOIN
		// while(u > 1) {
		// 	u /= 2;
		// 	nodes[u].join(nodes[2*u], nodes[2*u+1]);
		// }

		return;
	}

	// partial overlap
	add(2*u, l, (l+r)/2, x, y, n);
	add(2*u+1, (l+r)/2, r, x, y, n);
	nodes[u].join(nodes[2*u], nodes[2*u+1]);

	return;
}

void add(int l, int r, long long x) {
	add(1, 0, real_size, l, r, x);
}

void set_range(int u, int l, int r, int x, int y, int n) {
	// tengo conto del nodo, quindi mi serve che sia up-to-date
	is_lazy(u, l, r);

	// no overlap, nothing to do
	if(l >= y || r <= x) return;

	// full overlap, update node & lazy children
	// sia la somma che il minimo aumenteranno di x
	if(l >= x && r <= y) {
		// aumento direttamente il nodo e propago ai figli nel lazy
		nodes[u].mi = n;	
		// se cambio l'interno range di numeri in n --> la somma dei numeri sarà il numero di nodi incluso nel range * n
		nodes[u].val = n*(r-l);

		// non sono una foglia --> ho dei figli
		if(2*u+1 < nodes.size()) {
			// non voglio che si stackino lazy updates
			nodes[2*u].lazy_add = 0;
			nodes[2*u+1].lazy_add = 0;
			
			nodes[2*u].lazy_set = n;
			nodes[2*u+1].lazy_set = n;
		}
		
		// NON SERVE PERCHE DOVUNQUE C'E UN PARZIALE OVERLAP FACCIO GIA IL JOIN
		// while(u > 1) {
		// 	u /= 2;
		// 	nodes[u].join(nodes[2*u], nodes[2*u+1]);
		// }

		return;
	}

	// partial overlap
	set_range(2*u, l, (l+r)/2, x, y, n);
	set_range(2*u+1, (l+r)/2, r, x, y, n);
	nodes[u].join(nodes[2*u], nodes[2*u+1]);

	return;
}

void set_range(int l, int r, long long x) {
	set_range(1, 0, real_size, l, r, x);
}

long long get_min(int u, int l, int r, int x, int y) {	// y escluso
	// tengo conto del nodo, quindi mi serve che sia up-to-date
	is_lazy(u, l, r);

	// controllo se i limiti sono completamente esclusi
	if(l >= y || r <= x) return MAX;

	// sono completamente inclusi, ritorno il valore del nodo corrente
	if(l >= x && r <= y) return nodes[u].mi;

	// se sono inclusi a metà prendo il minimo della chiamata ricorsiva ai due figli
	return min(
		get_min(2*u, l, (l+r)/2, x, y),
		get_min(2*u+1, (l+r)/2, r, x, y)
	);
}

long long get_min(int l, int r) {
	return get_min(1, 0, real_size, l, r);
}

int lower_bound(int u, int l, int r, int x, int y, long long bound) {
	// tengo conto del nodo, quindi mi serve che sia up-to-date
	is_lazy(u, l, r);
	
    // controllo se i limiti sono completamente esclusi
    if(l >= y || r <= x) return -1;

	// sono almeno parzialmente inclusi, controllo se il valore del nodo corrente è minore di bound
    if(nodes[u].mi <= bound) {
        // sono una foglia
        if(r-l<=1) return l;

        // non sono una foglia, prima controllo sx poi dx
        int sx = lower_bound(2*u, l, (l+r)/2, x, y, bound);
        if(sx != -1) return sx;
        return lower_bound(2*u+1, (l+r)/2, r, x, y, bound);
    }
    return -1;
}

int lower_bound(int l, int r, long long x) {
	// returns the index to the left most element <= x
	return lower_bound(1, 0, real_size, l, r, x);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n, q;
	cin >> n >> q;
	
	vector<long long> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	init(a);
	
	for (int i = 0; i < q; i++) {
		int op, l, r;
		long long x;
		cin >> op;
		cin >> l >> r;
		if (op == 2 or op == 3 or op == 5)
			cin >> x;
		if (op == 1) cout << get_sum(l, r) << "\n";
		if (op == 2) add(l, r, x);
		if (op == 3) set_range(l, r, x);
		if (op == 4) cout << get_min(l, r) << "\n";
		if (op == 5) cout << lower_bound(l, r, x) << "\n";
	}
	
	return 0;
}