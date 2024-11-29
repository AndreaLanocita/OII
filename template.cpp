#include <bits/stdc++.h>

using namespace std;


int solve(int N, int K, int* S) {
    long long best = 0, c_dx = 0, z_dx = 0, c_sx = 0, z_sx = 0, p1 = 0, p2 = N;

    for(long long i=N-1; i>=0; i--) {
        if(c_dx <= K) {
            c_dx += S[i];
            if(S[i] == 0) z_dx++;
            p2 = i;
        } 
        else break;
    }
    
    if(p2 < N) best = z_dx;
    for( ; p1 < N; p1++) {
        c_sx += S[p1];
        if(S[p1] == 0) z_sx++;

        if(p2 >= N) goto fine;
        while(c_sx + c_dx > K) {
            c_dx -= S[p2];
            if(S[p2] == 0) z_dx--;
            p2++;
            if(p2 >= N) break;
        }
        fine:
        if(p2 >= N && c_sx <= K) best = max(z_sx, best);
        if(p2<N) best = max(z_dx + z_sx, best);
    }

    return best;
}

#define MAXN 20000000

static int N, K, i;
static int s[MAXN];

int solve(int N, int K, int* S);

static FILE *fin, *fout;

int main(){
    fin = fopen("C:\\repos\\c++\\github\\OII\\input.txt", "r");
    fout = fopen("C:\\repos\\c++\\github\\OII\\output.txt", "w");
    assert(2 == fscanf(fin, "%d%d", &N, &K));
    for(i=0; i<N; i++) assert(1 == fscanf(fin, "%d", &s[i]));
    fprintf(fout, "%d\n", solve(N, K, s));
    fclose(fin);
    fclose(fout);
    return 0;
}
