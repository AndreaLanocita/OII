#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define popb pop_back
#define vi vector<int>
#define pi pair<int, int>
#define vp vector<pi>
#define pl pair<int, int>
#define vl vector<int>
#define vpl vector<pl>
#define omap map<int, int>
#define umap unordered_map<int, int>
#define pq priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>

vi uf, h, arco;

struct tri{
  int a, b, costo;
  tri(int a, int b, int c) : a(a), b(b), costo(c) {};
};

bool func(tri a, tri b) {if(a.costo<b.costo) return true; return false;}

void make_set(int x) {uf[x] = x;h[x] = 0; arco[x] = 0;}
int find(int x) {
  if(uf[x] == x) return x;
  return uf[x] = find(uf[x]);
}
void unionn(int a, int b) {
  a = find(a); b = find(b);
  if(a == b) return ;
  if(h[a] < h[b]) {
    uf[a] = b;
  } else {
    uf[b] = a;
    if(h[a]==h[b]) h[b]++;
  }
  return ;
}

int alzati(int N, int M, int X[], int Y[]) {
  // [0, 4) pareti
  vector<tri> adj;
  int tmp, coord_x, coord_y, flag = 0, flag1= 0;
  for(int i=0; i<M; i++) {
    adj.pb(tri(0, i+4, X[i])); adj.pb(tri(1, i+4, N-Y[i]-1)); adj.pb(tri(2, i+4, N-X[i]-1)); adj.pb(tri(3, i+4, Y[i]));
    
    int diff_x, diff_y;
    for(int j=i+1; j<M; j++) {
      diff_x = abs(X[i]-X[j])-1; diff_y = abs(Y[i]-Y[j])-1;
      if(diff_x <= 0) diff_x=0; 
      if(diff_y <= 0) diff_y=0; 

      if(X[i] == X[j]) {
        tmp = diff_y/2;
        if(diff_y%2==1) tmp+=1;
      }
      else if(Y[i] == Y[j]) {
        tmp = diff_x/2;
        if(diff_x%2==1) tmp+=1;
      }
      else {
        tmp = diff_y/2;
        if(diff_y%2==1 || diff_x%2==1) tmp+=1;
        tmp += diff_x/2;
      }
      adj.pb(tri(i+4, j+4, tmp));
    }
  }

  arco.resize(adj.size());
  // union find
  uf.resize(adj.size()); h.resize(adj.size());
  for(int i=0; i<4; i++) {make_set(i);}
  for(int i=0; i<M; i++) {make_set(i+4);}
  sort(adj.begin(), adj.end(), func);

  for(int i=0; i<adj.size(); i++) {
    if(find(adj[i].a) != find(adj[i].b)) {
      unionn(adj[i].a, adj[i].b);
      arco[find(adj[i].a)] = max(arco[find(adj[i].a)], adj[i].costo);
    } 
    if(find(0) == find(2) || find(3) == find(1) || find(0) == find(3) || find(1) == find(2)) break;
  }

  if(find(0) == find(2) || find(1) == find(2)) return arco[find(2)]-1;
  if(find(3) == find(1) || find(0) == find(3)) return arco[find(3)]-1;
}

int main() {

  int N, M;

  assert(2==scanf("%d %d", &N, &M));

  int *X = (int*) malloc(M * sizeof(int));
  int *Y = (int*) malloc(M * sizeof(int));

  for(int i=0; i<M; i++)
    assert(2==scanf("%d %d", X+i, Y+i));

  printf("%d\n", alzati(N, M, X, Y));
  return 0;
}