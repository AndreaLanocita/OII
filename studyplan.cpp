/*
 * This template is valid both in C and in C++,
 * so you can expand it with code from both languages.
 * NOTE: it is recommended to use this even if you don't
 * understand the following code.
 */

#include <bits/stdc++.h>

using namespace std;

// constraints
#define MAXN 100000
#define MAXX INT_MAX

// input data
int N, i, j;
int H[MAXN];
vector<int> foglie;

int dfs1(int n, vector<int> adj[], int sol[], int tempo[], int H[]) {
    for(int vicino: adj[n]) {
        sol[n] = min(sol[n], tempo[vicino]-H[vicino]);
        if(sol[vicino] != MAXX) dfs1(vicino, adj, sol, tempo, H);
    }
    return 0;
}

int dfs(int n, vector<int> adj[], int visitato[]) {
  // cerco foglie
  visitato[n] = 1;
  if(adj[n].size() == 0) foglie.push_back(n);
  for(int vicino: adj[n]) {
    if(visitato[vicino] == 1) continue;
    dfs(vicino, adj, visitato);
  }
  return 0;
}

// nb cambiano le adj
int dp(int n, vector<int> adj[], int tempomin[]) {
  // caso base
  if(adj[n].size() == 0) {
    tempomin[n] = 0;
    return 0;
  }

  // ho già la sol
  if(tempomin[n] != -1) return tempomin[n];

  // calcolo come max di tutti quelli prima senza pause
  for(int vicino: adj[n]) {
    if(tempomin[n] == -1) tempomin[n] = dp(vicino, adj, tempomin);
    else tempomin[n] = max(tempomin[n], dp(vicino, adj, tempomin));
  }
  return tempomin[n];
}

int main() {
  //  uncomment the following lines if you want to read/write from files
  //  freopen("input.txt", "r", stdin);
  //  freopen("output.txt", "w", stdout);
  vector<int> adjgiusta[N];
  vector<int> adjgirata[N];
  int sol[N], tempomin[N], visitato[N];

  assert(1 == scanf("%d", &N));
  for (i = 0; i < N; i++)
    assert(1 == scanf("%d", &H[i]));
  for (i = 0; i < N; i++) {
    int k;
    assert(1 == scanf("%d", &k));
    for (j = 0; j < k; j++) {
      int s;
      assert(1 == scanf("%d", &s));

      adjgiusta[s].push_back(i);
      adjgirata[i].push_back(s);
    }
  }

  // insert your code here
  for(int i=0; i<N; i++) tempomin[i] = -1;
  for(int i=0; i<N; i++) visitato[i] = 0;
  for(int i=0; i<N; i++) sol[i] = MAXX;
  
  dfs(0, adjgiusta, visitato);
  for(int foglia: foglie) {
    dp(foglia, adjgirata, tempomin);
  }
  dfs1(0, adjgiusta, sol, tempomin, H);
  for(int i=0; i<N; i++) printf("%d\n", sol[i]);

  return 0;
}
