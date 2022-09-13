#include <bits/stdc++.h>

using namespace std;

#define MAXN 100000

int direziona(int N, vector<int> A, vector<int> B) {
	/* 
	Trovo massimo e minimo formiche, tutte le configurazioni in mezzo sono valide
	puntatore i di A, j di B;
	1. per ogni i, j++ finché Ai < Bj --> aumento counter --> i++
	2. per ogni i, se Ai > Bj --> counter++, j++
	res = counter1-counter2+1
	*/
	int i=0, j=0, countermax = 0;
	for(; i<N && j<N ; i++) {
		while(A[i] >= B[j] && j<N) j++;
		if(A[i] < B[j]) {
			countermax++;
			j++;
		} 
	}

	i=0, j=0;
	int countermin = 0;
	for(; i<N && j<N; i++) {
		if(A[i] >= B[j]) {
			countermin++;
			j++;
		}
	}
	countermin = N-countermin;
	return countermax-countermin+1;
}

int direziona(int N, vector<int> A, vector<int> B);

int main() 
{
	int N;
	cin >> N;

	vector<int> A(N), B(N);
	for (int& x : A) cin >> x;
	for (int& x : B) cin >> x;

	cout << direziona(N, A, B) << "\n";

	return 0;
}
