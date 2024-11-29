#include <bits/stdc++.h>
#ifdef Giulio
#include <bits/debug.h>
#else
#define dbg(...)
#endif

using namespace std;
using ll = long long;
using ld = long double;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
template <class T>
using V = vector<T>;

#define FOR(i, a, b) for (int i = a; i < (b); i++)
#define FORd(i, a, b) for (int i = (a); i >= b; i--)
#define feach(a, x) for (auto &a : x)

#define sz(x) (int)(x).size()
#define all(x) x.begin(), x.end()
#define pb push_back

const int MOD = 1000000007;
const char nl = '\n';

// 1 alto, 2 destra, 3 basso, 4 sinistra
// mossa: (inizio, delta_y, delta_x, fine)
// DA AGGIUNGERE IN INPUT:
// 96 -> Z
// A5 -> X
// C3 -> V

unordered_map<string, vector<vector<int>>> mosse_per_tile = {
    {"3",
     {{4, 0, 2, 2},
      {2, 0, -2, 4}}},
    {"5",
     {{3, -1, 1, 2},
      {2, 1, -1, 3}}},
    {"6",
     {{4, 1, 1, 3},
      {3, -1, -1, 4}}},
    {"7",
     {{3, -1, 1, 2},
      {2, 1, -1, 3},
      {4, 0, 2, 2},
      {2, 0, -2, 4},
      {4, 1, 1, 3},
      {3, -1, -1, 4}}},
    {"9",
     {{1, 1, 1, 2},
      {2, -1, -1, 1}}},
    {"Z",
     {{1, 1, 1, 2},
      {2, -1, -1, 1},
      {4, 1, 1, 3},
      {3, -1, -1, 4}}},
    {"A",
     {{4, -1, 1, 1},
      {1, 1, -1, 4}}},
    {"X",
     {{4, -1, 1, 1},
      {1, 1, -1, 4},
      {3, -1, 1, 2},
      {2, 1, -1, 3}}},
    {"B",
     {{4, 0, 2, 2},
      {2, 0, -2, 4},
      {4, -1, 1, 1},
      {1, 1, -1, 4},
      {1, 1, 1, 2},
      {2, -1, -1, 1}}},
    {"C",
     {{1, 2, 0, 3},
      {3, -2, 0, 1}}},
    {"V",
     {{1, 2, 0, 3},
      {3, -2, 0, 1},
      {4, 0, 2, 2},
      {2, 0, -2, 4}}},
    {"D",
     {{1, 2, 0, 3},
      {3, -2, 0, 1},
      {1, 1, 1, 2},
      {2, -1, -1, 1},
      {3, -1, 1, 2},
      {2, 1, -1, 3}}},
    {"E",
     {{1, 2, 0, 3},
      {3, -2, 0, 1},
      {4, -1, 1, 1},
      {1, 1, -1, 4},
      {4, 1, 1, 3},
      {3, -1, -1, 4}}},
    {"F",
     {{4, -1, 1, 1},
      {1, 1, -1, 4},
      {4, 1, 1, 3},
      {3, -1, -1, 4},
      {1, 2, 0, 3},
      {3, -2, 0, 1},
      {1, 1, 1, 2},
      {2, -1, -1, 1},
      {3, -1, 1, 2},
      {2, 1, -1, 3},
      {4, 0, 2, 2},
      {2, 0, -2, 4}}}
};
int dist(pair<int, int> a, pair<int, int> b)
{
    return abs(a.first - b.first) + abs(a.second - b.second);
}
class Tile {
public:
    string type;
    int cost;
    unsigned int available;
    Tile(string typee, int costt, unsigned int availablee): type(typee), cost(costt), available(availablee) {};
};

bool compatibile(int versoArrivo, string tileCorrente, string tilePrecedente)
{
    feach(mossa, mosse_per_tile[tileCorrente])
    {
        if (mossa[0] == versoArrivo)
            return 1;
    }
    return 0;
}

bool avvicina(pi inizio, pi fine, string tile)
{

    feach(mossa, mosse_per_tile[tile])
    {
        if (dist({inizio.first + mossa[1], inizio.second + mossa[2]}, fine) < dist(inizio, fine))
            return 1;
    }
    return 0;
}

/* ---------- Code here ---------- */


int collega(pair<int, int> g1, pair<int, int> g2, vector<Tile> &tilesOrdinato, unordered_map<string, Tile> &tilesDisordinato)
{
    string tilePrecedente = "";
    int numeroTile = 0;
    pair<int, int> corrente = g1;

    int costo=0;
    vector<Tile> ordineTiles;

    while (corrente.first != g2.first || corrente.second != g2.second)
    {
        // controllo che non siano finiti
        if (tilesOrdinato[numeroTile].available == 0)
        {
            numeroTile++;
            continue;
        }

        // controllo che sia compatibil
        feach(mossa, mosse_per_tile[tilePrecedente])
        {
            if (compatibile(mossa[3], tilesOrdinato[numeroTile].type, tilePrecedente) || tilePrecedente=="")
            {
                if (avvicina(corrente, g2, tilesDisordinato[tilePrecedente].type))
                {
                    tilesDisordinato[tilesOrdinato[numeroTile].type].available--;
                    tilePrecedente = tilesDisordinato[tilePrecedente].type;
                    corrente = {corrente.first + mossa[1], corrente.second + mossa[2]};
                    costo += tilesOrdinato[numeroTile].cost;
                    ordineTiles.push_back(tilesDisordinato[tilePrecedente]);
                    break;
                }
            }
        }
    }
}

void solve()
{
    int w, h, g, s, t;
    cin >> w >> h >> g >> s >> t;
    vector<pair<int, int>> golden(g);
    vector<vi> silver(s);
    vector<Tile> tiles;

    for (int i = 0; i < g; i++)
    {
        cin >> golden[i].first >> golden[i].second;
    }
    for (int i = 0; i < s; i++)
    {
        int x, y, cost;
        cin >> x >> y >> cost;
        silver[i] = {x, y, cost};
    }

    for (int i = 0; i < t; i++) {
        string type;
        int cost;
        unsigned int available;
        cin >> type >> cost >> available;
        tiles.push_back(Tile(type, cost, available));
    }

    sort(tiles.begin(), tiles.end(), [](Tile a, Tile b) {
        if (a.cost == b.cost)
            return a.available > b.available;
        return a.cost < b.cost;
    });

    vector<vi> distanze(g, vi(g, 0));
    for (int i = 0; i < g; i++)
    {
        for (int j = 0; j < g; j++)
        {
            distanze[i][j] = dist(golden[i], golden[j]);
            distanze[j][i] = distanze[i][j];
        }
        sort(distanze[i].begin(), distanze[i].end());
    }
}

/* ---------- Main here ---------- */

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}