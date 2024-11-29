#include <bits/stdc++.h> 

using namespace std;

#define vi vector<int>
#define pi pair<int, int>
#define vp vector<pi>
#define ll long long int
#define omap map<int, int>
#define umap unordered_map<int, int>

int main() {
    int t;
    cin >> t;
    for(int i=0; i<t; i++) {
        int n;
        cin >> n;
        vector<char> s(3);
        if(n<=28) {
            s[0] = 'a'; s[1] = 'a'; s[2] = 'a'+n-2-1;
        } 
        else if(n<=53) {
            s[0] = 'a'; s[2] = 'z'; s[1] = 'a'+n-27-1;
        }
        else {
            s[0] = 'a' + n -52-1; s[1] = 'z'; s[2] = 'z';
        }
        cout << s[0] << s[1] << s[2] << endl;
    }
    return 0;
}