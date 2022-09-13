#include <bits/stdc++.h>

using namespace std;

#define MAXN 1000000

void posiziona(int D, int T);

void budget(int B);

struct seme {
    int x, y;
    seme(): x(0), y(0) {};
    seme(int x, int y) : x(x), y(y) {};
};  

// corrisponde al valore assoluto della differenza
long long deltax(seme& a, seme& b) {
    if(a.x>b.x) return a.x-b.x;
    return b.x-a.x;
}
long long deltay(seme& a, seme& b) {
    if(a.y>b.y) return a.y-b.y;
    return b.y-a.y;
}

// controlla se valga la pena di unire i due semi
bool check(seme a, seme b, int C) {
    int dx, dy;
    dx = deltax(a, b);
    dy = deltay(a, b);
    if(b.y + C > (dx-dy)/2 || dx <= dy) return true;
    return false;
}

// costruisce il nuovo seme con i due uniti
seme buildd(seme a, seme b) {
    int tmp1;
    int dx = deltax(a, b);
    int dy = deltay(a, b);
    if(dx <= dy) {
        if(a.y > b.y) return a;
        return b;
    }

    tmp1 = dy + (dx-dy)/2;
    // quello con la x minore ha anche la y minore
    if(a.y <= b.y) return {a.x + tmp1, a.y+tmp1};
    // contrario
    else return {b.x - tmp1, b.y + tmp1};
}

bool func(seme a, seme b) {if(a.x<b.x) return true; if(a.x==b.x && a.y>b.y) return true; return false;}

void irriga(int C, int N, vector<int>& X, vector<int>& P)
{
    seme posizioni[N]; // {pos irrigatore, costo}
    seme lista[N]; // per il sort

    for(int i=0; i<N; i++) {
        lista[i] = {X[i], P[i]};
    } 
    sort(&lista[0], &lista[N], func);

    seme seme = lista[0];
    posizioni[0] = lista[0];
    int index = 0;
    // per ogni seme controllo se posso unirlo con il successivo
    for(int i=1; i<N; i++) {    
        if(check(seme, lista[i], C) == true) {
            if(deltax(seme, lista[i]) <= deltay(seme, lista[i])) continue;
            seme = buildd(seme, lista[i]);
            posizioni[index] = seme;
        } 
        else {
            index++;
            seme = lista[i];
            posizioni[index] = lista[i];
        }
    }

    int costo = 0;
    for(int i=0; i<index+1; i++) {
        costo += C + posizioni[i].y;
        posiziona(posizioni[i].x, posizioni[i].y);
    }
    budget(costo);
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