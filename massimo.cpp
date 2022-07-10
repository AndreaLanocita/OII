#include <bits/stdc++.h>

using namespace std;

int trova_massimo(int N, vector<int> V) {
    int sol = V[0];
    for(int i=1; i<N; i++) {
        if(V[i] > sol) sol = V[i];
    }

    return sol;
}

int main() {
    int N, temp, sol; 
    vector<int> V;

    ifstream indata;
    indata.open("input.txt");
    indata >> N;

    while(!indata.eof()) {
        indata >> temp;
        V.push_back(temp);
    }
    indata.close();

    sol = trova_massimo(N, V);
    ofstream outdata;
    outdata.open("output.txt");
    outdata << sol;
}