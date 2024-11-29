#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> ad;
vector<int> timee;
vector<int> tpsorted;
vector<int> entering;
vector<int> exiting;
vector<bool> visited;
int conta;

int N, M;



void dfs(int nd) {
 cout << nd << endl;
 if(visited[nd]) {
  return;
 }
 visited[nd] = true;
 
 for(int u : ad[nd]) {
  if(!visited[u]) {
   dfs(u);
  }
 }
 
 tpsorted[nd] = N - conta - 1;
 conta++;
}



int toposort() {
 vector<int> start;
 for(int i = 0; i < N; i++) {
  if(entering[i] == 0) {
   start.push_back(i);
  }
 }
 
 for(int i : start) dfs(i);

 vector<pair<int, int>> ordine;
 for(int j=0; j<N; j++) {
    ordine.push_back({timee[i], i});
 }
 sort(ordine.begin(), ordine.end());
 vector<int> done(N);

 for(int i=0; i<N-1; i++) {
    if(ordine[i].first != ordine[i+1].first) {
        int flag = 0;
        for(int u : ad[ordine[i].second]) {
            if(!done[u]) {
                flag++;
            }
        }

        if(!flag) {
            done[ordine[i].second] = true;
        } else {
            if(i >= ordine[i].first) {

            }
        }
    }
 }
 
 for(int i : tpsorted) cout << i << " ";
 cout << endl;
}



int solve() {
 cin >> N >> M;
 timee.resize(N);
 ad.resize(N);
 entering.resize(N, 0);
 exiting.resize(N, 0);
 visited.resize(N, 0);
 tpsorted.resize(N, 0);
 conta = 0;
 for(int i = 0; i < N; i++) {
  cin >> timee[i];
 }
 
 for(int i = 0; i < M; i++) {
  int a, b;
  cin >> a >> b;
  a--;
  b--;
  ad[a].push_back(b);
  exiting[a]++;
  entering[b]++;
 }
 
 toposort();
 
 
 
// cout << ris;
}



int main() {
 int T;
 cin >> T;
 for(int i = 0; i < T; i++) {
  solve();
 }
}