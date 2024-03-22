#include <bits/stdc++.h> 

using namespace std;

#define vi vector<int>
#define pi pair<int, int>
#define vp vector<pi>
#define ll long long int
#define omap map<int, int>
#define umap unordered_map<int, int>

int main() {
    int N, specie = 0;
    map<string, int> pokedex;
    cin >> N;
    for(int i=0; i<N; i++) {
        string p;
        cin >> p;
        if(pokedex.count(p)==1) continue;
        pokedex[p] = 1;
        specie++;
    }
    cout << specie+1;
    return 0;
}