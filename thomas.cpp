#include <bits/stdc++.h>
using namespace std;

#define MAXN 5000
#define MAXK 5000

int P[MAXN];
int mangia(int N, int K, int somma) {
    // Mettete qui il codice della soluzione
    //problema dello zainetto al contrario
    //massimizzo la quantità di cibo che mangio restando sotto alla capacità del mio zaino che è somma-k;
    int c=somma-K;
    vector<vector<int>> matrice(2,vector<int>(c+1,0));

    for(int i =0; i < N+1; i++)
    {
        for(int j=0; j < c+1; j++)
        {
            if(i==0 || j==0) matrice[i%2][j]=0;
            else if(P[i-1]>j) matrice[i%2][j]=matrice[(i-1)%2][j];
            else {
                matrice[i%2][j]=max(matrice[(i-1)%2][j], P[i-1]+matrice[(i-1)%2][j-P[i-1]]);
            }
        }

    }


    return somma-matrice[N%2][c];
}




int main() {
    int N, K;
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> N >> K;
    int somma =0;
    for(int i=0; i<N; i++){
        cin >> P[i];
        somma += P[i];
    }
        

    cout <<  mangia(N, K,somma);

    return 0;
}