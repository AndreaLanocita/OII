/*
 * NOTE: it is recommended to use this even if you don't
 * understand the following code.
 */

#include <iostream>

using namespace std;

// input data
int N, M, E;

int main() {
//  uncomment the following lines if you want to read/write from files
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    cin >> N >> M >> E;

    int soldi_marco_1, soldi_marco;
    soldi_marco_1, soldi_marco = 0;
    
    for (int i = M; i <= N; i++) {
        soldi_marco_1 = E % i;
        
        if (soldi_marco_1 >= soldi_marco) {
            soldi_marco = soldi_marco_1;
        }
    }
    

    cout << soldi_marco << endl; // print the result
    return 0;
}
