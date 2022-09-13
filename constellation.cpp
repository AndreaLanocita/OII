// NOTE: it is recommended to use this even if you don't understand the following code.

#include <bits/stdc++.h>

using namespace std;

#define MAXN 250000

vector<int> adjx[MAXN];
vector<int> adjy[MAXN];

long long res = 0;
void dfs(int n, int X[], int Y[], long long flagx=0, long long flagy=0) {
    for(int vicino: adjx[X[n]]) {
        if(vicino!=n) flagx++;
    }
    for(int vicino: adjy[Y[n]]) {
        if(vicino!=n) flagy++;
    }
    if(res==0) res = flagx*flagy;
    else res += flagx*flagy;
}

int main() {
//  uncomment the following lines if you want to read/write from files
//  ifstream cin("input.txt");
//  ofstream cout("output.txt");

    cin.tie(0); ios::sync_with_stdio(false);
    int N;
    cin >> N;
    int X[N]; int Y[N];

    for (int i = 0; i < N; i++) {
        cin >> X[i] >> Y[i];
        adjx[X[i]].push_back(i);
        adjy[Y[i]].push_back(i);
    }

    for(int i=0; i<N; i++) dfs(i, X, Y);

    cout << res << endl; // print the result
    
    return 0;
}
