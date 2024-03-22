/*
 * This template is valid both in C and in C++,
 * so you can expand it with code from both languages.
 * NOTE: it is recommended to use this even if you don't
 * understand the following code.
 */

#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define popb pop_back
#define vi vector<int>
#define pi pair<int, int>
#define vp vector<pi>
#define ll long long int
#define pl pair<ll, ll>
#define vl vector<ll>
#define vpl vector<pl>
#define omap map<int, int>
#define umap unordered_map<int, int>

// constraints
#define MAXN 100000

// input data
ll N, D, i;
ll L[MAXN], P[MAXN], S[MAXN], T[MAXN];

struct tri {
    ll arrivo, start, period;
};

int main() {
//  uncomment the following lines if you want to read/write from files
//    freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    assert(2 == scanf("%d %d", &N, &D));
    for(i=0; i<N; i++)
        assert(4 == scanf("%d %d %d %d", &L[i], &P[i], &S[i], &T[i]));

    vector<tri> adj[N+1];
    for(int i=0; i<N+1; i++) 
        for(int j=i+1; j<N; j++) {
            if(P[i] -(j-i)*D >= L[j]) adj[i].pb({j, S[i], T[i]});
            else break;
        }
            
    adj[N-1].pb({N, S[N-1], T[N-1]});
    
    priority_queue<pair<ll, int>> pq; // metto distanze negative (t1), arrivo
    int visitato[N+1] = { }; ll distanze[N+1];

    for(int i=0; i<N+1; i++) distanze[i] = LLONG_MAX; int n = 0;
    distanze[n] = 0; 
    pq.push({0, n});
    while(!pq.empty()) {
        n = pq.top().second;
        ll d = -pq.top().first;
        pq.pop();
        if(visitato[n] == 1 || distanze[n] != d) continue;
        
        
        if(n==N) break;   // ho finito
        visitato[n] = 1;

        // controllo vicini
        for(tri vicino: adj[n]) {
            // ho già visitato il nodo
            if(visitato[vicino.arrivo]==1) continue;

            // posso prendere il nodo e migliora il risultato
            if(vicino.start > distanze[n]) {
                if(vicino.start < distanze[vicino.arrivo]) {
                    distanze[vicino.arrivo] = vicino.start;
                    pq.push({-distanze[vicino.arrivo], vicino.arrivo});
                }
            }

            else {
                if(((distanze[n]-vicino.start)/vicino.period + 1) * vicino.period  + vicino.start < distanze[vicino.arrivo]) {
                    distanze[vicino.arrivo] = ((distanze[n]-vicino.start)/vicino.period + 1) * vicino.period  + vicino.start;
                    pq.push({-distanze[vicino.arrivo], vicino.arrivo});
                } 
            }
            
        }
    }
    
    if(distanze[N] == LLONG_MAX) cout << -1;
    else printf("%d\n", distanze[N]); // print the result
    return 0;
}
