#include <bits/stdc++.h> 

using namespace std;

#define vi vector<int>
#define pi pair<int, int>
#define vp vector<pi>
#define ll long long int
#define omap map<int, int>
#define umap unordered_map<int, int>

int solve(int n, int arr[]) {
    int somma = 0;
    for(int i=0; i<n; i++) somma+=arr[i];
    int media = somma/n;

    for(int i=0; i<n; i++) {
        if(arr[i]<media) return 0;
        else if(i!=n-1) arr[i+1] += arr[i]-media;
    }
    if(arr[n-1] == media) return 1;
    return 0;
}

int main() {
    int t;
    cin >> t;
    for(int i=0; i<t; i++) {
        int n; cin >> n;
        int arr[n];
        for(int j=0; j<n; j++) cin >> arr[j];
        if(solve(n, arr)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}