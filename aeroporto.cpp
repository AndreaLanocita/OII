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

bool check(int k, int R, int A[], int B[], int T[]) {
    T[0] = A[0];
    for(int i=1; i<R; i++) {
        T[i] = max(T[i-1]+k, A[i]);
        if(T[i] > B[i]) return 0;
    }
    return 1;
}

void riempi(int k, int R, int A[], int B[], int T[]) {
    T[0] = A[0];
    for(int i=1; i<R; i++) {
        T[i] = max(T[i-1]+k, A[i]);
    }
}


void pianifica(int R, int A[], int B[], int T[]) {
    int l = 0, r = B[R-1] / R + 1, mid;
    while(l<r) {
        mid = (l+r)/2;
        if(check(mid, R, A, B, T) == 1) l = mid+1;
        else r = mid;
    }

    riempi(r-1, R, A, B, T);
}

static FILE *fr, *fw;

// Declaring variables
static int R;
static int* A;
static int* B;
static int* T;

// Declaring functions
void pianifica(int R, int* A, int* B, int* T);

int main() {
    fr = fopen("input.txt", "r");
    fw = stdout;

	// Iterators used in for loops
	int i0;

	// Reading input
	fscanf(fr, "%d ", &R);
	A = (int*)malloc(R * sizeof(int));
	B = (int*)malloc(R * sizeof(int));
	for (i0 = 0; i0 < R; i0++) {
		fscanf(fr, "%d %d ", &A[i0], &B[i0]);
	}

	// Calling functions
	T = (int*)malloc(R * sizeof(int));
	pianifica(R, A, B, T);

	// Writing output
	for (i0 = 0; i0 < R; i0++) {
		fprintf(fw, "%d ", T[i0]);
	}
	fprintf(fw, "\n");
	
	fclose(fr);
	fclose(fw);
	return 0;
}