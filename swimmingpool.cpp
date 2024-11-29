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
#define INF  1500000

int main() {
    int N, i;

//  uncomment the following lines if you want to read/write from files
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    assert(1 == scanf("%d", &N));
    int P[N];
    for(i=0; i<N; i++) 
        assert(1 == scanf("%d", &P[i]));

    // insert your code here
    int primo, ultimo, distanza = INF;
    for(int i=0; i<N; i++) {
        if(max(P[i]-P[0], P[N-1]-P[i]) < distanza) distanza = max(P[i]-P[0], P[N-1]-P[i]);
    }

    printf("%d\n", distanza); 
    return 0;
}
