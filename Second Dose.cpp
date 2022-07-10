#include <bits/stdc++.h>

using namespace std;


int main() {
    int D1, D2, temp, counter;
    vector<int> Dose1;
    vector<int> Dose2;

    cin >> D1 >> D2;
    for (int i=0; i<D1; i++) {
        cin >> temp;
        Dose1.push_back(temp);
    }
    for (int i=0; i<D2; i++) {
        cin >> temp;
        Dose2.push_back(temp);
    }

    if(D1 > D2) {
        sort(Dose2.begin(), Dose2.end());

        for(int i=0; i<D1; i++) {
            if (binary_search(Dose2.begin(), Dose2.end(), Dose1[i])) counter += 1;
        }
    }
    else {
        sort(Dose1.begin(), Dose1.end());

        for(int i=0; i<D2; i++) {
            if (binary_search(Dose1.begin(), Dose1.end(), Dose2[i])) counter += 1;
        }
    }
    cout << counter;

    return 0;
}
