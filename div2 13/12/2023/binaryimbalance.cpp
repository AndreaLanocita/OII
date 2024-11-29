#include <bits/stdc++.h> 

using namespace std;

#define vi vector<int>
#define pi pair<int, int>
#define vp vector<pi>
#define ll long long int
#define omap map<int, int>
#define umap unordered_map<int, int>

int main() {
    int t, flag;
    cin >> t;
    for(int i=0; i<t; i++) {
        int N; string S;
        cin >> N;
        cin >> S;
        flag = 0;
        for(int j=0; j<N; j++) {
            if(S[j] == '0') {
                flag = 1;
                cout << "YES" << endl;
                break;
            }
        }
        if(flag == 0) cout << "NO" << endl;
    }
    return 0;
}