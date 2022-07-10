#include <bits/stdc++.h>

using namespace std;

string F1, F2, F3, F4;
int p1, p2, p3, p4;

int check(int l1, int l2, int M) {
    int i;
    for(i=1; i<M; i++) {
        if(F1[l1+i] != F2[l2+i]) return 0;
    }

    string v;
    v = F1.substr(l1, i);
    p3 = F3.find(v);
    p4 = F4.find(v);

    if(p3 == string::npos || p4 == string::npos) return 0;

    return 1;
}

void solve(int t) {
    int N1, N2, N3, N4, sol;
    cin >> N1 >> N2 >> N3 >> N4;

    int M;  // lunghezza virus
    cin >> M;

    cin >> F1 >> F2 >> F3 >> F4;

    for(int i=0; i<N1; i++) {
        for(int j=0; j<N2; j++) {
            if(F1[i] == F2[j] && N1 - i >= M && N2 - j >= M) {
                sol = check(i, j, M);

                if(sol == 1) {
                    p1 = i;
                    p2 = j;
                    cout << "Case #" << t << ": " << p1 << " " << p2 << " " << p3 << " " << p4 << endl;
                }
            }
        }
    }
}

int main() {
    // le seguenti due righe possono essere utili per leggere e scrivere da file

    freopen("antivirus_input_1.txt", "r", stdin);
    freopen("antivirus_output.txt", "w", stdout);

    int T;
    cin >> T;

    for (int t = 1; t <= T; t++) {
        solve(t);
    }
}