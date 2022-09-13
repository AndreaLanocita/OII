#include <bits/stdc++.h>

using namespace std;

long long conta(int S, int s[], int P, int p[]) {
  // cecro una seuqneza corretta, moltiplico quelli a sx per quelli a dx, 
  // tolgo l'overlap con la sequenza precedente 
  long long pp=0, pd = 0, ps = 0, res = 0, previuoss = -1;
  while(ps<=pd && pd<S) {
    if(s[pd] == p[pp]) {
      if(pp==0) ps = pd;
      pp++;
    } 
    // se trovo un primo migliore lo cambio
    else if(pp==1 && s[pd]==p[pp-1]) ps = pd;

    if(pp==P) {
      // trovato la disposizione
      res += (ps-previuoss)*(S-pd);

      previuoss = ps;
      pp = 0; 
      pd = ps = ps+1; // riparto da quello dopo il primo per evitare di perdermi roba in mezzo
      continue;
    }
    pd++;
  }
  return res;
}

long long conta(int S, int s[], int P, int p[]);

int main() {
  int S, P;
  assert(2 == scanf("%d %d", &S, &P));

  int *s = (int*)malloc(S*sizeof(int));
  int *p = (int*)malloc(P*sizeof(int));

  for(int i=0; i<S; i++) assert(1 == scanf("%d", s+i));
  for(int i=0; i<P; i++) assert(1 == scanf("%d", p+i));

  printf("%lld\n", conta(S, s, P, p));
  return 0;
}