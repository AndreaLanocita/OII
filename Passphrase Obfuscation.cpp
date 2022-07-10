#include <bits/stdc++.h>

using namespace std;

int main() {
    int tot, eliminare, index2;
    string parola;

    cin >> tot >> eliminare >> parola;

    for (int i=0; i<tot; i++) {
        index2 = i+1;

        for (int j=0; j<eliminare && index2<tot; j++) {
            if (parola[index2]>parola[i]) {
                parola.erase(i, j+1);
                eliminare -= j+1;
                tot -= j+1;

                i = -1;
                break;
            }

            index2++;
        }

        if (eliminare == 0) break;
    }

    if (eliminare != 0) parola = parola.erase(tot-eliminare, eliminare);

    cout << parola;

    return 0;
}