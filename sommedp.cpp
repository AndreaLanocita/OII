#include <bits/stdc++.h>

using namespace std;

int ans[550][550];

int ricorsiva(vector<int> &v, int x, int y, int somma) {  // y incluso
    // caso base
    if(y-x==0) return 0; // non può essere scelto, è da solo --> non sono state fatte somme, ne tengo conto quando controllo se res<somma sotto
    if(y-x==1) return abs(v[x] + v[y]);

    // ho il res
    if(ans[x][y] != -1) return ans[x][y];

    // calcolo
    int tmp;
    int res = INT_MAX;
    int somma_tmp = somma;
    for(int i=x; i<y; i++) {
        // calcolo il risultato ricorsivamente per ciascun prefisso del vettore e la parte che ne rimane
        somma_tmp -= v[i];
        tmp = max(ricorsiva(v, x, i, somma-somma_tmp), ricorsiva(v, i+1, y, somma_tmp));
        // scelgo la divisione che porta il risultato migliore
        if(tmp<res) res = tmp;
    }
    
    // tengo conto della somma fatta in questo punto della ricorsione (quella tra le due parti dell'array che ho guardato separatamente)
    ans[x][y] = max(res, abs(somma));
    return ans[x][y];
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int N;
    cin >> N;

    for(int i=0; i<=N; i++) {
        for(int j=0; j<=N; j++) ans[i][j] = -1;
    }
    vector<int> v(N);
    int somma = 0;
    for(int i=0; i<N; i++) {
        cin >> v[i];
        somma += v[i];
    }
    cout << ricorsiva(v, 0, N-1, somma);
}