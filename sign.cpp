#include <bits/stdc++.h>

using namespace std;

char solve(long long A, long long B) {
  if(A>0 && B>0) return '+';
  if((A>=0 && B<=0) || (A<=0 && B>= 0)) return '0';
  if(A<0 && B<0) {
    if((-A+B) % 2 == 0) return '-';
    return '+';
  }
}

int main() {
//  uncomment the following lines if you want to read/write from files
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    int T;
    assert(1 == scanf("%d", &T));

    for (int i=0; i<T; i++) {
        long long A, B;
        assert(2 == scanf("%lld%lld", &A, &B));
        printf("%c\n", solve(A, B));
    }

    return 0;
}
