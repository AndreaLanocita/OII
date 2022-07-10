#include <bits/stdc++.h>

using namespace std;

int sol[1000000];

int ans(int n, int b, vector<int> A) {
	// caso base
	if(b==0) return 0;

	if(b<0 || n==-1) return -2;

	// ho la sol
	if(sol[n] != -1) return sol[n];

	// sol
	int c, d;
	c = ans(n, b-A[n], A);	// prendo lo stesso panino
	d = ans(n-1, b, A); 	// non prendo panino

	if(c==-2 && d==-2) {
		sol[n] = -2;
		return sol[n];
	}

	if(c==-2) {
		sol[n] = d;
		return sol[n];
	}

	if(d==-2) {
		sol[n] = c+1;
		return sol[n];
	}

	sol[n] = min(d, c+1);

	return sol[n];
}

int sushi(int N, int B, vector<int> A) {
	for(int i=0; i<N; i++) {
		sol[i] = -1;
	}

	int temp = ans(N-1, B, A);
	if(temp == -2) temp = -1;

	return temp;
}

int main() {
	// se preferisci leggere e scrivere da file
	// ti basta decommentare le seguenti due righe:

	// ifstream cin("input.txt");
	// ofstream cout("output.txt");

	int N, B;
	cin >> N >> B;

	vector<int> A(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	cout << sushi(N, B, A) << endl;

	return 0;
}
