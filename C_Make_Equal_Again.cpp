#include <bits/stdc++.h> 

using namespace std;

#define vi vector<int>
#define pi pair<int, int>
#define vp vector<pi>
#define ll long long int
#define omap map<int, int>
#define umap unordered_map<int, int>

int solve(int n, int arr[]) {
    int togliere = arr[0];
    int i;
    for(i=0; i<n; i++) if(arr[i]!=togliere) break;
    if(i==n) return 0;

    if(arr[0] == arr[n-1]) {
        i=0;
        int j=n-1;
        int togliere = arr[0];
        while(i<j) {
            if(arr[i]==togliere) i++;
            if(i<j && arr[j]==togliere) j--;
            if(arr[i] != togliere && arr[j] != togliere) break;
        }
        return (n-i-(n-j-1));
    }
    int tolti_dx = 0;
    int tolti_sx = 0;
    togliere = arr[0];
    for(i=0; i<n; i++) if(arr[i] != togliere) break;
    tolti_dx = i;

    int j; togliere = arr[n-1];
    for(j=n-1; j>=0; j--) if(arr[j] != togliere) break;
    tolti_sx = n-j-1;
    return n-max(tolti_dx, tolti_sx);
}

int main() {
    int t;
    cin >> t;
    for(int i=0; i<t; i++) {
        int n;
        cin >> n;
        int arr[n];
        for(int j=0; j<n; j++) cin >> arr[j];
        cout << solve(n, arr) << endl;
    }
    return 0;
}