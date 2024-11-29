#include <bits/stdc++.h> 

using namespace std;

#define vi vector<int>
#define pi pair<int, int>
#define vp vector<pi>
#define ll long long int
#define omap map<int, int>
#define umap unordered_map<int, int>
#define MAXN 100001

int sottoseq[MAXN];

int calcolasottoseq(int n) {
    // non devo mai contare quelle da 1!!
    if(sottoseq[n] != -1) return sottoseq[n];

    sottoseq[n] = 0;
    for(int i=2; i<=n; i++) sottoseq[n] += n-(i-1);
    return sottoseq[n];
}

int conta(int pos[], int N, int iniz[]) {
    int res = 0;

    // input
    int a[N];
    for(int i=0; i<N; i++) {
        int tmp; cin >> tmp;
        a[i] = tmp;
    }

    int counter = 1; // counter sottoseq
    for(int i=0; i<N-1; i++) {
        if(a[i+1] == iniz[pos[a[i]]+1]) counter++;
        else {
            res+= calcolasottoseq(counter);
            counter = 0;
        }
    }
    return res+N;
}

int main() {
    int N, M;
    cin >> N >> M;
    int res = INT32_MAX;
    for(int i=1; i<N+1; i++) sottoseq[i] = -1;
    
    int iniz[N];
    int pos[N+1]; // i numero vanno da 1 a n
    for(int i=0; i<N; i++) {
        int tmp;
        cin >> tmp;
        iniz[i] = tmp;
        pos[tmp] = i;
    }

    for(int i=1; i<M; i++) {
        res = min(res, conta(pos, N, iniz));
        // cout << 'Res ' << i << ': ' << res << endl;
    }
    cout << res;
    return 0;
}