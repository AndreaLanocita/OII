/*
 * NOTE: it is recommended to use this even if you don't
 * understand the following code.
 */

#include <iostream>

using namespace std;

int main() {
//  uncomment the following lines if you want to read/write from files
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    long long N;
    cin >> N;
    long long sum = 1;
    long long product = 1;
    long long count = 1;
    // Saltiamo il primo caso, quello del ceo
    
    while (count <= N) {
        long long a;
        cin >> a;

        sum += product * a;
        product = product * a;
        count++; 
    }

    cout << sum; // print the result
    return 0;
}
