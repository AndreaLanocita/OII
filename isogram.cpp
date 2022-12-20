// NOTE: it is recommended to use this even if you don't understand the following code.

#include <bits/stdc++.h>

using namespace std;

// input data
int N;
string S;

int main() {
//  uncomment the following lines if you want to read/write from files
    ifstream cin("input.txt");
//  ofstream cout("output.txt");

    cin >> N;
    cin.ignore();

    unordered_map<int, int> map;
    int flag, counter=0;
    for (int i=0; i<N; i++) {
        flag = 0;
        getline(cin, S);

        // insert your code here
        for(int j=0; j<S.length(); j++) {
            if(S[j] >= 65 && S[j] <= 90) S[j] += 32;
            if(!(S[j] >= 97 && S[j] <= 122)) continue;
            map[S[j]]++;
            if(map[S[j]] > 2) {
                flag = 1;
                break;
            }
        }
        map.erase(map.begin(), map.end());
        if(flag!=1) counter++;
    }

    cout << counter << endl; // print the result
    return 0;
}
