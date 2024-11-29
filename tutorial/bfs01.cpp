int bfs01(vp adj[]) {
    int d[N];
    for(int i=0; i<N; i++) d[i] = INF;
    d[0] = 0;
    deque<int> dq; // 0 all'inizio, 1 alla fine
    dq.push_front(0);
    while(!dq.empty()) {
        int v = dq.front();
        dq.pop_front();
        for(pair<int, int> e: adj[v]) {
            int u = e.first;
            int w = e.second;
            if(d[v]+w<d[u]) {
                d[u]=d[w]+w;
                if(w==1) dq.push_back(u);
                else dq.push_front(u);
            }
        }
    }
    return d[N-1]
}