#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, L, M, Mi;
    string parola;

    cin >> N >> L >> Mi;
    unordered_map<string, int> parole;
    unordered_set<string> usato;
    vector<string> ordine;

    for(int i=0; i<Mi; i++) {
        cin >> parola;
        parole.insert(make_pair(parola, 0));
        ordine.push_back(parola);
    }
    

    for(int i=0; i<N-1; i++) {
        cin >> M;

        for(int h=0; h<M; h++) {
            cin >> parola;
            if(parole.find(parola) != parole.end() && usato.find(parola) == usato.end()) {
                parole[parola] += 1;
                usato.insert(parola);
            }
            
        }

        usato.clear();
    }

    //itero nel vettore
    for(int i=0; i<Mi; i++) {
        parola = ordine[i];
        cout << parole[parola] << " ";
    }
    
    return 0;
}