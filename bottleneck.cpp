#include <bits/stdc++.h>
#include <climits>

using namespace std;

#define MAXN 100000
#define MAXM 1000000

int Analizza(int N, int M, int W, int L, int arco_da[], int arco_a[], int capacita[], int R, int C) {
    // W e L
    vector<pair<int, int>> adj[N+1];  // nodi, capacità
    int visitato[N+1] = { };
    pair<int, int> distanze[N+1];     // n. nodi, min velocità
    queue<pair<int, int>> q;    // nodo, min capacità

    // inserisco gli archi nella lista
    for(int i=0; i<M; i++) {
        adj[arco_da[i]].push_back({arco_a[i], capacita[i]});
        adj[arco_a[i]].push_back({arco_da[i], capacita[i]});
    }

    // bfs
    q.push({W, INT_MAX});
    visitato[W] = 1;
    distanze[W] = {0, INT_MAX};
    int nodo, res_nodi = INT_MAX;

    while(!q.empty()) {
        while(!q.empty()) {
            nodo = q.front().first;
            if(q.front().second == distanze[nodo].second) break;
            q.pop();
        }
        if(distanze[nodo].first == res_nodi || q.empty()) break;
        q.pop();

        for(pair<int, int> vicino: adj[nodo]) {
            if(visitato[vicino.first] == 0 || (min(vicino.second, distanze[nodo].second) < distanze[vicino.first].second && distanze[nodo].first + 1 <= distanze[vicino.first].first)) {
                q.push({vicino.first, min(vicino.second, distanze[nodo].second)});
                visitato[vicino.first] = 1;
                distanze[vicino.first].first = distanze[nodo].first + 1;
                distanze[vicino.first].second = min(vicino.second, distanze[nodo].second);

                if(vicino.first == L) res_nodi = distanze[nodo].first + 1;
            }
        }
    }

    return distanze[L].second;
}

static FILE *fr, *fw;

static int N, M, W, L;
static int R, C;
static int arco_da[MAXM], arco_a[MAXM], capacita[MAXM];

int Analizza(int N, int M, int W, int L, int arco_da[], int arco_a[], int capacita[], int R, int C);

int main(){
    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");

    int i;
    assert(4 == fscanf(fr, "%d%d%d%d", &N, &M, &W, &L));
    assert(2 == fscanf(fr, "%d%d", &R, &C));
    for (i=0; i<M; i++)
        assert(3 == fscanf(fr, "%d%d%d", arco_da+i, arco_a+i, capacita+i));

    fprintf(fw, "%d\n", Analizza(N, M, W, L, arco_da, arco_a, capacita, R, C));

    fclose(fr);
    fclose(fw);
    return 0;
}