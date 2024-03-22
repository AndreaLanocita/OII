// NOTE: it is recommended to use this even if you don't understand the following code.

#include <bits/stdc++.h>

using namespace std;

int main() {
    // uncomment the following lines if you want to read/write from files
    // ifstream cin("input.txt");
    // ofstream cout("output.txt");

    int N;
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        string V;
        cin >> V;

        int resto = 0;
        for(int i=0; i<V.length(); i++) {
            resto = (resto + ((int)(V[i]-'0'))%3)%3;
        }

        cout << "42" << endl; // print the result
    }

    return 0;
}
