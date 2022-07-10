#include <bits/stdc++.h>

using namespace std;

int griglia[50][50];
int N, M;
int massimo=0;

bool isSafe(int a, int b) {
    // tris in verticale
    if(a>=3 && griglia[a-1][b] == 1 && griglia[a-2][b] == 1) return false;
    // tris in orizzontale
    if(b>=3 && griglia[a][b-1] == 1 && griglia[a][b-2] == 1) return false;
    // tris in diagonale
    if(a>=3 && b>=3 && griglia[a-1][b-1] == 1 && griglia[a-2][b-2] == 1) return false;
    // tris in anti-diagonale
    if(a>=3 && N-b>=2 && griglia[a-1][b+1] == 1 && griglia[a-2][b+2] == 1) return false;

    // nessun tris
    return true;
}

int riempi(int a, int b, int res) {

    // se non è possibile che il risultato finale sia maggiore del massimo già memorizzato concludo questo caso
    if(res + (N-b+1)-(N-b+1)/3 + (M-a)*(N-N/3) <= massimo) return 0;

    // arrivo alla fine delle colonne, passo alla riga dopo
    if(b==N+1) {
        a+=1;
        b=1;
    }

    // sono alla casella dopo l'ultima, controllo se il risultato parziale è maggiore di quello massimo memorizzato
    if(a==M+1) {
        if(res > massimo) massimo = res; 
        return 0;
    }

    // controllo se posso aggiungere una x in questa casella, se non posso guardo solo il caso in cui non la aggiungo
    if(isSafe(a, b) == false) {
        riempi(a, b+1, res);
        return 0;
    };

    // caso in cui aggiungo una x nella casella (b, a)
    griglia[a][b] = 1;
    riempi(a, b+1, res+1);

    // caso in cui non aggiungo una x nella casella (b, a)
    griglia[a][b] = 0;
    riempi(a, b+1, res);

    return 0;
}

int gioca(int N, int M) {
    // inizializzo aggiungendo una x nella prima casella
    griglia[1][1] = 1;
    riempi(1, 2, 1);

    // inizializzo non aggiungendo una x nella prima casella
    griglia[1][1] = 0;
    riempi(1, 2, 0);

    return massimo;
}


int main() {
    FILE *fr, *fw;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(2 == fscanf(fr, "%d %d", &N, &M));

    fprintf(fw, "%d\n", gioca(N, M));
    fclose(fr);
    fclose(fw);
    return 0;
}
