#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, M, S, E, a, b, c;
    S=0;
    cin>>N>>M>>S>>E;
    int distanze[N];
    bool processed[N];
    vector<vector<pair<int, int>>> adj(N);
    for(int o=0; o<M; o++){
        cin>>a>>b>>c;
        adj[a].push_back({b, c});
    }
    for(int o=0; o<N; o++){
        distanze[o]=INT_MAX;
        processed[o]=0;
    }
    distanze[S]=0;
    processed[S]=0;
    priority_queue<pair<int, int>> q;
    q.push({0, S});
    while(q.size()){
        int ark=q.top().second;
        q.pop();
        if(!processed[ark]){
            processed[ark]=true;
            for(auto u : adj[ark]){
                int b=u.first, w=u.second;
                if(distanze[ark]+w<distanze[b]){
                    distanze[b]=distanze[ark]+w;
                    q.push({-distanze[b], b});
                }
            }
        }
    }
    cout<<distanze[E];
}