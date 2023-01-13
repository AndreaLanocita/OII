#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    //  uncomment the following lines if you want to read/write from files
    //  ifstream cin("input.txt");
    //  ofstream cout("output.txt");

    int N, M;
    cin >> N >> M;

    vector<int> A(M), B(M), C(M);
    for (int i = 0; i < M; i++) {
        cin >> A[i] >> B[i] >> C[i];
    }

    // insert your code here

    cout << 42 << endl; // print the result

    return 0;
}
