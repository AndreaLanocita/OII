#include <bits/stdc++.h>

using namespace std;

int main() {
    set<int> input, temp_set;
    map<set<int>> pacchetti(N); //map del set, controllo alla fine per ogni elemento di temp_set nella hash_map con find se appartengono a temp, se si tolgo il più piccolo
    int temp, val, N, M, multiplo, a;

    cin >> N >> M;
    for(i=0; i<N; i++) {
        cin >> temp;
        input.insert(temp);
    }

    for(int i=0; i<N; i++) {
        val = input[i];
        temp_set.insert(val);

        for(int j=i+1; j<N && val*a<M; j++) {
            multiplo = val*a;
            if(input.find(val)) temp_set.insert(multiplo);

            a++;
        }
        a=2;

        for(int j=i+1; j<N && val/a>1; j++) {
            multiplo = val/a;
            if(val%a == 0 && input.find(val)) temp_set.insert(multiplo);

            a++;
        }

        pacchetti.insert(temp_set);
    }

}