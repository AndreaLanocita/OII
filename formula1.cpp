#include <bits/stdc++.h>

using namespace std;

struct car {
    int a;
    int b;
    int c;

    int numero;
};

long long t;

bool func(car a, car b) {
    long long s1 = a.a*(t*t) + a.b*t + a.c;
    long long s2 = b.a*(t*t) + b.b*t + b.c;

    if(s1==s2) return a.numero < b.numero;
    return s1 > s2;
} 

int main() {
    int N, Q;
    
    cin >> N;
    vector<car> macchine(N);

    for(int i=0; i<N; i++) {
        cin >> macchine[i].a >> macchine[i].b >> macchine[i].c;
        macchine[i].numero = i+1;
    }

    cin >> Q;
    int p;

    for(int i=0; i<Q; i++) {
        cin >> p >> t;

        nth_element(macchine.begin(), macchine.begin() + (p - 1), macchine.end(), func);
        cout << macchine[p-1].numero << endl;
    }

    return 0;
}