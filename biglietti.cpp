#include <stdio.h>
#include <assert.h>

int compra(int N, int M, int A, int B) {
    int sol;
    sol = 0;

    while(N!=0) {
        if(N>M && (B/M) < A) {
            sol += N/M * B;
            N -= N/M * M;
        }

        if(N<M && B<(N*A)) {
            sol += B;
            N = 0;
        }

        else {
            sol += N*A;
            N = 0;
        }
    }



    return sol;
}

int main() {
    FILE *fr, *fw;
    int N, M, A, B;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");

    assert(4 == fscanf(fr, "%d%d%d%d", &N, &M, &A, &B));

    fprintf(fw, "%d\n", compra(N, M, A, B));
    fclose(fr);
    fclose(fw);
    return 0;
}
