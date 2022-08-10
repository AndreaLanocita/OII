#include <bits/stdc++.h>
#include <climits>

using namespace std;

int ricorsiva(vector<int> v, int max_p) {
    vector<int> v_tmp;
    int res = INT_MAX;
    int tmp;
    if(v.size()==1) return max(abs(v[0]), max_p);
    for(int i=1; i<v.size(); i++) {
        v_tmp = v;
        v_tmp[i-1] += v_tmp[i];
        v_tmp.erase(v_tmp.begin() + i);
        tmp = abs(ricorsiva(v_tmp, max(abs(v_tmp[i-1]), max_p)));
        res = min(res, tmp);
    }
    return res;
}

int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int N;
    cin >> N;

    vector<int> v(N);
    for(int i=0; i<N; i++) cin >> v[i];

    cout << ricorsiva(v, 0);
}