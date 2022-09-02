#include <bits/stdc++.h> 

using namespace std;

#define pb push_back
#define popb pop_back
#define vi vector<ll>
#define pi pair<int, int>
#define vp vector<pi>
#define ll long long int
#define pl pair<ll, ll>
#define vl vector<ll>
#define vpl vector<pl>
#define omap map<int, int>
#define umap unordered_map<ll, ll>
#define pq priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>>
#define ull unsigned long long

#define MAXN 1000000

void Accendi(int N, int acceso[], int pulsante[]) {
    int counter;
    for(int i=N; i>0; i--) {
        counter = 0;
        for(int j=1; i*j<=N; j++) {
            if(pulsante[i*j] == 1) counter++;
        }
        if((counter+acceso[i]) % 2 == 0) pulsante[i] = 1;
    }
}

static FILE *fr, *fw;
static int N;
static int acceso[MAXN + 1], pulsante[MAXN + 1];

int main() {
    int i;
    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");

    assert(1 == fscanf(fr, "%d", &N));
    for (i=1; i<=N; i++)
        assert(1 == fscanf(fr, "%d", acceso + i));

    Accendi(N, acceso, pulsante);

    for (i=1; i<=N; i++) {
        if (i > 1) fprintf(fw, " ");
        fprintf(fw, "%d", pulsante[i]);
    }
    fprintf(fw, "\n");
    return 0;
}