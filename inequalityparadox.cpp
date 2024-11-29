#include <bits/stdc++.h> 

using namespace std;

#define vi vector<int>
#define pi pair<int, int>
#define vp vector<pi>
#define ll long long int
#define omap map<int, int>
#define umap unordered_map<int, int>

// int M[26][26] x > y --> M[x][y] = 1;

int cycle(int n, vi adj[26]) {
    int k;
    int visitato[26] = {};
    stack<int> s;
    s.push(n);

    while(!s.empty()) {
        k = s.top();
        s.pop();
        visitato[k] = 1;

        for(int vicino: adj[k]) {
            if(visitato[vicino] == 1 && n == vicino) return 1;
            if(visitato[vicino] == 1) continue;
            s.push(vicino);
        }

    }

    return 0;
}

int main() {
    int N;
    cin >> N;
    vector<char> S;
    S.resize(3);
    vector<int> adj[26];

    for(int i=0; i<N; i++) {
        for(int j=0; j<3; j++)
            cin >> S[j];

        int mag = S[0]-97; // controllare ascii
        int minn = S[2]-97; 
        for(int j=0; j<3; j++) if(S[j]=='<') swap(mag, minn);

        adj[mag].push_back(minn);
    }

    // cycle det
    for(int i=0; i<26; i++) {
        if(cycle(i, adj) == 1) {
            cout << ":(";
            return 0;
        }
    }
    cout << ":)";
    return 0;
}