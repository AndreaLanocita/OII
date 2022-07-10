#include <bits/stdc++.h>

using namespace std;

map<int, vector<int>> cestini;

void inizia(int N, int M) {
    for(int i=0; i<N; i++) {
        cestini[0].push_back(i);
    }
}

void sposta(int a, int b) {
    cestini[b].push_back(cestini[a][cestini[a].size()-1]);
    cestini[a].pop_back();
}

int controlla(int a, int i) {
    if(cestini[a].size() <= i) {
        return -1;
    }
    else {
        return cestini[a][i];
    }
}

int main() {
    // Uncomment the following lines if you want to read/write from files
    // ifstream cin("input.txt");
    // ofstream cout("output.txt");

    ios::sync_with_stdio(false);

    int N, M, Q;
    cin >> N >> M >> Q;

    inizia(N, M);

    for (int i = 0; i < Q; i++) {
        char t;
        int a, b;
        cin >> t >> a >> b;
        if (t == 's') {
            sposta(a, b);
        } else {
            cout << controlla(a, b) << '\n';
        }
    }

    return 0;
}