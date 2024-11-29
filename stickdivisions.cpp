#include <bits/stdc++.h> 

using namespace std;

#define pi pair<int, int>
#define vp vector<pi>
#define ll long long int
#define omap map<int, int>
#define umap unordered_map<int, int>
#define vi vector<ll>

int main() {
    ll L; int N;
    cin >> L >> N;
    if(N==1) {
        cout << 0;
        return 0;
    }

    priority_queue<ll> pq;
    for(int i=0; i<N; i++) {
        ll tmp;
        cin >> tmp;
        pq.push(-tmp);
    } 
    ll res = 0;
    for(int i=0; i<N-1; i++) {
        ll tmp = -pq.top(); pq.pop();
        tmp -= pq.top(); pq.pop();
        res += tmp;
        pq.push(-tmp);
    }
    cout << res;
    return 0;
}