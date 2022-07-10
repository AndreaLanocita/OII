#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, tot, temp, people;
    vector<int> goods;
    tot = 0;

    cin >> N;
    for (int i=0; i<N; i++) {
        cin >> temp;
        goods.push_back(temp);
        tot += temp;
    }

    sort(goods.begin(), goods.end());
    people = N/3;
    for (int i=1; i<=people; i++) {
        tot -= goods[N-(3*i)];
    }
    cout << tot;

    return 0;
}