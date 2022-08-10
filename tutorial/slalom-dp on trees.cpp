#include <bits/stdc++.h>

using namespace std;

int sol[400500][2];
vector<int> sol_v;

int dfss(int n, int precedente, int costo[], vector<int> adj[], int preso) {
    if(preso==0) {
        // prendo per forza i successivi, non prendo questo
        for(int vicino: adj[n]) {
            if(vicino == precedente) continue;
            sol_v.push_back(vicino);
            dfss(vicino, n, costo, adj, 1);
        }
    } else {
        // posso scegliere se prendere o non prendere i successivi
        for(int vicino: adj[n]) {
            if(vicino == precedente) continue;
            if(sol[vicino][1] <= sol[vicino][0]) {  // prendo il successivo
                sol_v.push_back(vicino);
                dfss(vicino, n, costo, adj, 1);
            } else {    // non prendo il successivo
                dfss(vicino, n, costo, adj, 0);
            }
        }
    }
    return 0;
}

int dfs(int n, int precedente, int costo[], vector<int> adj[]) {
    sol[n][0] = 0;
    sol[n][1] = costo[n];

    for(int vicino: adj[n]) {
        if(vicino == precedente) continue;

        dfs(vicino, n, costo, adj);
        // se non prendo questo nodo devo per forza prendere quelli successivi
        sol[n][0] += sol[vicino][1];
        // se lo prendo, posso scegliere
        sol[n][1] += min(sol[vicino][1], sol[vicino][0]);
    }
    return 0;
}

int main() {
//  uncomment the following lines if you want to read/write from files
    ifstream cin("input.txt");
    ofstream cout("output.txt");
    int N;
    cin >> N;
    int costo[N+1];
    int tmp1, tmp2;

    for(int i=1; i<N+1; i++)
        cin >> costo[i];
    
    vector<int> adj[N+1];

    for(int i=0; i<N-1; i++) {
        cin >> tmp1 >> tmp2;
        adj[tmp1].push_back(tmp2);
        adj[tmp2].push_back(tmp1);
    }

    dfs(1, -1, costo, adj);
    if(sol[1][1] <= sol[1][0]) {
        dfss(1, -1, costo, adj, 1);
        sol_v.push_back(1);
    } 
    else dfss(1, -1, costo, adj, 0);

    cout << sol_v.size() << endl; // print the result
    for(int i=0; i<sol_v.size(); i++) cout << sol_v[i] << " ";
    
    return 0;
}