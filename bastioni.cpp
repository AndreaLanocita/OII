#include <bits/stdc++.h>
using namespace std;

int arrampicate(int N, string S){
    int flag=0;
    int res=0;
    for(int i=0; i<N; ) {
        int c = S[i]; 
        if(c=='=') {i++; continue;}
        if(flag==1) res++;
        flag--;
        if(c=='?') {flag=2; i++; continue;}
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
