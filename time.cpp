#include <bits/stdc++.h>

using namespace std;




int main() {
    // input data
    int H0, M0, H1, M1;
//  uncomment the following lines if you want to read/write from files
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    assert(4 == scanf("%d%d%d%d", &H0, &M0, &H1, &M1));

    // insert your code here
    int resora, resmin;
    resora = H1-H0;
    resmin = M1-M0;

    if(resmin < 0) {
        resmin += 60;
        resora--;
    }
    if(resora<0) resora += 24;


    cout << resora << " " << resmin;
    return 0;
}
