#include <bits/stdc++.h>

using namespace std;

// input data
int N, M, res = 0, precedente;
vector<string> S;
queue<pair<int, int>> q;    // nodo, precedente

int bfs(int n, vector<int> adj[], int visitato[]) {
    q.push({n, -1});
    visitato[n] = 1;

    while(!q.empty()) {
        n = q.front().first;
        precedente = q.front().second;
        q.pop();

        for(int vicino: adj[n]) {
            if(visitato[vicino] == 1 && vicino != precedente) res++;
            else if(visitato[vicino] == 0) {
                q.push({vicino, n});
                visitato[n] = 1;
            } 
        } 
    }
    q = { };
    return 0;
}

int main() {
//  uncomment the following lines if you want to read/write from files
//  ifstream cin("input.txt");
//  ofstream cout("output.txt");

    cin >> N >> M;
    S.resize(N);
    for (int i=0; i<N; i++)
        cin >> S[i];

    // insert your code here
    int counter = -2;
    vector<int> adj[(N+1)*(M+1)];
    int visitato[(N+1)*(M+1)] = { };
    for(int i=0; i<M; i++) {
        adj[i].push_back(i+1);
        adj[i+1].push_back(i);

        adj[i+(M+1)*N].push_back(i+(M+1)*N+1);
        adj[i+(M+1)*N+1].push_back(i+(M+1)*N);
    }
    for(int i=0; i<N*(M+1); i=i+M+1) {
        adj[i].push_back(i+M+1);
        adj[i+M+1].push_back(i);

        adj[i+M].push_back(i+M+M+1);
        adj[i+M+M+1].push_back(i+M);
    }

    for(int i=0; i<N; i++) {
        counter++;
        for(int j=0; j<M; j++) {
            counter++;

            if((int)S[i][j] == 92) {
                adj[counter].push_back(counter+M+2);
                adj[counter+M+2].push_back(counter);
            }
            else {
                adj[counter+1].push_back(counter+1+M);
                adj[counter+1+M].push_back(counter+1);
            }
        }
    }


    for(int i=0; i<N; i++) {
        if(visitato[i] == 0) bfs(i, adj, visitato);
    }
    
    cout << res << endl; // print the result
    return 0;
}