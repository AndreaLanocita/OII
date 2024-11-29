/*
 * NOTE: it is recommended to use this even if you don't
 * understand the following code.
 */

#include <bits/stdc++.h>

// constraints
#define MAXN 9000
#define MAXM 100

using namespace std;

// input data
short int N, M;
vector<string> S;
<<<<<<< HEAD

=======
>>>>>>> e36d179ced5161c8c6ee992a38584e6ba5e578cb
vector<short int> link;
vector<short int> sizee;

void init(short int N) {
    link.resize(N);
    sizee.resize(N);
    for(short int i=0; i<N; i++) {
        sizee[i] = 0;
        link[i] = i;
    }
}
<<<<<<< HEAD

=======
>>>>>>> e36d179ced5161c8c6ee992a38584e6ba5e578cb
short int find(short int a) {
    while(link[a]!=a) a=link[a];
    return a;
}
<<<<<<< HEAD

=======
>>>>>>> e36d179ced5161c8c6ee992a38584e6ba5e578cb
void unionn(short int a, short int b) {
    a = find(a);
    b= find(b);
    if(a==b) return;

    if(sizee[a] < sizee[b]) {
        link[a] = b;
        sizee[b] += sizee[a];
    } else {
        link[b] = a;
        sizee[a] += sizee[b];
    }
}
<<<<<<< HEAD

int main() {
//  uncomment the following lines if you want to read/write from files
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    assert(cin >> N >> M);
    S.resize(N);
    for(short int i=0; i<N; i++)
        assert(cin >> S[i]);

    short int tmp;
    vector<pair<short int, pair<short int, short int>>> lista;
    for(short int i=0; i<N; i++) {
        for(short int j=i+1; j<N; j++) {
            tmp = 0;
            for(short int k=0; k<M; k++) if(S[i][k] != S[j][k]) tmp++;
            lista.push_back({tmp, {i, j}});
        }
    }

=======
int main() {
>>>>>>> e36d179ced5161c8c6ee992a38584e6ba5e578cb
    sort(lista.begin(), lista.end());
    int prezzo = 0;
    init(N);
    for(pair<short int, pair<short int, short int>> arco: lista) {
        if(find(arco.second.first) == find(arco.second.second)) continue;
        unionn(arco.second.first, arco.second.second);
        prezzo += (int) arco.first;
    }

<<<<<<< HEAD
    cout << prezzo+M << "\n"; // print the result
=======
    cout << prezzo+M << "\n"; 
>>>>>>> e36d179ced5161c8c6ee992a38584e6ba5e578cb
    return 0;
}
