#include <bits/stdc++.h> 

using namespace std;

#define vi vector<int>
#define pi pair<int, int>
#define vp vector<pi>
#define ll long long int
#define omap map<int, int>
#define umap unordered_map<int, int>

int solve(int n, string S) {
    int inizio; int fine=0;
    for(int i=0; i<n; i++) {
        if(S[i]=='B') {
            inizio=i;
            break;
        }
    }

    for(int i=0; i<n; i++) {
        if(S[i]=='B') {
            fine = i;
        }
    }
    return fine-inizio;
}

int main() {
    int t;
    cin >> t;
    for(int i=0; i<t; i++) {
        int n;
        cin >> n;
        string S;
        cin >> S;
        cout << solve(n, S)+1 << endl;
    }
    
    return 0;
}