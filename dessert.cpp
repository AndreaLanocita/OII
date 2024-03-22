/*
 * This template is valid both in C and in C++,
 * so you can expand it with code from both languages.
 * NOTE: it is recommended to use this even if you don't
 * understand the following code.
 */

#include <bits/stdc++.h>

using namespace std;

// constraints
#define MAXN 1000000

// input data
int N, i, j;
int M[MAXN], L[MAXN], *F[MAXN];

int main() {
    cin.tie(0); ios::sync_with_stdio(false);
//  uncomment the following lines if you want to read/write from files
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    assert(1 == scanf("%d", &N));
    for (i=0; i<N; i++) {
        assert(2 == scanf("%d %d", &M[i], &L[i]));
        F[i] = (int*)malloc(M[i]*sizeof(int));
        for (j=0; j<M[i]; ++j)
            assert(1 == scanf("%d", &F[i][j]));
    }

    // insert your code here
    vector<int> adj[N];
    queue<int> q;
    int res = 0, n;
    for(int i=0; i<N; i++) {
        if(L[i]==0) {
            q.push(i);
            res++;
        } 
        for(int j=0; j<M[i]; j++) {
            // quando cade l'amico devo diminuire di 1
            adj[F[i][j]].push_back(i);
        }
    }

    // bfs con counter
    int visitato[N] = { };
    while(!q.empty()) {
        n = q.front();
        q.pop();

        for(int vicino: adj[n]) {
            if(visitato[vicino]==1) continue;
            L[vicino]--;
            if(L[vicino]==0) {
                visitato[vicino] = 1;
                q.push(vicino);
                res++;
            }
        }        
    }
    
    printf("%d\n", res); // print the result
    return 0;
}
