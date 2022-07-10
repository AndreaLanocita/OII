#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vi;

// with a sliding door

ll count(vi &v, ll x) {
    ll start = 0, end = 0, count = 0, sum = v[0];
    while(start < v.size() && end < v.size()) {
        // la somma totale rispetta le condizioni  --> mando avanti la sliding door
        if(sum <= x) {
            end++;
            
            /* 
            Secondo me non serve, se end = start --> sum = 0 --> la condizione è
            rispettata di sicuro --> end++
            if(end >= start) 
            */
        
           // tiene conto ancehe did quelli ceh salterei (andando troppo avanti)
           // se aumentassi solo di 1 count
           count += (end - start);

            // se no all'ultima iterazione va fuori spazio
            if(end != v.size()) sum += v[end];
        } 
        // non rispetta le condiizioni
        else {
            // fino all'iterazione prima le rispettava, faccio update
            start++;
            sum -= v[start-1];
        }
    }

    return count;
}

int main() {
    ll x, n;
    cin >> n >> x;

    vi v(n);
    for(int i=0; i<n; i++) {
        cin >> v[i];
    }

    cout << count(v, x);

    return 0;
}