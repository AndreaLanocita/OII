#include <stdio.h>
#include <assert.h>

double scosse(double N) {
    return N*(N-1)/4;
}


int main() {
    FILE *fr, *fw;
    int N;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(1 == fscanf(fr, "%d", &N));
    fprintf(fw, "%.6f\n", scosse((double)N));
    fclose(fr);
    fclose(fw);
    return 0;
}
