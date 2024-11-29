#include <bits/stdc++.h>

using namespace std;

#define MAXM 200000

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
}


int A[MAXM];
int B[MAXM];

int main() {
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
