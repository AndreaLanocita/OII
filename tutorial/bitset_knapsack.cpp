#include <bits/stdc++.h>

using namespace std;

#define MAXW 1000

/* 
Given N objects of weight w, can we find a knapsack of weight W? 
We use a bitset instead of a boolean vector because it is faster.

It is not unbounded.
*/

int main() {
    bitset<MAXW> reached;
    int N, W;
    cin >> N >> W;
    int weights[N];
    for(int i=0; i<N; i++) cin >> weights[i];

    // base case
    reached[0] = 1;
    // We add w[i] 0s at the start of the bitset (reach the positin in pos+w[i])
    // and update the bitset to have 1s wherever at least of the two bisets has a 1 (OR)
    for(int i=0; i<N; i++) reached |= (reached << weights[i]);

    cout << reached[W];
}