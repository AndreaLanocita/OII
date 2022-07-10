#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, ripetizioni, not_isogram, first, last, a;
    string input;

    cin >> N;
    cin.ignore();
    not_isogram = 0;

    for(int i=0; i<N; i++) {
        getline(cin, input);

        input[0] = tolower(input[0]);

        for(int j=0; j<input.size(); j++) {
            if(input[j] >= 65 && input[j] < 97) input[j] = tolower(input[j]);
        }

        for(int j=0; j<input.size(); j++) {
            first = input.find_first_of(input[j], j+1);
            last = input.find_last_of(input[j]);
            a = input.find_first_of(input[j], j);
            if((last == first || last == a) || (input[j] < 65) || (input[j] > 122) || (input[j] > 90 && input[j] < 97)) continue;

            not_isogram += 1;
            break;
        }
    }

    ripetizioni = N-not_isogram;
    cout << ripetizioni;
}