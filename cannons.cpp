#include <bits/stdc++.h>

using namespace std;

// constraints
#define MAXN 1000000

// input data
int N, i;
int T[MAXN];

int dfs(int n, int T[], int visitato[], int N, int ultimo) {
    for(int i=n; ;) {
        visitato[i] = 1;
        if(visitato[T[i]]) return ultimo;
        i=T[i];
        if(i>ultimo) ultimo = i;
    }
    return ultimo;
}

int main() {
//  uncomment the following lines if you want to read/write from files
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    assert(1 == scanf("%d", &N));
    for(i=0; i<N; i++)
        assert(1 == scanf("%d", &T[i]));

    int visitato[N] = {};
    vector<pair<int, int>> archi; // primo, ultimo
    for(int i=0; i<N; i++) {
        if(visitato[i]) continue;
        int ultimo = dfs(i, T, visitato, N, i);
        archi.push_back({i, ultimo});
    }

    long long res = 0;
    for(int i=0; i<archi.size()-1; i++) {
        res += archi[i+1].first-archi[i].second;
    }

    cout << res << endl;
    return 0;
}
