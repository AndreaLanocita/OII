#include <bits/stdc++.h>

using namespace std;

#define MAXN 100000

vector<int> usato(1000, 0);
vector<int> kusato(1000, 0); // ho già trovato questa config?

int res = 0;
int ricorsiva(int n, int k, int N, vector<int> &B, vector<int>& A, vector<int>& usato, vector<int>& kusato) {	
	if(n==N-1) {
		for(int i=0; i<N; i++) {
			if(usato[i] != 0) continue;
			if(A[n] < B[i] && kusato[k+1] == 0) {
				res++;
				kusato[k+1] = 1;
			} 
			else if(A[n] >= B[i] && kusato[k] == 0) {
				res++;
				kusato[k] = 1;
			}
		}
		return 0;
	}
	
	for(int i=0; i<N; i++) {
		if(usato[i] != 0) continue;;
		usato[i] = 1;
		if(A[n] < B[i]) ricorsiva(n+1, k+1, N, B, A, usato, kusato);
		else ricorsiva(n+1, k, N, B, A, usato, kusato);

		usato[i] = 0;

	}
	return 0;
}

int direziona(int N, vector<int> A, vector<int> B) {
	// for(int i=0; i<N; i++) {
	// 	numero[i] = N-distance(B.begin(), lower_bound(B.begin(), B.end(), A[i]));		
	// }
	ricorsiva(0, 0, N, B, A, usato, kusato);
	return res;
}