#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define popb pop_back
#define vi vector<int>
#define pi pair<int, int>
#define vp vector<pi>
#define ll long long int
#define pl pair<ll, ll>
#define vl vector<ll>
#define vpl vector<pl>
#define omap map<int, int>
#define umap unordered_map<int, int>
#define pq priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>>

bool check(int N, vi &Z) {
    int flag = 0;
    int ncrescente=0; // sembra possa avere al massimo una sequenza crescente
    for(int i=1; i<N; i++) {
        if(flag==2) flag=0;
        while(Z[i]==Z[i-1]) {
            i++;
            flag = 1;
            
        }
        while(Z[i] > Z[i-1]) {
            if(flag==0) ncrescente++;
            i++;
            flag = 2;
        }
        if(ncrescente==2) return 0;
    }
    return 1;
}

bool heights(int N, vector<int> Z, vector<int> &H) {
    return check(N-1, Z);
}

int main() {
    // decommenta queste due righe per leggere da / scrivere su file
    // uncomment these two lines to read from / write to file
    // assert(freopen("input.txt", "r", stdin));
    // assert(freopen("output.txt", "w", stdout));

    int N;
    cin >> N;

    vector<int> Z(N - 1), H(N);
    for (int &z: Z) {
        cin >> z;
    }

    bool found = heights(N, Z, H);

    if (!found) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        for (int h: H) {
            cout << h << " ";
        }
        cout << "\n";
    }
}