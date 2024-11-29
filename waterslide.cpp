#include <bits/stdc++.h>

using namespace std;

#define MAXM 200000

<<<<<<< HEAD
long double solve(int N, vector<long double> &aff, vector<int> adj[], vector<int> &archi)
{
    if(N==0)  {
        aff[N]=1.0;
        return 1.0;
    }
    if(aff[N]!=-1.0) return aff[N];
    
    aff[N]=0;
    for(int vicino: adj[N]) {
        solve(vicino, aff, adj, archi);
        aff[N]+=(aff[vicino]/archi[vicino]);
    }

    return aff[N];
}


int find_pool(int N, int M, int P, int A[], int B[]) {
    vector<int> adj[N+5];
    vector<int> archi(N+5,0);

    for(int i =0; i < M; i++){
        adj[B[i]].push_back(A[i]);
        archi[A[i]]++;
    }

    vector<long double> aff(N+5,-1);
    long double massimo=0;
    int sol;
    for(int i = N-P; i <N ; i++) 
    {
        if(solve(i, aff, adj, archi)> massimo)
        {
            massimo=max(massimo, solve(i, aff, adj, archi));
            sol=i;
        }
        
    }

    return sol;
=======
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
>>>>>>> e36d179ced5161c8c6ee992a38584e6ba5e578cb
}


int A[MAXM];
int B[MAXM];

int main() {
<<<<<<< HEAD
=======
    ios::sync_with_stdio(false); cin.tie(0);
>>>>>>> e36d179ced5161c8c6ee992a38584e6ba5e578cb
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
