#include <bits/stdc++.h>

using namespace std;


int solve(int N, int K, int* S) {
    vector<pair<int, long long>> dx(N);
    vector<pair<int, long long>> sx(N);

    int best = 0;
    long long c = 0; long long z = 0;
    for(int i=0; i<N; i++) {
        if(S[i] == 0) z++;
        else c += S[i];
        sx[i] = {z, c};
    }

    c = 0; z = 0;
    for(int i=N-1; i>=0; i--) {
        if(S[i] == 0) z++;
        else c += S[i];
        dx[i] = {z, c};
    }

    int p1 = 0; int p2 = N;
    for(int i=N-1; i>=0; i--) {
        if(dx[i].second <= K) p2 = i;
        else if (dx[i].second > K) break; 
    }

    if(p2 < N) best = dx[p2].first;
    for( ; p1 < N; p1++) {
        if(p2 >= N) goto fine;
        while(sx[p1].second + dx[p2].second > K) {
            p2++;
            if(p2 >= N) break; // GOTOTOOT
        }
        fine:
        if(p2 >= N && sx[p1].second <= K) best = max(sx[p1].first, best);
        if(p2<N) best = max(dx[p2].first + sx[p1].first, best);
    }

    // cout << best;
    return best;
}