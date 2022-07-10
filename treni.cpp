#include <bits/stdc++.h>

using namespace std;

int sol[1000000][3];
int N; int* c; int* d;

int dp(int n, int t) {
    // bottom-down
    // imposto caso base
    if(n==-1) return 0;

    // controllo se ho già sol
    if(sol[n][t] != -1) return sol[n][t];

    // eseguo
    sol[n][0] = max(max(dp(n-1, 0), dp(n-1, 1)), dp(n-1, 2));   // oggi non prendo il treno
    sol[n][1] = sol[n][0] + c[n];    // oggi prendo SFT
    sol[n][2] = dp(n-1, 0) + d[n]; // oggi prendo HFT

    // ritorna sol corrispondente
    return sol[n][t];
}

int tempo_massimo(int f, int a[], int b[])
{
    N = f;
    c = a;
    d = b;
    for(int i=0; i<N; i++) {
        sol[i][0] = -1;
        sol[i][1] = -1;
        sol[i][2] = -1;
    }
    dp(N-1, 0);
    dp(N-1, 1);
    dp(N-1, 2);
    return max(sol[N-1][1], sol[N-1][2]);
}

int main()
{
    int n;
    FILE *in = stdin, *out = stdout;
    assert(fscanf(in, "%d", &n) == 1);

    int *a = (int*)calloc(n, sizeof(int));
    int *b = (int*)calloc(n, sizeof(int));

    for(int i=0; i<n; i++){
      assert(fscanf(in, "%d", a + i) == 1);
      assert(fscanf(in, "%d", b + i) == 1);
    }

    int answ = tempo_massimo(n, a, b);
    fprintf(out, "%d\n", answ);

    free(a);
    free(b);

    fclose(in);
    fclose(out);

    return EXIT_SUCCESS;
}