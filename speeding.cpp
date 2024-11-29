// NOTE: it is recommended to use this even if you don't understand the following code.

#include <bits/stdc++.h>
long long MOD = 10e9+7;

using namespace std;

int main() {
    // uncomment the following lines if you want to read/write from files
    // ifstream cin("input.txt");
    // ofstream cout("output.txt");

    long long N;
    cin >> N;
    
    vector<long long> A(N), B(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> B[i];
    }

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    long long res = 1; 

    long long i=0, j=0;
    while(i<=j && j<=N) {
        while(j!=N && B[j]<=A[i]) j++;
        if(j-i>1) res = (((res%MOD) * ((j-i)%MOD))%MOD);
        i++;
    }

    for(int i=0; i<N; i++) {
        if(A[i]<B[i])  {
            cout << 0 << endl;
            return 0;
        }
    }
        
    cout << res%MOD << endl;
    return 0;
}
