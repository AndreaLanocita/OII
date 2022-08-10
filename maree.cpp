#include <bits/stdc++.h>
#include <climits>

using namespace std;

int solve(int N, int M, int T, int* S, int* E) {
    //faccio un grafo bidirezionale, ma mi tengo come secondo parametro una flag
    // 0 (percorribile prima della marea) o 1 (percorribile dopo la marea)
    // poi faccio dijikistra tenendo conto che posso aspettare che arrivi la marea
    // per visitare alcuni nodi altrementi irraggiungibili
    vector<pair<int, int>> adj[N];  // 0 (percorribile prima della marea) o 1 (percorribile dopo la marea)
    int visitato[N] = { }, distanze[N], nodo;
    distanze[0] = 0;
    for(int i=1; i<N; i++) distanze[i] = INT_MAX;
    // distanza, nodo
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0});

    for(int i=0; i<M; i++) {
        adj[S[i]].push_back({E[i], 0});
        adj[E[i]].push_back({S[i], 1});
    }

    for(int i=0; i<N; i++) {
        // cerco il nodo
        while(!pq.empty()) {
            nodo = pq.top().second;
            if(visitato[nodo] == 0 && distanze[nodo] == pq.top().first) break;
            pq.pop();
        }
        if(pq.empty()) break;
        pq.pop();
        visitato[nodo] = 1;
        if(nodo == N-1) break;

        // controllo i vicini
        for(pair<int, int> vicino: adj[nodo]) {
            // posso percorrere la strada? posso migliorare la distanza?
            if(visitato[vicino.first] == 1) continue;
            if(distanze[nodo] < T && vicino.second == 0 && distanze[nodo] + 1 < distanze[vicino.first]) {
                distanze[vicino.first] = distanze[nodo] + 1;
                pq.push({distanze[vicino.first], vicino.first});
            }
            if(vicino.second == 1 && max(distanze[nodo], T) + 1 < distanze[vicino.first]) {
                distanze[vicino.first] = max(distanze[nodo], T) + 1;
                pq.push({distanze[vicino.first], vicino.first});
            }
        }
    }

    if(distanze[N-1] == INT_MAX) return -1;
    return distanze[N-1];
}

#define MAXM 3000000

static int i, N, M, T;
static int S[MAXM], E[MAXM];

int solve(int N, int M, int T, int* S, int* E);

static FILE *fin, *fout;

int main(){
    fin = fopen("input.txt", "r");
    fout = fopen("output.txt", "w");
    assert(3 == fscanf(fin, "%d%d%d", &N, &M, &T));
    for(i=0; i<M; i++) assert(2 == fscanf(fin, "%d%d", S+i, E+i));
    fprintf(fout, "%d\n", solve(N, M, T, S, E));
    fclose(fin);
    fclose(fout);
    return 0;
}