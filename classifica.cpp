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

#define MAXN 1000005

int idd[MAXN];	// zero based
int classifica[MAXN];
int squalificato[MAXN];

struct Node {
	int summ, minn;
	Node() : summ(0), minn(0) {};
};

vector<Node> st;
int real_size = 1;

void inizia(int N, int ids[]) {
	int i;
	for(i=0; i<N; i++) 
		classifica[i] = ids[i];
		
	for(i=0; i<N; i++) 
		idd[classifica[i]] = i;
	
	while(real_size < N) real_size *= 2;
	st.resize(2*real_size);
}

int dx;
int inverseLowerbound(int u, int l, int r, int x, int y) {
	// completamente escluso
	if(l>=y || r<=x || st[u].minn == 1) return -1;

	// sono una foglia
	if(r-l<=1) return l;

	// non sono una foglia, prima controllo dx poi sx
	dx = inverseLowerbound(2*u+1, (l+r)/2, r, x, y);
	if(dx != -1) return dx;
	return inverseLowerbound(2*u, l, (r+l)/2, x, y);
}

int psum(int u, int l, int r, int x, int y) {
	// completamente escluso
	if(l>=y || r<=x) return 0;

	// completamente incluso e valido
	if(l>=x && r<= y) return st[u].summ;

	// ricorro
	return (psum(2*u, l, (l+r)/2, x, y) + psum(2*u+1, (l+r)/2, r, x, y));
}

int indexx;
void update(int l) {
	indexx = real_size + l;
	st[indexx].summ += 1;
	indexx /= 2;
	while(indexx > 0) {
		st[indexx].summ = st[indexx*2].summ + st[indexx*2+1].summ;
		indexx /= 2;
	}
	return ;
}

void update_min(int l) {
	indexx = real_size + l;
	st[indexx].minn = 1;
	indexx /= 2;
	while(indexx > 0) {
		st[indexx].minn = min(st[2*indexx].minn, st[2*indexx+1].minn);
		indexx /= 2;
	}
	return ;
}

int precedente, tmp, tmp1;	// precedente non squalificato
void supera(int id) {
	// trovo l'indexx del precedente in classifica
	precedente = inverseLowerbound(1, 0, real_size, 0, idd[id]);
	tmp = classifica[precedente];
	classifica[precedente] = classifica[idd[id]];
	classifica[idd[id]] = tmp;
	tmp1 = idd[tmp];
	idd[tmp] = idd[id];
	idd[id] = tmp1;
}

int real_pos;
void squalifica(int id) {
	update_min(id[idd]);

	real_pos = id[idd]-psum(1, 0, real_size, 0, id[idd]);
	if(squalificato[id[idd]+1] == 1) 
	update(id[idd]-psum(1, 0, real_size, 0, id[idd]));
}

int summ = 0;
int partecipante(int pos) {
	summ = pos-1+psum(1, 0, real_size, 0, pos);
	while(st[summ+real_size].minn==1) summ += st[summ+real_size].summ;
	return classifica[summ];
}

static FILE *fr, *fw;

// Declaring variables
static int N;
static int Q;
static int* ids;
static char* types;
static int* params;
static int* answers;

// Declaring functions
void inizia(int N, int ids[]);
void supera(int id);
void squalifica(int id);
int partecipante(int pos);

// Functions ad-hoc for this grader
void make_calls(int& Q, char types[], int params[], int answers[]) {
    int cnt = 0;
	for (int i = 0; i < Q; i++) {
		if (types[i] == 's') {
			supera(params[i]);
		}
		else if (types[i] == 'x') {
			squalifica(params[i]);
		}
		else if (types[i] == 'p') {
			answers[cnt++] = partecipante(params[i]);
		}
	}
    Q = cnt;
}


int main() {
	fr = stdin;
	fw = stdout;

	// Reading input
	fscanf(fr, " %d %d", &N, &Q);
	ids = (int*)malloc((N) * sizeof(int));
	for (int i0 = 0; i0 < N; i0++) {
		fscanf(fr, " %d", &ids[i0]);
	}
	types = (char*)malloc((Q) * sizeof(char));
	params = (int*)malloc((Q) * sizeof(int));
	for (int i0 = 0; i0 < Q; i0++) {
		fscanf(fr, " %c %d", &types[i0], &params[i0]);
	}

	// Calling functions
	inizia(N, ids);
	answers = (int*)malloc((Q) * sizeof(int));
	make_calls(Q, types, params, answers);

	// Writing output
	for (int i0 = 0; i0 < Q; i0++) {
		fprintf(fw, "%d ", answers[i0]);
	}
	fprintf(fw, "\n");

	fclose(fr);
	fclose(fw);
	return 0;
}