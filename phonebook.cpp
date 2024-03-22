#include <bits/stdc++.h> 

using namespace std;

#define vi vector<int>
#define pi pair<int, int>
#define vp vector<pi>
#define ll long long int
#define omap map<int, int>
#define umap unordered_map<int, int>

int main() {
    ll N;
    cin >> N;
    ll res = 0, tmp;
    ll ten = 10e9;
    ll nine = 10e8;

    for(int i=0; i<N; i++) {
        cin >> tmp;
        if(tmp / ten == 39) res++;
        else if(tmp / nine == 39) res++; 
    }
    cout << res;
    return 0;
}