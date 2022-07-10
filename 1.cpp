#include <iostream>
using namespace std;

int main() {
    long long R, C, K;
    cin >> R;
    cin >> C;
    cin >> K;

    long long Ro, Co;
    if (K >= R) {
        Ro = 1;
    } else {
        Ro = (R / K) + (R % K);
    }

    if (K >= C) {
        Co = 1;
    } else {
        Co = (C / K) + (C % K);
    }

    long long tot;
    tot = Ro * Co;

    cout << tot;
    return 0;
}
