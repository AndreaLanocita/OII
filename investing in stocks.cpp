#include <bits/stdc++.h>

using namespace std;

int main() {
    int temp, N, prev, index, s, size;
    vector<int> v;
    vector<int> sums;

    cin >> N;
    for (int i=0; i<N; i++) {
        cin >> temp;
        v.push_back(temp);
    }

    prev = 0;
    index = 0;
    sums.push_back(0);

    for (int i=0; i<N; i++) {
        cin >> s;
        if (s == 1 && v[i] >= prev) {
            sums[index] = sums[index] + v[i];
            prev = v[i];
        }
        else if (s == 1) {
            index++;
            sums.push_back(0);
            prev = v[i];
            sums[index] = sums[index] + v[i];
        }
        else {
            prev = 0;
            index++;
            sums.push_back(0);
        }
    }

    sort(sums.begin(), sums.end());
    size = sums.size();
    cout << sums[size-1];

    return 0;
}