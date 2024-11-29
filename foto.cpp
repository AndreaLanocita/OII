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
    int res = 0; int status; int i=1; int flag = 0;
    while(Z[i]==Z[i-1] && i<N) i++;
    if(i==N) return 1;

    if(Z[1]>Z[0]) {
        res++; status=1;
    }
    else status=0;

    for(; i<N; ) {
        if(Z[i]==Z[i-1]) {
            if((Z[i-2]<Z[i-1] && status==0) || (Z[i-2]>Z[i-1] && status==1)) res++;
            if(res==2) return 0;
        } 
        while(Z[i]==Z[i-1] && i<N) {
            i++;
            flag = 1;
        }
        if(flag==1) {
            // if(Z[i]<Z[i-1] && status==0) res++;
            // if(Z[i]>Z[i-1] && status==1) res++;
            // if(res>1) return 0;
            i++;
            flag=0;

            if(Z[i]>Z[i-1]) status=1;
            else status=0;
        }
        if(i==N) return 1;
        while(Z[i]<Z[i-1] && i<N) {
            if(status==1) {
                res++;
                if(res==2) return 0;
            }
            status=0;
            i++;
        }
        if(i==N) return 1;
        while(Z[i]>Z[i-1] && i<N) {
            if(status==0) {
                res++;
                if(res==2) return 0;
            }
            status=1;
            i++;
        }
    }
    return 1;
}

bool heights(int N, vector<int> Z, vector<int> &H) {
    for(int i=0; i<N; i++) H[i] = 1;
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