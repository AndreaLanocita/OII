/*
 * This template is valid both in C and in C++,
 * so you can expand it with code from both languages.
 */

#include <bits/stdc++.h>

// input data
long double R, C, K;
long long Ro, Co;

int main() {
  //  uncomment the following lines if you want to read/write from files
  //  freopen("input.txt", "r", stdin);
  //  freopen("output.txt", "w", stdout);

  assert(3 == scanf("%lld %lld %lld", &R, &C, &K));

  Ro = ceil(R / K);
  Co = ceil(C / K);

  long long tot;
  tot = Ro * Co;

  printf("%lld\n", tot);  // print the result
  return 0;
}
