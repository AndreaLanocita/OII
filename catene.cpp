#include <bits/stdc++.h>
#include <climits>

using namespace std;

#define ll long long int
#define vi vector<int>
#define pi pair<int, int>
#define pli pair<pair<ll, ll>, int>

pi vicino;
ll sol[20][2];
int dp(int n, vector<pi> adj[], int precedente) {
    // caso base
    if(adj[n].size() == 1 && n != 1) {
        sol[n][0] = 0;
        sol[n][1] = 0;
        return 0;
    }

    // calcolo
    sol[n][0] = 0;
    sol[n][1] = 0;

    // corner 
    if(n != 1 && adj[n].size() == 2) {
        for(pi vicino: adj[n]) {
            if(vicino.second == precedente) continue;
            dp(vicino.second, adj, n);
            if(vicino.first <= 0) sol[n][0] = max(sol[vicino.second][1], sol[vicino.second][0]);
            else sol[n][0] = max(sol[vicino.second][1], sol[vicino.second][0] + vicino.first);
        }
        sol[n][1] = sol[n][0];
        return 0;
    }

    priority_queue<pli, vector<pli>, greater<pli>> pq; 
    pq.push({{0, 0}, -1});
    pq.push({{0, 0}, -1});
    for(pi vicino: adj[n]) {
        if(vicino.second == precedente) continue;
        dp(vicino.second, adj, n);

        // 1 = prendo arco, 0 = non prendo
        if(sol[vicino.second][0] + vicino.first > sol[vicino.second][1]) {
            // controllo che l'edge non sia negativo, se lo è non conviene mai prenderlo
            if(vicino.first <= 0) continue;

            // conviene prendere questo arco
            if(pq.top().first.first < sol[vicino.second][0] + vicino.first - sol[vicino.second][1]) {
                pq.pop();
                pq.push({{sol[vicino.second][0] + vicino.first - sol[vicino.second][1], sol[vicino.second][0] + vicino.first}, vicino.second});
            }
        }
    }

    // insieriamo gli archi che conviene prendere
    int flag = 0;
    unordered_map<int, int> avoid;
    priority_queue<pli, vector<pli>> pq1; 
    while(!pq.empty()) {
        pq1.push(pq.top());
        pq.pop();
    }
    while(!pq1.empty()) {
        if(pq1.top().first.second <= 0) {
            pq1.pop();
            continue;
        }
        if(flag==0) {
            sol[n][0] += pq1.top().first.second;
            flag = 1;
            avoid[pq1.top().second] = 2;
        } 
        sol[n][1] += pq1.top().first.second;
        if(avoid.count(pq1.top().second) == 0) avoid[pq1.top().second] = 1;
        pq1.pop();
    }

    for(pi vicino: adj[n]) {
        if(vicino.second == precedente) continue;

        // già aggiunto nella fase precedente
        if(avoid.count(vicino.second) == 1) {
            if(avoid[vicino.second] == 2) continue; // aggiunto ad entrambi
            // aggiunto solo ad 1 --> all'1
            sol[n][0] += max(sol[vicino.second][0], sol[vicino.second][1]);
            continue;
        }

        sol[n][0] += max(sol[vicino.second][0], sol[vicino.second][1]);
        sol[n][1] += max(sol[vicino.second][0], sol[vicino.second][1]);
    }

    return 0;
}

ll profitto_massimo(int N, int U[], int V[], int W[]){
    vector<pi> adj[N+1];

    for(int i=0; i<N-1; i++) {
        adj[U[i]].push_back({W[i], V[i]});
        adj[V[i]].push_back({W[i], U[i]});
    }
    dp(1, adj, -1);
    ll res = max(sol[1][0], sol[1][1]);
    return res;
}

long long profitto_massimo(int, int[], int[], int[]);

int main(){
    int n;
    FILE *in = stdin, *out = stdout;
    assert(fscanf(in, "%d", &n) == 1);

    int *u = (int*)calloc(n-1, sizeof(int));
    int *v = (int*)calloc(n-1, sizeof(int));
    int *w = (int*)calloc(n-1, sizeof(int));

    for(int i=0; i<n-1; i++)
      assert(fscanf(in, "%d%d%d", u + i, v + i, w + i) == 3);

    long long answ = profitto_massimo(n, u, v, w);
    fprintf(out, "%lld\n", answ);

    free(u);
    free(v);
    free(w);

    fclose(in);
    fclose(out);

    return EXIT_SUCCESS;
}