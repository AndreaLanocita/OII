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
short int find(short int a) {
    while(link[a]!=a) a=link[a];
    return a;
}
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
int main() {
    sort(lista.begin(), lista.end());
    int prezzo = 0;
    init(N);
    for(pair<short int, pair<short int, short int>> arco: lista) {
        if(find(arco.second.first) == find(arco.second.second)) continue;
        unionn(arco.second.first, arco.second.second);
        prezzo += (int) arco.first;
    }

    cout << prezzo+M << "\n"; 
    return 0;
}
