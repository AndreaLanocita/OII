#include <vector>
#include <fstream>
#include <iostream>

using namespace std;

#define MAXH 1000000
#define MAXN

int dp[MAXH];
int dfs(int n, int visitato[], int hmax, vector<int> &S, vector<int> &A, vector<int> &B) {
	if(n+B[n]>=S.size()) return 1;
	visitato[n] = 1;
	int flag=0;
	for(int i=n+A[n]; i<=n+B[n]; i++) {
		if(visitato[i] || S[i]>hmax || dp[i]) continue;
		if(dfs(i, visitato, hmax, S, A, B)) flag=1;
	}
	if(!flag) dp[n]=1;
	return flag;
}

int controlla(int hmax, int visitato[], int N, vector<int> &S, vector<int> &A, vector<int> &B) {
	for(int i=0; i<N; i++) visitato[i] = 0;
	if(S[0]>hmax) return 0;
	return dfs(0, visitato, hmax, S, A, B);
}

int salta(int N, vector<int> S, vector<int> A, vector<int> B){
	int l=S[0]; int r=S[0];
	for(int i=0; i<N; i++) {
		l=min(l, S[i]);
		r=max(MAXH, S[i])+1;
		dp[i]=0;
	}
	
	int visitato[N];
	while(l<r) {
		int mid=(l+r)/2;
		if(controlla(mid, visitato, N, S, A, B)) r=mid;
		else l=mid+1;
	}
	return r;
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  // Uncomment the following lines if you want to read or write from files
  ifstream cin("input.txt");
  ofstream cout("output.txt");

  int N;
  cin >> N;

  vector<int> S(N), A(N), B(N);
  for (int i = 0; i < N; i++) {
    cin >> S[i] >> A[i] >> B[i];
  }

  cout << salta(N, S, A, B) << endl;

  return 0;
}
