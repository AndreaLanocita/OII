#include <bits/stdc++.h> 

using namespace std;

#define vi vector<int>
#define pi pair<int, int>
#define vp vector<pi>
#define ll long long int
#define omap map<int, int>
#define umap unordered_map<int, int>

ll res = 0;

void aggiungi(int n, char str[5]) {
    if(n==5) {
        int flag_flowing = -1;
        if(str[1]>str[0]) flag_flowing = 1;
        else flag_flowing = 0;
        
        for(int i=1; i<5; i++) {
            if(str[i]>str[i-1] && flag_flowing==0) {
                res += 1;
                break;
            } 
            if(str[i]<str[i-1] && flag_flowing==1) {
                res += 1;
                break;
            } 
        }
        return ;
    }

    if(n==0) {
        for(int i=0; i<26; i++) {
            str[n] = i+97;
            aggiungi(n+1, str);
        }
    }
    else {
        for(int i=0; i<26; i++) {
            str[n] = i+97;
            aggiungi(n+1, str);
        }
    }
}

int main() {
    char str[5];
    aggiungi(0, str);
    cout << res;
    return 0;
}