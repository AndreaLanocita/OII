#include <bits/stdc++.h>

using namespace std;

int main() {
    int n_impianti, temp, energia;
    vector<int> v_impianti;

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin >> n_impianti;

    for (int i=0; i<n_impianti; i++) {
        cin >> temp;
        v_impianti.push_back(temp);
    }

    for (int i=0; i<n_impianti; i++) {
        energia = v_impianti[i];
        for (int j=i+1; j<i+n_impianti; j++) {
            if (energia <= 10) break;

            if (j==(i+n_impianti-1)) {
                cout << i+1;
                return 0;
            }
            energia += (v_impianti[j%n_impianti] - 10);
        }
        energia = 0;
    }
    return 0;
}