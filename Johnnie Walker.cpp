#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, K, T;
    cin >> N >> K;

    if (K==3) T = (N-1) * (N-2);
    else T = pow(N-1, K-2) + pow(N-1, K-3) * pow(N-2, 2);

    T = T % 666013;
    cout << T;

    return 0;
}