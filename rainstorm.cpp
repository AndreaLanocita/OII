/*
 * This template is valid both in C and in C++,
 * so you can expand it with code from both languages.
 * NOTE: it is recommended to use this even if you don't
 * understand the following code.
 */

#include <bits/stdc++.h>

using namespace std;

// constraints
#define MAXM 100000

// input data
int N, M, i;
int A[MAXM], B[MAXM], R[MAXM];

int dfs(int n, int mid, vector<pair<int, int>> adj[], int visitato[]) {
    visitato[n] = 1;
    for(pair<int, int> vicino: adj[n]) {
        if(visitato[vicino.first] == 1) continue;
        if(vicino.second < mid) continue;

        dfs(vicino.first, mid, adj, visitato);
    }
    return 0;
}

int main() {
//  uncomment the following lines if you want to read/write from files
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    assert(2 == scanf("%d %d", &N, &M));
    for(i=0; i<M; i++)
        assert(3 == scanf("%d %d %d", &A[i], &B[i], &R[i]));

    vector<pair<int, int>> adj[N];
    for(int i=0; i<M; i++) {
        adj[A[i]].push_back({B[i], R[i]});
        adj[B[i]].push_back({A[i], R[i]});
    }

    // insert your code here
    int l = 0, r = 100000+1, mid, flag;
    int visitato[N] = { };
    while(l<r) {
        flag = 0;

        mid = (l+r)/2;
        dfs(0, mid, adj, visitato);

        for(int i=0; i<N; i++) {
            if(visitato[i] != 1) {
                r = mid;
                flag = 1;
            } 
            visitato[i] = 0;
        } 
        if(flag!=1) {
            l = mid+1;
        }
    }
    cout << r-1;

    return 0;
}
