#include <bits/stdc++.h>
#include <climits>

using namespace std;

struct Node {
    int depth;
    int mi;
    long long int pos;

    Node() : mi(INT_MAX), pos(0), depth(0) {};

    void join(const Node &l, const Node &r) {
        // se quello a sx è minore non devo riordinare
        if(l.mi <= r.mi) {  
            mi = l.mi;
            pos = l.pos + r.pos;
        } else {
            // se quello a dx maggiore devo spostarlo più volte in base alla altezza dell'albero, che parte da 0 per i figli
            mi = r.mi;
            pos = l.pos + r.pos + (l.depth + 1);
        }
        depth = l.depth + 1;
    }

};

int n, real_size;
int* dataa;
vector<Node> nodes;

void build_pari(int u, int l, int r) {
    if(r-l == 1) {
        // sono in una foglia
        if(l<n) {
            // sono una foglia che esiste
            nodes[u].mi = dataa[l];
        }
    }
    else {
        build_pari(2*u, l, (r+l)/2);
        build_pari(2*u+2, (l+r)/2+1, r);
        nodes[u].join(nodes[2*u], nodes[2*u+2]);
    }
}

void build_dispari(int u, int l, int r) {
    if(r-l == 1) {
        // sono in una foglia
        if(l<n) {
            // sono una foglia che esiste
            nodes[u].mi = dataa[l];
        }
    }
    else {
        build_dispari(2*u-1, l, (l+r)/2);
        build_dispari(2*u+1, (l+r)/2+1, r);
        nodes[u].join(nodes[2*u-1], nodes[2*u+1]);
    }
}

void init() {
    real_size = 1;
    while(real_size < n) {
        real_size *= 2;
    }

    nodes.assign(2 * real_size, Node());

    build_pari(2, 0, real_size-1); // albero pari
    build_dispari(3, 1, real_size); // albero dispari
}

long long paletta_sort(int N, int V[]) {
    dataa = V;
    n = N;
    for (int i = 0; i < n; ++i){
		if(i%2 != V[i]%2)
			return -1;	
    }
    init();

    return nodes[2].pos + nodes[3].pos;
}

static FILE *fr, *fw;

// Declaring variables
static int N;
static int* V;
static long long int numero_ribaltamenti;

// Declaring functions
long long int paletta_sort(int N, int* V);

int main() {
	#ifdef EVAL
		fr = fopen("input.txt", "r");
		fw = fopen("output.txt", "w");
	#else
		fr = stdin;
		fw = stdout;
	#endif

	// Reading input
	fscanf(fr, "%d ", &N);
	V = (int*)malloc(N * sizeof(int));
	for (int i0 = 0; i0 < N; i0++) {
		fscanf(fr, "%d", &V[i0]);
	}

	// Calling functions
	numero_ribaltamenti = paletta_sort(N, V);

	// Writing output
	fprintf(fw, "%lld\n", numero_ribaltamenti);
	
	fclose(fr);
	fclose(fw);
	return 0;
}
