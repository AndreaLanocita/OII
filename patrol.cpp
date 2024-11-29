// NOTE: it is recommended to use this even if you don't understand the following code.

#include <bits/stdc++.h>

using namespace std;

int main() {
//  uncomment the following lines if you want to read/write from files
//    ifstream cin("input.txt");
//  ofstream cout("output.txt");

    int N, M, K;
    cin >> N >> M >> K;

    int a, b;
    vector<int> adj[N];
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<vector<int>> H(K);
    for (int i = 0; i < K; i++){
        int L;
        cin >> L; 
        H[i].resize(L);
        for (int j = 0; j < L; j++) {
            cin >> H[i][j];
        }
    }


    // insert your code here
    queue<int> q;
    int n = 0;
    q.push(n);
    int visitato[N] = { }; visitato[0] = 1;
    int distanze[N];
    distanze[0] = 0;

    while(!q.empty()) {
        n = q.front();
        q.pop();
        //cout << n << ' ' << distanze[n] << endl;
        if(n==N-1) break;

        for(int vicino: adj[n]) {
            if(visitato[vicino]) continue;
            visitato[vicino] = 1;
            q.push(vicino);
            distanze[vicino] = distanze[n] + 1;
        }
    }


    cout << distanze[N-1] << endl; // print the result
    
    return 0;
}
