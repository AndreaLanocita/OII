// NOTE: it is recommended to use this even if you don't understand the following code.

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
//  uncomment the following lines if you want to read/write from files
// ifstream cin("input.txt");
//  ofstream cout("output.txt");

    // input data
    int N;
    vector<char> L;
    cin >> N;
    L.resize(N);
    for (int i=0; i<N; i++)
        cin >> L[i];

    // insert your code here
    int counter = 0, rimaste, res = 1;
    for(int i=0; i<N; i++) {
        if(L[i]=='_') counter++;
    }
    rimaste = 26 - (N-counter);
    
    for(int i=0; i<counter; i++) {
        res *= (rimaste-i);
    }

    cout << res << endl; // print the result
    return 0;
}
