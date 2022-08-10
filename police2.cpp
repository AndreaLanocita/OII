/*
 * This template is valid both in C and in C++,
 * so you can expand it with code from both languages.
 * NOTE: it is recommended to use this even if you don't
 * understand the following code.
 */

#include <bits/stdc++.h>

using namespace std;

// constraints
#define MAXN 100005

// input data
int N, counter;

int dfs(int i, int nodi[], int visitato[], int counterr[]) {
  counter = 0;
  i = nodi[i];
  while(true) {
    counter++;
    if(visitato[i] == 1) return counter-counterr[i];
    counterr[i] = counter;
    visitato[i] = 1;
    i = nodi[i];
  }
}

int main() {
  //  uncomment the following lines if you want to read/write from files
  //  freopen("input.txt", "r", stdin);
  //  freopen("output.txt", "w", stdout);
  ios::sync_with_stdio(false); cin.tie(0);
  assert(1 == scanf("%d", &N));
  int nodi[N], visitato[N] = { }, counterr[N] = { };
  int res = 0;
  for (int i = 0; i < N; i++)
    assert(1 == scanf("%d", &nodi[i]));

  // insert your code here
  for(int i=0; i<N; i++) {
    if(visitato[i] == 1) continue;
    res = max(dfs(i, nodi, visitato, counterr), res);
    visitato[i] = 1;
  } 

  printf("%d\n", res); // print the result
  return 0;
}
