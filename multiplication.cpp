// NOTE: it is recommended to use this even if you don't understand the following code.

#include <bits/stdc++.h>


using namespace std;

// input data
int N;
vector<int> K;

int solve(int a) {
    int counter=10; // oppure nove?
    int k = 1; int n;
    int cifre[10] = {};
    while(counter!=0) { 
        n = a*k;
        while(n!=0) {
            int cifra = n%10;
            if(!cifre[cifra]) {
                counter--;
                cifre[cifra] = 1;
            }
            n /= 10;
        }
        k++;
    }
    return k;
}

int main() {
//  uncomment the following lines if you want to read/write from files
//  ifstream cin("input.txt");
//  ofstream cout("output.txt");

    cin >> N;
    K.resize(N);
    for (int i=0; i<N; i++)
        cin >> K[i];

    for(int i=0; i<N; i++) cout << solve(K[i])-1 << endl;
    return 0;
}
