// NOTE: it is recommended to use this even if you don't understand the following code.

#include <bits/stdc++.h>

using namespace std;

#define ll long long int
ll MOD = 1000000007;

ll res = 0;
vector<vector<int>> possibili;
void ricorsiva(int n, vector<int> &proibiti, int N) {
    if(n==N) {
        // è valido
        res+=1;
        res = res % MOD;
        return ;
    }

    for(int i: possibili[n]) {
        if(proibiti[i] == 0) {
            proibiti[i] = 1;
            ricorsiva(n+1, proibiti, N);
            // tolgo il proibito
            proibiti[i] = 0;
        } 

        
    }

    // non è possibile
    return ;
}

int main() {
    //  uncomment the following lines if you want to read/write from files
    // ifstream cin("input.txt");
    // ofstream cout("output.txt");
    int N, M;
    cin >> N >> M;

    vector<vector<int>> L(N, vector<int>(M));
    possibili.resize(N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> L[i][j];
        }
    }

    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++)
            if(L[i][j] == 1) possibili[i].push_back(j);
    }

    vector<int> proibiti;
    proibiti.assign(M, 0);
    ricorsiva(0, proibiti, N);

    cout << res << endl; // print the result

    return 0;
}
