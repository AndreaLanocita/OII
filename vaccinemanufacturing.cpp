#include <bits/stdc++.h> 

using namespace std;

#define vi vector<int>
#define pi pair<int, int>
#define vp vector<pi>
#define ll long long int
#define omap map<int, int>
#define umap unordered_map<int, int>

#define MOD 1000000007

/* 
restituisce il resto della parola più lunga, 
se quella più corta vi è contenuta.
*/
string parteContiguaFinale(string Si, string Sj) {
    string rem;
    int flag, l;   // quale è la piu corta?
    if(Si.length() < Sj.length()) {
        flag = 0;
        l = Si.length();
    } else {
        flag = 1;
        l = Sj.length();
    }

    for(int i=0; i<l; i++) 
        if(Si[i] != Sj[Sj.length()-1-i]) return "!";

    if(flag==0) {
        for(int i=0; i<(Sj.length()-Si.length()); i++) {
            rem.push_back(Sj[i]);
        }
    } else {
        for(int i=0; i<(Si.length()-Sj.length()); i++) {
            rem.push_back(Si[Si.length()-1-i]);
        }
    }
    return rem;
}

// flag = 0 se Si è più piccola o uguale
string check(string rem, string Sk, int flag) {
    string rem1;

    // il resto deve essere all'inizio di Sk
    if(flag == 0) {
        // devo sempre controllare se il resto è più grande
        // o piccolo, fare una flag...
    }
    // analog per flag == 1
}

int main() {
    int N; ll res;
    cin >> N;

    vector<string> S; S.resize(N);
    for(int i=0; i<N; i++) 
        cin >> S[i];

    for(int i=0; i<N; i++) {
        int counter = S[i].length();
        // cerco la seconda
        for(int j=0; j<N; j++) {
            string rem = parteContiguaFinale(S[i], S[j]);
            // non valido
            if(rem == "!") continue;
            counter += S[j].length();
            
            // cerco la terza
            for(int k=0; k<N; k++) {
                if(rem.length() == 0 && palindromo(S[k])) {
                    res = (res%MOD + 1)%MOD;
                    continue;
                }

                string rem1 = check(rem, S[k], (S[i].length()>S[j].length()));
                if(rem1 == "!") continue;

                counter += S[k].length();
                if(palindromo(rem1, counter%2)) res = (res%MOD + 1)%MOD;
            }
        }
    }
    return 0;
}