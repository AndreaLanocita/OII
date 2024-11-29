/*
 * This template is valid both in C and in C++,
 * so you can expand it with code from both languages.
 */

#include <bits/stdc++.h>

using namespace std;

#include <bits/stdc++.h> 

using namespace std;

#define ll long long
#define pq priority_queue<pair<ll, pair<ll, int>>, vector<pair<ll, pair<ll, int>>>, greater<pair<ll, pair<ll, int>>>>

// constraints
#define MAXN 50000
#define MAXM 100000
#define INF LLONG_MAX

// input data
int N, M;
int source, destination;

struct archi {
    long long t0, t1, arrival;
    archi(int a, int b, int c): t0(a), t1(b), arrival(c) {};
};

int main() {
//  uncomment the following lines if you want to read/write from files
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    assert(1 == scanf("%d", &N));
    assert(2 == scanf("%d%d", &source, &destination));
    assert(1 == scanf("%d", &M));

    vector<archi> adj[N];
    for (int i=0; i<M; i++) {
        int city1, time1, city2, time2;
        assert(4 == scanf("%d%d%d%d", &city1, &time1, &city2, &time2));
        adj[city1].push_back(archi(time1, time2, city2));
    }

    long long distanze[N]; int visitato[N] = {};
    for(int i=0; i<N; i++) distanze[i] = INF;
    pq p;
    p.push({0, {0, 0}});
    pair<ll, int> n = {0, source};

    for(int i=0; i<N; i++) {
        while(!p.empty()) {
            n = p.top().second;
            if(visitato[n.second]==0 || distanze[n.second] == p.top().first) break;
            p.pop();
        }
        if(p.empty()) break;
        p.pop();

        visitato[n.second] = 1;
        for(archi vicino: adj[n.second]) {
            if(visitato[vicino.arrival] || vicino.t0<n.first) continue;
            if(distanze[vicino.arrival] > vicino.t1) {
                distanze[vicino.arrival] = vicino.t1;
                p.push({distanze[vicino.arrival], {vicino.t1, vicino.arrival}});
            }
        }
    }
    
    if(distanze[destination]==INF) cout << "IMPOSSIBLE" << endl;
    else cout << distanze[destination] << endl;
    return 0;
}
