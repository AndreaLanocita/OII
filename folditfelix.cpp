#include <bits/stdc++.h> 

using namespace std;


#define pi pair<int, int>
#define vp vector<pi>
#define ll long long int
#define omap map<int, int>
#define umap unordered_map<int, int>
#define vi vector<ll>

#define MAXN 200000

int main() {
    int N; 
    cin >> N;
    vi L(N), p_sum(N);
    ll res[N];
    

    for(int i=0; i<N; i++) 
        cin >> L[i];
    
    int summ = 0;
    for(int i=0; i<N; i++) {
        p_sum[i] = L[i] + summ;
        summ += L[i];
        res[i] = p_sum[i];
    }

    for(int i=0; i<N-1; i++) {
        int j = lower_bound(p_sum.begin(), p_sum.end(), 2*res[i]+(p_sum[i]-res[i]))-p_sum.begin();
        if(j>N-1) res[N-1] = min(res[N-1], res[i]);
        else res[j] = min(res[j], p_sum[j]-res[i]-(p_sum[i]-res[i]));
    }

    cout << res[N-1];
    return 0;
}