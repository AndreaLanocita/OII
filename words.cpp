/*
 * NOTE: it is recommended to use this even if you don't
 * understand the following code.
 */

#include <bits/stdc++.h>

using namespace std;
#define ll long long
const int MAXK = 26*26*26;

// input data
int N, L, K;
string trigram;

int main() {
//  uncomment the following lines if you want to read/write from files
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);
    int x, y;
    bool tri [26*26*26+1];
    vector<int> lista;
    for (int i=0; i<26*26*26+1; i++) tri[i] = false;
    cin >> N >> L >> K;
    for (int i=0; i<K; i++) {
        cin >> trigram;
        x = (int)(trigram[0]-'a')*26*26 + (int)(trigram[1]-'a')*26 + (int)(trigram[2]-'a');
        tri[x] = true;
        lista.push_back(x);
    }
    ll dp[MAXK][L];
    for (int i=0; i<MAXK; i++)  dp[i][L-3] = 1;
    for (int i=0; i<MAXK; i++){
        for (int pos=L-4; pos >= 0; pos--){
            dp[i][pos] = 0; 
            x = 26*(i%(26*26));
            for (int j=0; j<26; j++){
                if (tri[x+j]) dp[i][pos] += dp[x+j][pos+1];
            }
        }
    }
    cout << dp[26][L-4];
    cout << endl << dp[679][L-4];

    int i = 0, j = 0;
    N--;

    string ans = "";

    while(N > 0){
        while(N > 0){
            i++;
            N -= dp[i][j];
            if (!N) goto end;
        }
        if (!j) ans +=  
        j++;
        i = 0;

    }

    end:

    return 0;
}
