#include <bits/stdc++.h>

using namespace std;

int N, M, W, L, tmp1, tmp2, tmp3;

int main() {
    srand (time(NULL));
    
    N = rand() % 1000;
    M = rand() % 1000;
    cout << N << " ";
    cout << M << " ";

    W = rand() % N;
    L = rand()% N;
    cout << W << " ";
    cout << L << " ";

    cout << -1 << " " << -1 << endl;

    for(int i=0; i<M; i++) {
        tmp1 = rand() % N;
        tmp2 = rand() % N;
        tmp3 = rand() % 1000000000;
        cout << tmp1 << " " << tmp2 << " " << tmp3 << endl;
    }

    return 0;
}