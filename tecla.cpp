#include <bits/stdc++.h>

using namespace std;

// input data
int N, M, res;
vector<int> ordine;
vector<int> adj[35];

int torno_indietro(int nodo, int counter, vector<int> &counterr) {
    if(nodo == 0 && counter%2 == 1) {
        ordine.push_back(0);
        return 1;
    }

    for(int vicino=0; vicino < adj[nodo].size(); vicino++) {
        // cerco tutti i vicini già visitati che abbiamo un counter minore
        // voglio tornare a zero
        if(counterr[adj[nodo][vicino]] != -1 && counterr[adj[nodo][vicino]] < counterr[nodo]) {
            torno_indietro(adj[nodo][vicino], counter+1, counterr);
            ordine.push_back(nodo);
            return 1;
        } 
    }
    return 0;
}

int dfs(int nodo, int counter, vector<int> &counterr) {
    counterr[nodo] = counter;
    for(int vicino=0; vicino < adj[nodo].size(); vicino++) {
        // visitato
        if(counterr[adj[nodo][vicino]] != -1) {
            // cambia l'ordine, torno indietro
            if(counterr[adj[nodo][vicino]] % 2 != (counter+1) % 2) {
                torno_indietro(adj[nodo][vicino], counter+1, counterr);
                ordine.push_back(nodo);
                return 1;
            }
            continue;
        }

        // non ancora visitato
        res = dfs(adj[nodo][vicino], counter+1, counterr);
        // trovato il torna indietro
        if(res==1) {
            ordine.push_back(nodo);
            return 1;
        }
    }

    return 0;
}

int main() {
//  uncomment the following lines if you want to read/write from files
    // ifstream cin("input.txt");
    // ofstream cout("output.txt");

    cin >> N >> M;
    vector<int> counterr(N+1, -1);
    int counter = 0;    // pari == BLEAH; dispari == SLURP
    int tmp1, tmp2;
    for (int i=0; i<M; i++) {
        cin >> tmp1 >> tmp2;
        adj[tmp1].push_back(tmp2);
        adj[tmp2].push_back(tmp1);
    }
        
    // insert your code here
    counterr[0] = 0;
    dfs(0, counter, counterr);

    cout << ordine.size()-1 << endl; // print the result
    for(int i=0; i < ordine.size(); i++) cout << ordine[i] << " ";
    return 0;
}