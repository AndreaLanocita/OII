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

// input data
int N, i;
int C[MAXN];
long long int M;

int main() {
//  uncomment the following lines if you want to read/write from files
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);
    int res;
    assert(2 == scanf("%d %lld", &N, &M));
    for(i=0; i<N; i++) 
        assert(1 == scanf("%d", &C[i]));

    int tot = 0;
    for(int i=0; i<N; i++) tot += C[i];
    if(M % tot != 0) M = M % tot;
    else M = tot;

    while(M!=0) {
        for(int i=0; i<N; i++) {
            M -= C[i];
            if(M==0) {
                res = i;
                break;
            }
        }
    }
    
    printf("%d\n", res); // print the result
    return 0;
}
