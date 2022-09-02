#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>\n
#define pi pair<int, int>
#define vp vector<pi>
#define ll long long int
#define pl pair<ll, ll>
#define vl vector<ll>
#define vpl vector<pl>
#define omap map<int, int>
#define umap unordered_map<int, int>

#define MAXN 1000000

void posiziona(int D, int T);

void budget(int B);

void irriga(int C, int N, vector<int>& X, vector<int>& P)
{
    
}

static int WT[MAXN][2];
static int Costo = 0;
static int K = 0;

void posiziona(int W, int T)
{
    WT[K][0] = W;
    WT[K][1] = T;
    K++;
}

void budget(int B)
{
    Costo = B;
}

int main()
{
    // Input da file:
    freopen("input.txt", "r", stdin);

    // Output su file:
    // freopen("output.txt", "w", stdout);

    int C, N;
    assert(2 == scanf("%d\n%d", &C, &N));
    vector<int> X(N);
    vector<int> P(N);
    for (int i = 0; i < N; i++) {
        assert(2 == scanf("%d %d", &X[i], &P[i]));
    }

    irriga(C, N, X, P);
    printf("%d\n%d\n", Costo, K);

    for (int i = 0; i < K; i++) {
        printf("%d %d\n", WT[i][0], WT[i][1]);
    }

    return 0;
}