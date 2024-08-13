#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define pi pair<int, int>
#define vp vector<pi>
#define ll long long int
#define omap map<int, int>
#define umap unordered_map<int, int>

int sim(int p, vp &scambi, vi &guess, int n) {
    int res=0;
    for(int i=0; i<n; i++) {
        if(p==guess[i]) res++;
        if(p==scambi[i].first) p=scambi[i].second;
        else if(p==scambi[i].second) p=scambi[i].first;
    }
    return res;
}

int main() {
    if (fopen("shell.in", "r")) {
        freopen("shell.in", "r", stdin);
		freopen("shell.out", "w", stdout);
    }

    // cin.tie(nullptr);ios::sync_with_stdio(false);
    // ifstream cin("shell.in");
    // ifstream cout("shell.out");

    //Remember to use \n<<flush

    int n;
    cin >> n;
    vp scambi;
    vi guess;
    for(int i=0; i<n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        scambi.push_back({a, b});
        guess.push_back(c);
    }

    // sim - parte da 1
    int res = max(sim(1, scambi, guess, n), max(sim(2, scambi, guess, n), sim(3, scambi, guess, n)));
    cout << res << endl;
    return 0;
}