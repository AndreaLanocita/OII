int prim(vp adj[]) {
    int nodo = 1, n_raggiunti = 0, sol = 0;
    vector<pair<int, int>> S;   // archi scelti
    int visitato[N+1] = { };     // per ciascun nodo, raggiunto o no?
    // insieme di archi che portano a nodi raggiungibili
    priority_queue<pair<ll, pair<int, int>>, vector<pair<ll, pair<int, int>>>, greater<pair<ll, pair<int, int>>>> vicini;
    
    while(n_raggiunti<N) {  // quando visitiamo tutti i nodi abbiamo un mst
        visitato[nodo] = 1;

        // aggiungo alla pq nuovi archi usabili
        for(pair<int, ll> vicino: adj[nodo]) {
            // se non ho già raggiunto il nodo aggiungo arco a pq
            if(visitato[vicino.first] == 0) vicini.push({vicino.second, {nodo, vicino.first}});
        }

        // scelgo il nuovo arco da aggiungere
        pair<ll, pair<int, int>> arco;
        while(!vicini.empty()) {
            arco = vicini.top();
            // controllo se ho visitato il nodo, di sicuro lo visito
            // per primo con l'insieme di archi che risulta nella minore distanza
            if(visitato[arco.second.second] == 0) break;
            vicini.pop();
        }
        nodo = arco.second.second;
        if(vicini.empty()) break;
        vicini.pop();

        // salvo l'arco
        S.push_back(arco.second);
        sol += arco.first;
        n_raggiunti++;
    }
    
    return sol; // the tree is in S
}