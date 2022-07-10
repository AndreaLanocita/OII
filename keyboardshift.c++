#include <bits/stdc++.h>

using namespace std;

int main() {
    unordered_map<char, char> conversione;
    conversione = {
        {'q', 'w'},
        {'w', 'e'},
        {'e', 'r'},
        {'r', 't'},
        {'t', 'y'},
        {'y', 'u'},
        {'u', 'i'},
        {'i', 'o'},
        {'o', 'p'},
        {'a', 's'},
        {'s', 'd'},
        {'d', 'f'},
        {'f', 'g'},
        {'g', 'h'},
        {'h', 'j'},
        {'j', 'k'},
        {'k', 'l'},
        {'z', 'x'},
        {'x', 'c'},
        {'c', 'v'},
        {'v', 'b'},
        {'b', 'n'},
        {'n', 'm'},
    };

    int N;
    string parola;
    char lettera;

    cin >> N;
    cin >> parola;

    for(int i=0; i<N; i++) {
        cout << conversione[parola[i]];
    }

    return 0;
}