#include <bits/stdc++.h>

using namespace std;


int main() {
    int N, X, temp1, temp2;
    vector<int> perc;
    vector<int> cost;
    vector<int> sol;
    vector<int> sol_temp;

    cin >> N >> X;
    for(int i=0; i<N; i++) {
        cin >> temp1 >> temp2;
        perc.push_back(temp1);
        cost.push_back(temp2);
    }

    for(int i=0; i<=X; i++) {
        sol.push_back(0);
        sol_temp.push_back(0);
    }

    for(int i=0; i<N; i++) {
        for(int j=0; j<=X-cost[i]; j++) {
            if(cost[i] > X) break;
            if(sol[j] + perc[i] > sol[j+cost[i]]) sol_temp[j+cost[i]] = sol[j] + perc[i];
        }
        sol = sol_temp;
    }

    sort(sol.begin(), sol.end());
    cout << sol[X];


    return 0;
}