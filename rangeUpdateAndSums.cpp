#include <bits/stdc++.h> 
#include <climits>

using namespace std;

#define vi vector<ll>
#define pi pair<int, int>
#define vp vector<pi>
#define ll long long int
#define omap map<int, int>
#define umap unordered_map<int, int>

#define INF LLONG_MAX

int real_size = 1;
vi st_sum, st_min;
vi lz_add, lz_set;


void update_add(int u, int l, int r, ll val) {
    st_sum[u] += val * (r-l);
    st_min[u] += val;
}

void update_set(int u, int l, int r, ll val) {
    st_sum[u] = val * (r-l);
    st_min[u] = val;
}

void build(vi& dataa) {
    while(real_size < dataa.size()) 
        real_size *= 2;

    st_sum.assign(2*real_size, 0); st_min.assign(2*real_size, INF);
    lz_add.assign(real_size, 0); lz_set.assign(real_size, INF);

    for(int i=0; i<real_size; i++) {
        st_sum[i+real_size] = dataa[i];
        st_min[i+real_size] = dataa[i];
    }
        
    
    for(int i=real_size-1; i>=0; i--) {
        st_sum[i] = st_sum[2*i] + st_sum[2*i+1];
        st_min[i] = min(st_min[2*i], st_min[2*i+1]);
    }
        
}

void push(int u, int l, int r) {
    // changes the children of u and propogates the update 
    // in their lazy tree
    // se ho sia set che add, allora l'ultimo update deve essere stato
    // un add --> faccio prima set poi add
    if(u>=real_size) return ;

    if(lz_set[u] != INF && lz_add[u] != 0) {
        update_set(2*u, l, (l+r)/2, lz_set[u]);
        update_set(2*u+1, (l+r)/2, r, lz_set[u]);
        update_add(2*u, l, (l+r)/2, lz_add[u]);
        update_add(2*u+1, (l+r)/2, r, lz_add[u]);

        if(2*u < real_size) {
            // non so l'ordine originale. Se ho aggiunto add prima devo aggiungerlo anche sotto
            lz_add[2*u] = lz_add[u];
            lz_add[2*u+1] = lz_add[u];
            lz_set[2*u] = lz_set[u];
            lz_set[2*u+1] = lz_set[u];
        }
        lz_add[u] = 0;
        lz_set[u] = INF;
        return ;
    }
    
    if(lz_set[u] != INF) {
        update_set(2*u, l, (l+r)/2, lz_set[u]);
        update_set(2*u+1, (l+r)/2, r, lz_set[u]);

        if(2*u < real_size) {
            // non so l'ordine originale. Se ho aggiunto add prima devo aggiungerlo anche sotto
            lz_set[2*u] = lz_set[u];
            lz_set[2*u+1] = lz_set[u];
        }
    }

    if(lz_add[u] != 0) {
        update_add(2*u, l, (l+r)/2, lz_add[u]);
        update_add(2*u+1, (l+r)/2, r, lz_add[u]);

        if(2*u < real_size) {
            lz_add[2*u] = lz_add[u] + lz_add[2*u];
            lz_add[2*u+1] = lz_add[u] + lz_add[2*u+1];
        }
    }

    lz_add[u] = 0;
    lz_set[u] = INF;
}

void addd(int u, int l, int r, int x, int y, ll val) {
    if(l>=y || r<=x) return ;
    if(l>=x && r<=y) {
        update_add(u, l, r, val);

        if(u < real_size)
            lz_add[u] = val + lz_add[u];
        
        return ;
    }
    push(u, l, r);
    addd(2*u, l, (l+r)/2, x, y, val);
    addd(2*u+1, (l+r)/2, r, x, y, val);
    st_sum[u] = st_sum[2*u] + st_sum[2*u+1];
    st_min[u] = min(st_min[2*u], st_min[2*u+1]);
}

void sett(int u, int l, int r, int x, int y, ll val) {
    if(l>=y || r<=x) return ;
    if(l>=x && r<=y) {
        update_set(u, l, r, val);

        if(u < real_size) {
            lz_add[u] = 0;
            lz_set[u] = val;
        }
        return ;  
    }
    push(u, l, r);
    sett(2*u, l, (l+r)/2, x, y, val);
    sett(2*u+1, (l+r)/2, r, x, y, val);
    st_sum[u] = st_sum[2*u] + st_sum[2*u+1];
    st_min[u] = min(st_min[2*u], st_min[2*u+1]);
}

ll get_summ(int u, int l, int r, int x, int y) {
    if(l>=y || r<=x) return 0;
    if(l>=x && r<=y) return st_sum[u];
    push(u, l, r);
    return (get_summ(2*u, l, (l+r)/2, x, y) + get_summ(2*u+1, (l+r)/2, r, x, y));
}

ll get_minn(int u, int l, int r, int x, int y) {
    if(l>=y || r<=x) return INF;
    if(l>=x && r<=y) return st_min[u];
    push(u, l, r);
    return min(get_minn(2*u, l, (l+r)/2, x, y), get_minn(2*u+1, (l+r)/2, r, x, y));
}

ll sx, dx;
ll get_lowerbound(int u, int l, int r, int x, int y, ll bound) {
    if(l>=y || r<=x || st_min[u] > bound) return -1;
    
    // sono in una foglia = caso base
    if(u >= real_size) return u - real_size;
    
    push(u, l, r);
    // provo prima a sx poi a dx
    sx = get_lowerbound(2*u, l, (l+r)/2, x, y, bound);
    if(sx == -1) return get_lowerbound(2*u+1, (l+r)/2, r, x, y, bound);
    return sx;
}

void init(vector<long long> a) {
	build(a);
}

long long get_sum(int l, int r) {
	return get_summ(1, 0, real_size, l, r);
}

void add(int l, int r, long long x) {
	addd(1, 0, real_size, l, r, x);
}

void set_range(int l, int r, long long x) {
	sett(1, 0, real_size, l, r, x);
}

long long get_min(int l, int r) {
	return get_minn(1, 0, real_size, l, r);
}

int lower_bound(int l, int r, long long x) {
	return get_lowerbound(1, 0, real_size, l, r, x);
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