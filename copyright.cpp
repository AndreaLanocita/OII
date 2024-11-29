#include <bits/stdc++.h>

using namespace std;

#define MAXN 1000010
bool trattino = 1; // se va aggiunto ', 2018' è 1
bool trattino_0 = 1; // è 1 se cambi l'ultimo numero con un 8, 0 se va aggiunto '-2018'
int punto; 
int numero;

int update_copyright(int N, char S[]) {
    // troviamo dove c'è il copyright
    for(int i=0; i<N; i++) {
        if(
            S[i] == 'C' && 
            S[i+1] == 'o' && 
            S[i+2] == 'p' && 
            S[i+3] == 'y' && 
            S[i+4] == 'r' && 
            S[i+5] == 'i' && 
            S[i+6] == 'g' && 
            S[i+7] == 'h' && 
            S[i+8] == 't' 
        ) {
            int j = i+9;
            while(true) {
                if(S[j] == '.') {
                    punto = j;

                    if(S[j-1] == '7' && S[j-2] == '1' && S[j-3] == '0' && S[j-4] == '2') {
                        if(S[j-5] == ',') {
                            trattino_0 = 0;
                        }
                        trattino = 0;
                    } 
                    break;
                }
                j++;
            }
        }
    }

    return N;
}


char S[MAXN];

int main() {
    FILE *fr, *fw;
    int N, i;

    fr = fopen("C:\\repos\\c++\\github\\OII\\input.txt", "r");
    fw = fopen("C:\\repos\\c++\\github\\OII\\output.txt", "w");


    assert(1 == fscanf(fr, "%d\n", &N));
    for(i=0; i<N; i++)
        assert(1 == fscanf(fr, "%c", &S[i]));

    N = update_copyright(N, S);

    fprintf(fw, "%d\n", N);

    if(trattino == 1) {
        // cambiare il numero...
        
        for(i=0; i<punto; i++) {
            fprintf(fw, "%c", S[i]);
        }
        fprintf(fw, "%c", ',');
        fprintf(fw, "%c", ' ');
        fprintf(fw, "%c", '2');
        fprintf(fw, "%c", '0');
        fprintf(fw, "%c", '1');
        fprintf(fw, "%c", '8');
        for(i=punto; i<N; i++) {
            fprintf(fw, "%c", S[i]);
        }
    }
    else if(trattino_0 == 0) {
        for(i=0; i<punto; i++) {
            fprintf(fw, "%c", S[i]);
        }
        fprintf(fw, "%c", '-');
        fprintf(fw, "%c", '2');
        fprintf(fw, "%c", '0');
        fprintf(fw, "%c", '1');
        fprintf(fw, "%c", '8');
        for(i=punto; i<N; i++) {
            fprintf(fw, "%c", S[i]);
        }
    }
    else {
        S[punto-1] = '8';
        for(i=0; i<N; i++) {
            fprintf(fw, "%c", S[i]);
        }
    }
        
    fclose(fr);
    fclose(fw);
    return 0;
}

