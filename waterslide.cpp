#include <bits/stdc++.h>

using namespace std;

#define MAXM 200000

int find_pool(int N, int M, int P, int A[], int B[]) {
    vector<int> adj[N];
    int counter_pool[N-(N-P)];
    for(int i=0; i<M; i++) adj[A[i]].push_back(B[i]);

    int visitato[N] = { }; int n;
    queue<int> q;
    q.push(0);
    while(!q.empty()) {
        n = q.front();
        q.pop();


        for(int vicino: adj[n]) {
            if(vicino>=N-P) counter_pool[vicino-(N-P)]++;
            if(visitato[vicino] == 1) continue;
            q.push(vicino);
            visitato[vicino] = 1;
        }
    }
    int res_sum = 0, res;
    for(int i=0; i<N-(N-P); i++) {
        if(counter_pool[i] > res_sum) {
            res_sum = counter_pool[i];
            res = i+(N-P);
        }
    }
    return res;
}


int A[MAXM];
int B[MAXM];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    FILE *fr, *fw;
    int N, M, P, i;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(3 == fscanf(fr, "%d %d %d", &N, &M, &P));
    for(i=0; i<M; i++)
        assert(2 == fscanf(fr, "%d %d", &A[i], &B[i]));

    fprintf(fw, "%d\n", find_pool(N, M, P, A, B));
    fclose(fr);
    fclose(fw);
    return 0;
}
