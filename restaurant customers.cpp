// You are given the arrival and leaving times of n customers in a restaurant.

// What was the maximum number of customers in the restaurant at any time?

// Input

// The first input line has an integer n: the number of customers.

// After this, there are n lines that describe the customers. Each line has two integers a and b: the arrival and leaving times of a customer.

// You may assume that all arrival and leaving times are distinct.

// Output

// Print one integer: the maximum number of customers.

// Constraints
// 1≤n≤2⋅105
// 1≤a<b≤109
// Example

// Input:
// 3
// 5 8
// 2 4
// 3 9

// Output:
// 2

#include <bits/stdc++.h>

using namespace std;

int main() {
    long long N, a, b;
    vector<pair<long long, int>> v;
    cin >> N;

    for(int i=0; i<N; i++) {
        cin >> a >> b;
        // we use prefix sums, for each point after a (included) we add 1 customer
        v.push_back(make_pair(a, 1));
        // for each point after b (included) we subtract 1 customer
        v.push_back(make_pair(b, -1));
    }
    // we sort the array so that each prefix (both a and b) are in order in time
    sort(v.begin(), v.end());
    // summ is the temp value, maxx is the max number of customers in a time unit
    long long maxx = 0, summ = 0;
    for(int i=0; i<v.size(); i++) {
        summ += v[i].second;
        if(summ > maxx) maxx = summ;
    }

    cout << maxx;
    return 0;
}

