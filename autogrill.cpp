#include <bits/stdc++.h>

using namespace std;

#define ll long long int

set<ll> aperti;

void inizia() {
    return;
}

void apri(long long p) {
    aperti.insert(p);
    return;
}

void chiudi(long long p) {
    aperti.erase(p);
    return;
}

long long chiedi(long long p) {
    if(aperti.empty() == true) return -1;

    std::set<ll>::iterator itl, itu;
    itu = aperti.lower_bound(p);
    if(itu==aperti.begin()) return *itu;
    itl = (--aperti.lower_bound(p));
    
    if(itu==aperti.end()) return *itl;
    if(itl==aperti.end()) return *itu;

    if(abs(*itu-p) > abs(*itl-p)) return *itl;
    return *itu;
}

int main() {
    int Q;
    cin >> Q;

    inizia();

    for (int i = 0; i < Q; i++){
        long long p;
        char t;
        cin >> t >> p;
        if (t == 'a') apri(p);
        else if (t == 'c') chiudi(p);
        else cout << chiedi(p) << endl;
    }

    return 0;
}
