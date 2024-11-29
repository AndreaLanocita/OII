/*
 * This template is valid both in C and in C++,
 * so you can expand it with code from both languages.
 * NOTE: it is recommended to use this even if you don't
 * understand the following code.
 */

#include <bits/stdc++.h>

using namespace std;

// constraints
#define MAXM 200000
#define MAXN 200000

#define vp pair<int, int>

// input data
int N, M, i;
int A[MAXM], B[MAXM], W[MAXM];
vector<int> C, D, E;

int main() {
//  uncomment the following lines if you want to read/write from files
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    assert(2 == scanf("%d%d", &N, &M));
    for(i=0; i<M; i++)
        assert(3 == scanf("%d%d%d", &A[i], &B[i], &W[i]));

    // insert your code here
    vp S[N] = { };
    for(int i=0; i<M; i++) {
        S[A[i]].first -= W[i];
        S[A[i]].second = A[i];

        S[B[i]].first += W[i];
        S[B[i]].second = B[i];
    }
    sort(S, S+N);

    int pi = N-1; int pa = 0;
    int counter = 0;
    while(pi!=pa) {
        if(S[pi].first == 0) {
            pi--;
            continue;
        }

        else if(S[pi].first > 0) {
            counter++;
            int flag = 0;
            if(abs(S[pi].first) >= abs(S[pa].first)) {
                if(S[pi].first == S[pa].first) flag = 1;
                S[pi].first += S[pa].first;
                C.push_back(S[pi].second);
                D.push_back(S[pa].second);
                E.push_back(-S[pa].first);
                S[pa].first = 0;
                pa++;
                if(flag==1) pi++;
            } else {
                S[pa].first += S[pi].first;
                C.push_back(S[pi].second);
                D.push_back(S[pa].second);
                E.push_back(S[pi].first);
                S[pi].first = 0;
                pi--;
            }
        }
    }

    cout << C.size() << endl;
    for(int i=0; i<C.size(); i++) {
        cout << C[i] << " " << D[i] << " " << E[i] << endl;
    }
    
    return 0;
}
