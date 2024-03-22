/*
 * This template is valid both in C and in C++,
 * so you can expand it with code from both languages.
 * NOTE: it is recommended to use this even if you don't
 * understand the following code.
 */

#include <iostream>
#include <vector>

// constraints
#define MAXN 100000

using namespace std;

// input data
int N;
vector<int> V;
int res = 0;

void ricorsiva(int l, int r, int maxn, int minn, int map[]) {
    // vado solo avanti da dx
    if(r<V.size()-1) {
        r++;
        map[V[r]]++;
        if(maxn != V[r] && map[V[r]] > map[maxn]) maxn = V[r];
        if(minn != V[r] && map[V[r]] > map[maxn]) maxn = V[r];
        ricorsiva(l, r, maxn, minn, map);
    }
    // annullo modifiche ala mappa
    map[V[r]]--;

    // vado solo avanti da sx
    if(l<r-1) {
        l++;
        map[V[l]]++;
        if()
    }
}

int main() {
//  uncomment the following lines if you want to read/write from files
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    cin >> N;
    V.resize(N);
    for (int i=0; i<N; i++) cin >> V[i];

    // insert your code here
    
    cout << 42 << endl; // print the result
    return 0;
}
