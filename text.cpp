// NOTE: it is recommended to use this even if you don't understand the following code.

#include <bits/stdc++.h>

using namespace std;

// input data
int N, K;
vector<string> S;

int main() {
//  uncomment the following lines if you want to read/write from files
//  ifstream cin("input.txt");
//  ofstream cout("output.txt");
    ios::sync_with_stdio(false);
    cin >> N >> K;
    S.resize(N);
    for (int i = 0; i < N; i++)
        cin >> S[i];

    // insert your code here
    int lettere[26] = { };
    int sol[N];

    for(int i=0; i<N; i++) sol[i] = 0;

    for(int j=0; j<K; j++) {
        for(int i=0; i<N; i++) {
            lettere[S[i][j]-'a']++;
        }
        for(int i=0; i<N; i++) sol[i] += (N-lettere[S[i][j]-'a']);

        for(int i=0; i<26; i++){
            lettere[i]=0;
        }
    }

    

    int minore = INT_MAX;
    int index_minore = INT_MAX;
    for(int i=0; i<N; i++) {
        if(minore > sol[i]) {
            index_minore = i;
            minore = sol[i];
        }
    }


    cout << index_minore << endl; // print the result
    return 0;
}
