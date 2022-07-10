#include <bits/stdc++.h>
#include <climits>

using namespace std;

typedef long long ll;
typedef vector<ll> vi;

ll N, K;

// with a sliding door

ll countt(vi &v, ll x) {
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
            // faccio update
            start++;
            sum -= v[start-1];
        }
    }

    return count;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> N >> K;
    
    vi v(N), p(N+1);
    cin >> v[0];
    p[0] = 0;  // importantissimo per i calcoli successivi con lower_bound
    for(int i=1; i<N; i++) {
        cin >> v[i];
        // array che indica il prezzo di un tour che parte da 0 e arriva a i-1
        p[i] = p[i-1] + v[i-1];
    }
    p[N] = p[N-1] + v[N-1];

    // ricerca binaria sul risultato, voglio trovare il costo 
    // del tour K, per farlo trovo x | count(x) è il minore >= K
    ll l = 0;
    ll r = p[N];
    ll mid;

    // O(NlogN)
    while(l<r) {
        mid =(l+r)/2;
        // non rispetta la condizione --> ce ne sono troppi pochi --> alzo il prezzo
        if(countt(v, mid) < K) l = mid+1;
        // rispetta la condizione --> ce ne sono troppi --> abbasso il prezzo
        else r = mid;
    }

    // tra i tour con questo cost, quale indice ha quello che devo trovare?
    // L'indice del tour che voglio trovare meno il numero di quelli che hanno un costo minore
    int indice = K - countt(v, r-1);

    // ora tra i tour che hanno il costo = costo, trovo quello con indice = indice
    // = trovo il indiceesimo subarray con sum = costo
    // O(N)
    int i = 0;
    vi::iterator fine;
    for(i; i<N && indice != 0; i++) {
        // primo elemento >= p[i] + costo
        fine = lower_bound(p.begin(), p.end(), p[i] + r);
        // uso lower_bound come un b_search, controllo che l'elemento esista 
        // e sia esattamente = a quello che mi serve
        if(fine == p.end() || *fine - r != p[i]) continue;
        // diminuisco l'indice, quando arrivo a 0 esco dal loop e ho il risultato
        indice--;
    }

    // output 0 based, tolgo 1
    cout << i-1 << " " << fine - p.begin() - 1 << endl;
    
    return 0;
}