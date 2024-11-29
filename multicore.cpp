#include <bits/stdc++.h>

#define MAXN 300
#define MAXB 10000000000

using namespace std;


vector<vector<int>> ans(MAXN, vector<int>(MAXB));
int N, B;
int C[MAXN], P[MAXN];

// k indica sia l'oggetto dell'array, sia nella ricorrenza di ans il sottoproblema per ogni oggetto da 0 a k
int solve(int k, int c) {
    // caso base
    if(k==-1) return 0;

    // controllo se ho gia calcolato la risposta per k, se si la riporto
    if(ans[k][c] != -1) return ans[k][c];

    // posso sempre tenere conto del caso in cui non aggiungo un oggetto --> prendo la soluzione fino all'oggetto prima
    ans[k][c] = solve(k-1, c);

    // controllo se l'oggetto k ci sta nello zaino, se si vedo se raggiungo una soluzione migliore aggiungendolo
    if(P[k] <= c) ans[k][c] = max(ans[k][c], solve(k-1, c-P[k]) + C[k]);

    return ans[k][c];
}

int main() {
    // se preferisci leggere e scrivere da file
    // ti basta decommentare le seguenti due righe:

    freopen("C:\\repos\\c++\\github\\OII\\multicore_input_1.txt", "r", stdin);
    freopen("C:\\repos\\c++\\github\\OII\\multicore_output_1.txt", "w", stdout);

    int T, t, i;
    cin >> T;

    for (t = 1; t <= T; t++) {
        
        // scrivi in questa variabile la risposta
        int nc;

        cin >> N >> B;
        for (i = 0; i < N; i++) cin >> C[i] >> P[i];
        
        for(i=0; i<N; i++) for(int j=0; j<B; j++) ans[i][j] = -1;
        solve(N, B);


        // for(int i=0; i<=B; i++) {
        //     sol.push_back(0);
        //     sol_temp.push_back(0);
        // }

        // for(int i=0; i<N; i++) {
        //     for(int j=0; j<=B-P[i]; j++) {
        //         if(P[i] > B) break;
        //         if(sol[j] + C[i] > sol[j+P[i]]) sol_temp[j+P[i]] = sol[j] + C[i];
        //     }
        //     sol = sol_temp;
        // }

        int maxx = 0;
        for(int j=0; i<B; i++) if(ans[N-1][j] > maxx) maxx = ans[N-1][j];
        cout << maxx << endl;
    }


    return 0;
}