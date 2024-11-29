#include <bits/stdc++.h> 

using namespace std;

#define vi vector<int>
#define pi pair<int, int>
#define vp vector<pi>
#define ll long long int
#define omap map<int, int>
#define umap unordered_map<int, int>

int main() {
    cin.tie(0); ios::sync_with_stdio(false);
    int N, K;
    cin >> N >> K;
    vector<pair<int, int>> v(N);
    for(int i=0; i<N; i++) {
        cin >> v[i].first;
        v[i].second = i;
    }
        

    sort(v.begin(), v.end());
    int i=0, j=N-1;
    while(i<j) {    // non possono essere uguali
        if(v[i].first + v[j].first == K) {
            cout << v[i].second+1 << " " << v[j].second+1;
            return 0;
        }
        if(v[i].first + v[j].first > K) {
            j--;
            continue;
        }
        else i++;
    }
    cout << "IMPOSSIBLE";
    return 0;
}