#include <bits/stdc++.h>

using namespace std;

int main() {
    // Prendo due numeri, se non sono uguali faccio la sottrazione tra il maggiore e
    // e il minore fino a quando lo sono, quello è il MCD

    int A, B;
    cin >> A >> B;

    while (A!=B) {
        if(A>B) {
            A=A-B;
        }
        else B=B-A;
    }

    cout << A;
    return 0;
}