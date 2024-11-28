#include <bits/stdc++.h> 

using namespace std;

#define vi vector<int>
#define pi pair<int, int>
#define vp vector<pi>
#define ll long long int
#define omap map<int, int>
#define umap unordered_map<int, int>

bool is_set(int number, int x) {
    // rimuovo i primi x bit a destra e controllo se
    // il primo che rimane è 1
    return (number >> x) & 1;
}

// un numero è divisibile per 2^k se ha i primi k
// bit = zero
bool isDivisibleBytheKthPowerOf2(int n, int k) {
    int powerOf2 = 1 << k; // aggiungo k zeri
    return (n & (powerOf2 - 1)) == 0;
}

bool isPowerOfTwo(unsigned int n) {
    // && ritorna true se entrambi i numeri sono
    // differenti da zero
    // in pratica controlliamo se il secondo termine
    // fa o non fa zero. 
    return n && !(n & (n - 1));
}

// l'algoritmo va avanti finchè il numero non è zero
// se non lo è, c'è un bit settato --> aumento counter
// e lo tolgo con il trucchetto del & (n-1)
int countSetBits(int n) {
    int count = 0;
    while (n)
    {
        n = n & (n - 1);
        count++;
    }
    return count;
}

int main() {
    //cin.tie(nullptr);ios::sync_with_stdio(false);
    
    int n = 0b1101; // corrisponde a 13
    int neg = ~n+1; // complemento a due
    n = ~neg+1;
    cout << n << '\n';

    // bit shifting
    n = 0b1;
    n <<= 3; // 8, aggiungo zero a destra (alla fine)
    // corrisponde a moltiplicare per 2^3
    cout << n << '\n';

    n>>=3; // 1, toglie gli ultimi bit a destra
    // corrisponde a dividere per 2^3, attenzione che diventa pari
    cout << n << '\n';

    // useful tricks
    int a = 1<<3; // unico bit settato è il terzo
    a = ~ (1<<3); // tutti i bit settati tranne il terzo
    n = n | (1 << 3); // setta il terzo bit 
    n = n xor (1<<3); // flippa il terzop bit
    n = n& ~(1<<3); // setta a zero il terzo bit
    n = n&(n+1); // toglie tutti gli zero finali
    // NB 11010 --> 11010
    n = n | (n+1); // setta l'ultimo zero
    n = n& -n; // estra il bit meno importante settato
    
    return 0;
}