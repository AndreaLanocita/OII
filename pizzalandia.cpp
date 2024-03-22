#include <bits/stdc++.h> 

using namespace std;

#define vi vector<int>
#define pi pair<int, int>
#define vp vector<pi>
#define ll long long int
#define omap map<int, int>
#define umap unordered_map<int, int>

ll treno(int Tx, int Ty, int arrivox, int arrivoy, int X, int Y) {
    ll res = 0;
    // controllo se sono sullo stesso e il treno può raggiungerlo
    // oppure ricorsiva
    if(Tx == 0 && arrivox == 0 && Ty<=arrivoy) return (((ll) arrivoy)- ((ll) Ty));
    if(Tx == X && arrivox == X && Ty>=arrivoy) return (((ll) Ty) - ((ll) arrivoy));
    if(Ty==0 && arrivoy == 0 && Tx >= arrivox) return (((ll) Tx) - ((ll) arrivox));
    if(Ty==Y && arrivoy == Y && Tx <= arrivox) return (((ll) arrivox) - ((ll) Tx));

    if(Tx==0 && Ty != Y) return (((ll) Y) - ((ll) Ty)) + treno(0, Y, arrivox, arrivoy, X, Y);
    if(Tx==X && Ty != 0) return ((ll) Ty) + treno(X, 0, arrivox, arrivoy, X, Y);

    if(Ty==0 && Tx != 0) return ((ll) Tx) + treno(0, 0, arrivox, arrivoy, X, Y);
    if(Ty==Y && Tx != X) return ((ll) X) - ((ll) Tx) + treno(X, Y, arrivox, arrivoy, X, Y);
    return res;
}

int main() {
    int T;
    cin >> T;
    int X, Y, Tx, Ty, Wx, Wy;
    ll basso, alto, dx, sx;

    for(int i=0; i<T; i++) {
        cin >> X >> Y >> Tx >> Ty >> Wx >> Wy;
        // se non lo prende al primo giro, di sicuro al secondo
        ll tmp;
        ll giro_completo = (ll) 2*X + (ll) 2*Y;

        // alto
        alto = ((ll) Y)- ((ll) Wy);
        tmp = treno(Tx, Ty, Wx, Y, X, Y);
        if(tmp >= alto) alto = tmp;
        else alto = tmp + giro_completo;

        // alto
        basso = ((ll) Wy);
        tmp = treno(Tx, Ty, Wx, 0, X, Y);
        if(tmp >= basso) basso = tmp;
        else basso = tmp + giro_completo;

        // sx
        sx = ((ll) Wx);
        tmp = treno(Tx, Ty, 0, Wy, X, Y);
        if(tmp >= sx) sx = tmp;
        else sx = tmp + giro_completo;

        // dx
        dx = ((ll) X) - ((ll) Wx);
        tmp = treno(Tx, Ty, X, Wy, X, Y);
        if(tmp >= dx) dx = tmp;
        else dx = tmp + giro_completo;

        cout << min(alto, min(basso, min(dx, sx))) << endl;
    }
    return 0;
}