#include <bits/stdc++.h> 

using namespace std;

#define vi vector<int>
#define pi pair<int, int>
#define vp vector<pi>
#define ll long long int
#define omap map<int, int>
#define umap unordered_map<int, int>

int a, b;
vector<int> palindromi;

// n è sempre palindromo
void contaPalindromi(int n, int cifre) {
    // genero i nuovi palindromi
    int poww = pow(10, cifre+1);
    int poww1 = pow(10, cifre-1);
    for(int i=0; i<10; i++) {
        // n troppo grande --> finisce
        if(n>10000000) return ;

        // n è corretto --> aggiungo
        if(n>=1) palindromi.push_back(n);

        int tmp = n*10+1+poww;
        contaPalindromi(tmp, cifre+2);
        n+=1;
        if(cifre != 1) n += poww1;
    }
}

int main() {
    int N; ll res;
    cin >> N;
    contaPalindromi(0, 1);
    contaPalindromi(0, 2);
    sort(palindromi.begin(), palindromi.end());
    for(int i=0; i<N; i++) {
        cin >> a >> b;
        res = ((upper_bound(palindromi.begin(), palindromi.end(), b)-palindromi.begin()))-(lower_bound(palindromi.begin(), palindromi.end(), a)-palindromi.begin());
        cout << res << "\n";
    }

    return 0;
}