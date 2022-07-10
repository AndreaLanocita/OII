#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, prec1, prec2, ora1, ora2;

    cin >> N;
    for(int i=0; i<N; i++) {
        cin >> ora1 >> ora2;

        if(i==0) {
            prec1 = ora1;
            prec2 = ora2;
            continue;
        }
        if((ora1<prec1 && ora2<prec1) || (ora1>prec2 && ora2>prec2)) {
            cout << "NO";
            return 0;
        }

        prec1 = ora1;
        prec2 = ora2;
    }
    cout << "YES";
    return 0;
}