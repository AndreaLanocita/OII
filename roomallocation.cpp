#include <bits/stdc++.h> 

using namespace std;

#define vi vector<int>
#define ll long long int
#define pi pair<ll, pair<ll, int>>
#define vp vector<pi>
#define omap map<int, int>
#define umap unordered_map<int, int>

int main() {
    int N;
    cin >> N;
    vp v(N);
    for(int i=0; i<N; i++) {
        ll a, b;
        cin >> a >> b;
        v[i] = {a, {b, i}};
    }
    sort(v.begin(), v.end());
    int counter = 0; int maxx = 0; vi alloggi(N);
    priority_queue<pair<ll, int>> partenze; // partenza, stanza
    priority_queue<int> stanze; // stanze libere
    for(int i=1; i<=N; i++) stanze.push(-i);

    for(int i=0; i<N; i++) {
        while(counter != 0) {
            if((-partenze.top().first) >= v[i].first) break;
            stanze.push(-partenze.top().second);
            partenze.pop(); counter--;
        }
        partenze.push({-v[i].second.first, -stanze.top()});
        alloggi[v[i].second.second] = -stanze.top();
        stanze.pop();
        counter++;

        if(counter > maxx) maxx = counter;
    }

    cout << maxx << endl;
    for(int i=0; i<N; i++) cout << alloggi[i] << " ";
    return 0;
}