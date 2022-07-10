/*
 * This template is valid both in C and in C++,
 * so you can expand it with code from both languages.
 * NOTE: it is recommended to use this even if you don't
 * understand the following code.
 */

#include <bits/stdc++.h>

using namespace std;

// constraints
#define MAXN 1000

// input data
int R, C;
int M[MAXN][MAXN];
int v[MAXN][MAXN];
int sol = 0;

// faccio dfs anche per penisole per escluderle, flag mi dice di non togliere più volte dalla sol
// int dfs(int r, int c, int flag) {  
//     // visitato
//     v[r][c] = 1;

//     // controllo penisola
//     if((r==0 || c==0 || r==R-1 || c==C-1) && flag != 1) {
//         flag = 1;
//         sol -= 1;
//     }

//     // controllo se ho 1 di fianco
//     if(M[r+1][c] == 1 && v[r+1][c] != 1) dfs(r+1, c, flag);
//     if(M[r-1][c] == 1 && v[r-1][c] != 1) dfs(r-1, c, flag);
//     if(M[r][c+1] == 1 && v[r][c+1] != 1) dfs(r, c+1, flag);
//     if(M[r][c-1] == 1 && v[r][c-1] != 1) dfs(r, c-1, flag);

//     return 0;
// }


int dfs(int r, int c) {
    int flag = 0;
    stack<pair<int, int>> stack;

    stack.push(make_pair(r, c));

    // continuo fino a quando lo stack è vuoto
    while(!stack.empty()) {
        r = stack.top().first;
        c = stack.top().second;

        // visitato
        v[r][c] = 1;

        // tolgo da pila
        stack.pop();

        // controllo penisola
        if((r==0 || c==0 || r==R-1 || c==C-1) && flag != 1) {
            flag = 1;
            sol -= 1;
        }

        // cerco vicini non visitati
        if(M[r+1][c] == 1 && v[r+1][c] != 1) stack.push(make_pair(r+1, c));
        if(M[r-1][c] == 1 && v[r-1][c] != 1) stack.push(make_pair(r-1, c));
        if(M[r][c+1] == 1 && v[r][c+1] != 1) stack.push(make_pair(r, c+1));
        if(M[r][c-1] == 1 && v[r][c-1] != 1) stack.push(make_pair(r, c-1));
    }

    return 0;
}

int main() {
//  uncomment the following lines if you want to read/write from files
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    assert(2 == scanf("%d %d", &R, &C));
    for(int i=0; i<R; i++)
        for (int j=0; j<C; j++)
            assert(1 == scanf("%d", &M[i][j]));

    // trovo nodo da cui partire con DFS
    for(int i=0; i<R; i++) {
        for(int j=0; j<C; j++) {
            if(M[i][j] == 1 && v[i][j] != 1) {
                dfs(i, j);
                sol += 1;
            }
        }
    }

    printf("%d\n", sol); // print the result
    return 0;
}
