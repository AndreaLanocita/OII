#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    long long distanza, lunghezza, temp;
    int min, index, N;
    vector<long long> distanze;
    
    
    cin >> N >> distanza >> lunghezza;
    
    for(int i=0; i<N; i++) {
        cin >> temp;
        distanze.push_back(temp);
    }
    
    if(lunghezza>distanze[N-1]+distanza || 0<distanze[0]-distanza) {
        cout << 0;
        return 0;
    }

    // trovo il min del primo punto
    temp = 0;
    for(int j=0; j<N; j++) {
        if(0<distanze[j]-distanza) break;
        temp+=1;
    }
    min = temp;
    index = 1;

    for(long long i=distanze[0]+distanza+1; i<=lunghezza;) {
        temp = 0;
        
        if((index+min-1 < N && distanze[index+min-1]-distanza > i) || index+min-1 >= N) {
            for(int j=index; j<N; j++) {
                if(i<distanze[j]-distanza || min<=temp) break;
                temp+=1;
            }
        
            min = temp;
        }
        
        i = distanze[index] + distanza + 1;
        index++;
    }

    cout << min;

    return 0;
}
