#include <bits/stdc++.h>

using namespace std;

#define MAXN 100000

vector<int> V;

int sfangate(int N) {
    int sum = 0; int res = 0;

    sort(V.begin(), V.end());

    // trovo il bilancio totale
    for(int i=0; i<N; i++) {
        sum += V[i];
    }

    // sistemo il bilancio
    for(int i=0; sum <= 0; i++) {
        sum -= 2*V[i];
        res += 1;

        if(sum == 0) return sum+1;
    }

    return res;
}


int main() {
    FILE *fr, *fw;
    int N, i, temp;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(1 == fscanf(fr, "%d", &N));
    for(i=0; i<N; i++) {
        assert(1 == fscanf(fr, "%d", &temp));
        V.push_back(temp);
    }  

    fprintf(fw, "%d\n", sfangate(N));
    fclose(fr);
    fclose(fw);
    return 0;
}