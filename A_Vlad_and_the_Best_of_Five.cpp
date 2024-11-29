#include <bits/stdc++.h> 

using namespace std;

#define vi vector<int>
#define pi pair<int, int>
#define vp vector<pi>
#define ll long long int
#define omap map<int, int>
#define umap unordered_map<int, int>

int main() {
    int n;
    cin >> n;
    for(int i=0; i<n; i++) {
        int a=0, b=0;
        for(int j=0; j<5; j++) {
            char c;
            cin >> c;
            if(c=='A') a++;
            else b++;
        }
        if(a>b) cout << 'A' << endl;
        else cout << 'B' << endl;
    }

    return 0;
}