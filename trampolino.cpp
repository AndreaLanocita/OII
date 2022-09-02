#include <bits/stdc++.h>

using namespace std;

#define pi pair<int, int>
#define MAXN 100500

int salta(int N, int E[]) {
    // pos = in che trampolino mi trovo
    // index = fino a dove ho controllato
    // d = distanza tra pos e index
    int pos = 0, index = 1, res=0, d=1;
    pi maxx;   // maxE, index

    while(true) {
        res++;
        if(pos + E[pos] >= N) return res;
        maxx = {0, 0}; d = 1;
        for(index=index; index <= pos + E[pos]; index++) {
            if(E[index]+d > maxx.first) maxx = {E[index]+d, index};
            d++;
        } 
        pos = maxx.second;
    }

    return res;
}


int E[MAXN];

int main() {
    cin.tie(0); ios::sync_with_stdio(false);
    FILE *fr, *fw;
    int N, i;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(1 == fscanf(fr, "%d", &N));
    for(i=0; i<N; i++)
        assert(1 == fscanf(fr, "%d", &E[i]));

    fprintf(fw, "%d\n", salta(N, E));
    fclose(fr);
    fclose(fw);
    return 0;
}
