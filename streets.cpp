/*
 * This template is valid both in C and in C++,
 * so you can expand it with code from both languages.
 */

#include <bits/stdc++.h>

using namespace std;

// constraints
#define MAXN 100

// input data
int N, M, i, a, b;
int D[MAXN];

int main() {
  //  uncomment the following lines if you want to read/write from files
  //  freopen("input.txt", "r", stdin);
  //  freopen("output.txt", "w", stdout);
  vector<int> adj[MAXN];
  vector<int> archi(MAXN, 0);

  assert(2 == scanf("%d %d", &N, &M));
  for (i = 0; i < N; i++) assert(1 == scanf("%d", &D[i]));
  for (i = 0; i < M; i++) {
    assert(2 == scanf("%d %d", &a, &b));
    // a road can be built between `a` and `b`
    archi[a]++;
    archi[b]++;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  // troviamo quello con minor budget
  vector<pair<int, int>> sortt;
  for(int i=0; i<N; i++) sortt.push_back({D[i], i});
  sort(sortt.begin(), sortt.end());
  for(pair<int, int> n: sortt) {
      while(D[n.second] != 0 || archi[n.second] != 0) {
        // cerchiamo 

      
    }
  }
  

  printf("%d %d\n", 0, 1);  // print the result
  return 0;
}
