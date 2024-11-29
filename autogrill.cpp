#include <bits/stdc++.h>
using namespace std;

int arrampicate(int N, string S){
    
    
    int res=0;
    for(int i=0; i<N+1; ) {
        int c = S[i]; 
        if(c=='=') {i++; continue;}
        // i++;
        //if(c=='?') c == 
        res++;
        while((c == S[i] || S[i]=='=') && c!='#' && i<N+1) i++;
        i++;
    }
    if(res==0) return 1;
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove these two lines in interactive problems.

    int N;
    assert(cin >> N);
    
    string S;
    assert(cin >> S);

    cout << arrampicate(N, move(S)) << '\n';

}
