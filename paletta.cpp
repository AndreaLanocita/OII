#include <bits/stdc++.h>
#include <climits>

using namespace std;

#define vi vector<int>
#define ll long long int

vi fenwick;

void add(int index, int val) {
    while(index<fenwick.size()) {
        fenwick[index] += val;
        index += index & (-index);
    }
}

int summ=0;
ll sum(int index) {
    summ=0;
    // prefix sum, all of the elements smaller than index
    while(index > 0) {
        summ += fenwick[index];
        // go backwards lsb(index)
        index -= index & (-index);
    }
    return summ;
}

long long paletta_sort(int N, int V[]) {
    int pari[N/2+2];
    int dispari[N/2+2];
    int pn = 0, dn = 0;

    // check if it exists
    for (int i = 0; i < N; ++i){
		if(i%2 != V[i]%2)
			return -1;	

        // divido gli array in pari e dispari
        if(i%2) {
            pari[pn] = V[i];
            pn += 1;
        }
        else {
            dispari[dn] = V[i];
            dn += 1;
        }
    }
    
    // fenwick
    fenwick.assign(N+1, 0);
    ll res = 0;
    // faccio tutto al contrario per comodità
    for(int i=dn-1; i>=0; i--) {
        // look for the sum of all the elements smaller than 
        // V[i]
        res += sum(dispari[i]+1);

        // update the tree --> there's one more element with that value
        // +1, fuck the 0
        add(dispari[i]+1, 1);
    }

    // fenwick
    fenwick.assign(N+1, 0);
    // faccio tutto al contrario per comodità
    for(int i=pn-1; i>=0; i--) {
        // look for the sum of all the elements smaller than 
        // V[i]
        res += sum(pari[i]+1);
        
        // update the tree --> there's one more element with that value
        // +1, fuck the 0
        add(pari[i]+1, 1);
    }

    return res;

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
