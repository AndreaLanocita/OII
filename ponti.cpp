#include <bits/stdc++.h>

using namespace std;

#define MAXN 10005
#define MAXM 100005

int p[MAXN], r[MAXN], c, b;

void make_set(int x) {
    p[x] = x;
    r[x] = 0;
}

int find(int x) {
    if(p[x] == x) return x;
    return p[x] = find(p[x]);
}

void unionn(int x, int y) {
    c = find(x);
    b = find(y);

    if(c==b) return;
    if(r[c] > r[b]) {
        p[b] = c;
    } else {
        p[c] = b;
        if(c==b) r[b]++;
    }
}

int costruisci(int N, int M, int da[], int a[]) {
    for(int i=0; i<N; i++) make_set(i);
    for(int i=0; i<M; i++) unionn(a[i], da[i]);
    int componenti = 0, visti[N] = { };
    for(int i=0; i<N; i++) {
        if(visti[find(i)] == 1) continue;
        visti[find(i)] = 1;
        componenti++;
    }       

    return componenti-1;
}


int da[MAXM], a[MAXM];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    FILE *fr, *fw;
    int N, M, i;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(2 == fscanf(fr, "%d%d", &N, &M));
    for(i=0; i<M; i++)
        assert(2 == fscanf(fr, "%d%d", &da[i], &a[i]));

    fprintf(fw, "%d\n", costruisci(N, M, da, a));
    fclose(fr);
    fclose(fw);
    return 0;
}
