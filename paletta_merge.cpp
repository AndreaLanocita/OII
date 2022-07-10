#include <bits/stdc++.h>
#include <climits>

using namespace std;

long long int counter = 0;

void merge(int l, int r, int *dataa) {
    int res[l+r+1];
    int mid = (l+r)/2;
    int i=l, j=mid, k=l;

    while(i<mid && j<r) {
        if(dataa[i] <= dataa[j]) {
            res[k] = dataa[i];
            i++;
        }
        else {
            res[k] = dataa[j];
            j++;

            counter += (mid - i);
        }
        k++;
    }

    while(i < mid) {
        res[k] = dataa[i];
        i++; k++;
    }
    while(j<r) {
        res[k] = dataa[j];
        j++; k++;
    }

    for(i=l; i<k; i++) {
        dataa[i] = res[i];
    }
}

void MergeSort(long long int l, long long int r, int *dataa) {
    if(r-l==1) return;

    if(l < r) {
        int mid = (l+r)/2;

        MergeSort(l, mid, dataa);
        MergeSort(mid, r, dataa);

        merge(l, r, dataa);
    }
}

long long paletta_sort(int N, int V[]) {
    int pn = 0, dn = 0;
    int pari[N/2+2];
    int dispari[N/2+2];

    for (int i = 0; i < N; ++i){
        // ci sono tutti i numeri fino ad N-1, quindi per riordinare la sequenza di numeri da 0 a n-1 tutti i numeri pari devono essere in posizioni pari
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

    MergeSort(0, pn, pari);
    MergeSort(0, dn, dispari);

    return counter;
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
		fscanf(fr, "%i", &V[i0]);
	}

	// Calling functions
	numero_ribaltamenti = paletta_sort(N, V);

	// Writing output
	fprintf(fw, "%lli\n", numero_ribaltamenti);
	
	fclose(fr);
	fclose(fw);
	return 0;
}
