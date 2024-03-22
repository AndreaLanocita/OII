#include <bits/stdc++.h> 

using namespace std;

#define vi vector<int>
#define pi pair<int, int>
#define vp vector<pi>
#define ll long long int
#define omap map<int, int>
#define umap unordered_map<int, int>

int main() {
    int T, n;
    cin >> T;
    for(int i=0; i<T; i++) {
        cin >> n; 
        if(n%3 == 1 || n%3 == 2) cout << "First" << endl;
        else cout << "Second" << endl;
    }
    return 0;
}