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
#define pq priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>>


int jump(int H, int W, char** G) {
    // bfs con una pair per indicare la posizione
    // + controllo se posso andare in un posto
    pi n; 
    queue<pi> q; q.push({0, 0});
    int visitato[H][W]; int distanze[H][W];
    for(int i=0; i<H; i++) for(int j=0; j<W; j++) visitato[i][j] = 0;
    visitato[0][0] = 1; distanze[0][0] = 0;


    while(!q.empty()) {
        n = q.front();
        q.pop();
        if(n.first == H-1 && n.second == W-1) break;

        // diagonali miste
        if(n.first + 1 < H && n.second - 1 >= 0 && visitato[n.first+1][n.second-1] == 0 && G[n.first+1][n.second-1] == '.') {
            visitato[n.first + 1][n.second-1] = 1;
            distanze[n.first + 1][n.second-1] = distanze[n.first][n.second]+1;
            q.push({n.first+1, n.second-1});
        }

        if(n.first - 1 >= 0 && n.second + 1 < W && visitato[n.first-1][n.second+1] == 0 && G[n.first-1][n.second+1] == '.') {
            visitato[n.first - 1][n.second+1] = 1;
            distanze[n.first - 1][n.second+1] = distanze[n.first][n.second]+1;
            q.push({n.first-1, n.second+1});
        }

        // controllo le mosse possibili
        // diagonale
        if(n.first + 1 < H && n.second + 1 < W && visitato[n.first+1][n.second+1] == 0 && G[n.first+1][n.second+1] == '.') {
            visitato[n.first + 1][n.second+1] = 1;
            distanze[n.first + 1][n.second+1] = distanze[n.first][n.second]+1;
            q.push({n.first+1, n.second+1});
        }

        // diagonale indietro
        if(n.first -1 > 0 && n.second -1 >0 && visitato[n.first-1][n.second-1] == 0 && G[n.first-1][n.second-1] == '.') {
            distanze[n.first-1][n.second-1] = distanze[n.first][n.second]+1;
            visitato[n.first -1][n.second-1] = 1;
            q.push({n.first-1, n.second-1});
        }

        // sotto di uno
        if(n.first + 1 < H && visitato[n.first+1][n.second] == 0 && G[n.first+1][n.second] == '.') {
            visitato[n.first + 1][n.second] = 1;
            distanze[n.first + 1][n.second] = distanze[n.first][n.second]+1;
            q.push({n.first+1, n.second});
        }

        // sopra di uno
        if(n.first -1 >= 0 && visitato[n.first-1][n.second] == 0 && G[n.first-1][n.second] == '.') {
            visitato[n.first -1][n.second] = 1;
            distanze[n.first-1][n.second] = distanze[n.first][n.second]+1;
            q.push({n.first-1, n.second});
        }

        // destra di uno
        if(n.second + 1 < W && visitato[n.first][n.second+1] == 0 && G[n.first][n.second+1] == '.') {
            visitato[n.first][n.second+1] = 1;
            distanze[n.first][n.second+1] = distanze[n.first][n.second]+1;
            q.push({n.first, n.second+1});
        }

        // sinistra di uno
        if(n.second-1 >= 0 && visitato[n.first][n.second-1] == 0 && G[n.first][n.second-1] == '.') {
            visitato[n.first][n.second-1] = 1;
            distanze[n.first][n.second-1] = distanze[n.first][n.second]+1;
            q.push({n.first, n.second-1});
        }

        // sotto di due
        if(n.first +2 < H && visitato[n.first+2][n.second] == 0 && G[n.first+2][n.second] == '.') {
            visitato[n.first +2][n.second] = 1;
            distanze[n.first+2][n.second] = distanze[n.first][n.second]+1;
            q.push({n.first+2, n.second});
        }

        // sopra di due
        if(n.first -2 >=0 && visitato[n.first-2][n.second] == 0 && G[n.first-2][n.second] == '.') {
            visitato[n.first -2][n.second] = 2;
            distanze[n.first-2][n.second] = distanze[n.first][n.second]+1;
            q.push({n.first-2, n.second});
        }

        // destra di due
        if(n.second +2 < W && visitato[n.first][n.second+2] == 0 && G[n.first][n.second+2] == '.') {
            visitato[n.first][n.second+2] = 2;
            distanze[n.first][n.second+2] = distanze[n.first][n.second]+1;
            q.push({n.first, n.second+2});
        }

        // sinistra di due
        if(n.second-2 >= 0 && visitato[n.first][n.second-2] == 0 && G[n.first][n.second-2] == '.') {
            visitato[n.first][n.second-2] = 2;
            distanze[n.first][n.second-2] = distanze[n.first][n.second]+1;
            q.push({n.first, n.second-2});
        }
    }


    return distanze[H-1][W-1];
}


int main() {
    FILE *fr, *fw;
    int H, W, i;
    char** G;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(2 == fscanf(fr, "%d%d", &H, &W));
    G = (char**) malloc(H * sizeof(char*));
    for(i=0; i<H; i++) {
        G[i] = (char*) malloc(W * sizeof(char*));
        assert(1 == fscanf(fr, "%s", G[i]));
    }

    fprintf(fw, "%d\n", jump(H, W, G));
    fclose(fr);
    fclose(fw);
    return 0;
}
