#include <bits/stdc++.h>
#define MAXN 1000001

using namespace std;

struct classifica{
	int id = 0,left = 0,right = 0;
};

classifica C[MAXN];
int tree[MAXN * 4];

class st{
	public :
		st(int N,int *tree){
			this->S = N;
			this->tree = tree;
			build(0,0,S - 1);
		}
		void update(int index){
			this->pos = index;
			updateUtil(0,0,S - 1);
		}
		int query(int index){
			this->pos = index;
			return queryUtil(0,0,S - 1);
		}
	;
	private :
		int S,*tree = NULL;
		// utilities
		inline int RC(int &i){
			return i * 2 + 2;
		}
		inline int LC(int &i){
			return i * 2 + 1;
		}
		inline int get_mid(int s,int e){
			return (s + e) / 2;
		}
		// builder
		void build(int node,int s,int e){
			if(s == e){
				tree[node] = 1;
			}else{
				int rc = RC(node);
				int lc = LC(node);
				int mid = get_mid(s,e);
				build(lc,s,mid);
				build(rc,mid + 1,e);
				tree[node] = tree[rc] + tree[lc];
			}
		}
		// query and update
		int pos;
		void updateUtil(int node,int s,int e){
			if(s > pos || e < pos)return;
			if(s == pos && e == pos){
				tree[node] = 0;
				return;
			}
			int lc = LC(node);
			int rc = RC(node);
			int mid = get_mid(s,e);
			updateUtil(lc,s,mid);
			updateUtil(rc,mid + 1,e);
			tree[node] = tree[lc] + tree[rc];
		}
		
		int queryUtil(int node,int s,int e){
			if(s == e){
				return s;
			}
			int lc = LC(node);
			int rc = RC(node);
			int mid = get_mid(s,e);
			if(tree[lc] < pos){
				pos -= tree[lc];
				return queryUtil(rc,mid + 1,e);
			}else{
				return queryUtil(lc,s,mid);
			}
		}	
	;
};

int posizioni[MAXN];

st *T = NULL;
void inizia(int N, int ids[]){
	for(int i = 0; i < N; i++){
		C[i].id = ids[i];
		C[i].left = i - 1;
		C[i].right = i + 1;
		posizioni[ids[i]] = i;
	}
	T = new st(N,tree);
}

void supera(int id){
	int p1 = posizioni[id];
	int p2 = C[p1].left;
	int id2 = C[p2].id;
	swap(C[p1].id,C[p2].id);
	swap(posizioni[id],posizioni[id2]);	
};

/*
	rip  b 
	<-A-><-b-><-c-><-d->
	<-A-><-c-><-d->
*/

void squalifica(int id){
	int p1 = posizioni[id];
	int left = C[p1].left;
	int right = C[p1].right;
	C[left].right = right;
	C[right].left = left;
	T->update(p1);
}

int partecipante(int pos){
	pos = T->query(pos);
	return C[pos].id;
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