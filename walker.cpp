#include <bits/stdc++.h>

using namespace std;

long long MOD = 666013;
long long int N, K, T;

long long p(long long x, long long n) {
    long long result = 1;
    while(n) {
        if(n%2==1) {
            result = (result*x)%MOD;
            n=n-1;
        }
        x=(x*x)%MOD;
        n=n/2;
   }
   return result;
}

long long count(long long n, long long k) {
    long long quad_n = p(n-1, 2);
    long long sommatoria = 0;
    for(long long int i=0; i<(k-2)/2; i++) {
        sommatoria += p(quad_n, i);
        sommatoria%=MOD;
    }
    if(k%2==1) {
        sommatoria = (p(n-1, k-2) + ( (n-1) * sommatoria))%MOD;
        return ((n-2)*sommatoria);
    }
    else {
        sommatoria = (p(n-1, k-2) + sommatoria)%MOD;
        return ((n-2)*sommatoria+1);
    }
}

int main() {
    
    cin >> N >> K;

    cout << count(N, K);

    return 0;
}