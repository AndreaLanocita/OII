#include <bits/stdc++.h>

using namespace std;

long long int N, K, Q, P, i;
long long int V;

int main() {
    srand (time(NULL));
    
    N = rand() % 10000 + 1;
    K = rand() % N + 1;
    cout << N << " " << K << endl;

    P = rand() % 100+1;
    Q = rand() % 100+1;
    cout << P << " " << Q << endl;

    for(int i=0; i<N; i++) {
        V = rand() % 10000 + 1;
        cout << V << " ";
    }
}