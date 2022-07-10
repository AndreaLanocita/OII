#include <iostream>
#include <string>

using namespace std;

int main() {
//  uncomment the following lines if you want to read/write from files
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    string iniziale, finale;
    cin >> iniziale;
    cin >> finale;

    long long sumi = 0, sumf = 0;
    int lunghezzai = iniziale.length();
    int lunghezzaf = finale.length();
    int count = 1;
    long long punti = 1;

    while (0 < lunghezzai) {
        lunghezzai --;
        char a;
        a = iniziale[lunghezzai];

        // Se incontriamo un punto, resettiamo count e ripartiamo
        if (a == '.') {
            count = 1;
            punti = punti * 256;
            continue;
        }

        int b = (int)a - 48;
        sumi += b * count * punti;
        count = count * 10;
    }

    count = 1;
    punti = 1;

    while (0 < lunghezzaf) {
        lunghezzaf --;
        char a;
        a = finale[lunghezzaf];

        // Se incontriamo un punto, resettiamo count e ripartiamo
        if (a == '.') {
            count = 1;
            punti = punti * 256;
            continue;
        }

        int b = (int)a - 48;

        sumf += b * count * punti;
        count = count * 10;
    }

    cout << (sumf - sumi + 1); // print the result
    return 0;
}
