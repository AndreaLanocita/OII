#include <bits/stdc++.h>

using namespace std;

int counter;
int recursive(int number, int binary[], int depth) {
    int remainder;

    remainder = number % 2;

    // sono arrivato alla fine
    if(number == 1) {
        binary[depth] = remainder;
        counter = depth;
        return 0;
    }

    number = number / 2;
    // non ho finito, vado avanti
    recursive(number, binary, depth+1);

    // finisce la ricorsione, aggiungo e ritorno
    binary[depth] = remainder;
    return 0;
}

int main() {
    int number;
    int binary[10000];

    cin >> number;

    recursive(number, binary, 0);

    for(int i=0; i<counter+1; i++) {
        cout << binary[i];   
    }

    // // I'll shift the bits till I reach zero
    // for( ; number != 0; ) {
    // // check if the last bit == 1
    // if(number & 1 == 1) v.push_back(1);
    // else v.push_back(0);

    // // shift numbers bits to the right
    // number = number >> 1;
    // }

    // for(int i=0; i<v.size(); i++) {
    // cout << v[i];
    // }

    // return 0;
}