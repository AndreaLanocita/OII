#include <bits/stdc++.h> 

using namespace std;

#define vi vector<int>
#define pi pair<int, int>
#define vp vector<pi>
#define ll long long int
#define omap map<int, int>
#define umap unordered_map<int, int>

// ASSUMING SIZE <= 3!!
vector<int> successor(vector<int> &lis) { // dont need to copy lis
    int flag=0, i=0; // checks for overflow
    vector<int> succ;

    // Using a for loop so it can be generalized to work with greater numbers
    for(; i<lis.size() && flag==0; i++) {
        if(lis[i]==2) { 
            succ.push_back(0);
            continue;
        }
        flag = 1;
        succ.push_back(lis[i]+1);
    }

    if(flag==0 && i==3) { // overflow
        return {-1};
    }

    // copying the rest of the list
    for(; i<lis.size(); i++) succ.push_back(lis[i]);
    for(; i<3 && flag==0; i++) { // might have an array with many trailing zeroes
        flag = 1;
        succ.push_back(1);
    } 
    return succ; // dont want to add the zeroes so I can save up space
}

bool leq(vector<int> &A, vector<int> &B) {
    // I could simply convert both lists, obtaining a very easy solution.
    // However, this solution would be linearithmic in time, which is not optimal.
    // Instead, by comparing the two lists directly, I can solve the problem in O(N)
    
    // First, I need to compare lists that could be equal but written in differente ways
    // i.e. [1, 0, 0] [1]

    // counting the trailing zeroes
    int sizeA= A.size();
    for(int i=A.size()-1; i>=0; i--) {
        if(A[i]==0) sizeA--;
        else break;
    }

    int sizeB= B.size();
    for(int i=B.size()-1; i>=0; i--) {
        if(B[i]==0) sizeB--;
        else break;
    }

    if(sizeA<sizeB) return 1;
    if(sizeA>sizeB) return 0;

    for(int i=sizeA; i>=0; i--) { // it makes sense to start from the mst, to make it slightly faster
        if(A[i]>B[i]) return 0;
        if(A[i]<B[i]) return 1;
    }
    return 1; // if they are equal
}

vector<int> tritwise_min(vector<int> &A, vector<int> &B) {
    int N = min(A.size(), B.size()), i=0; 
    vector<int> res;
    for(i; i<N; i++) res.push_back(min(A[i], B[i])); // anything else is a trailing zero

    return res;
}

vector<int> f(vector<int> &A, vector<int> &B) {
    if(!leq(A, B)) return {-1}; 
    vector<int> res = A, succ; 
    while(leq(succ, B)) { // B is the last list checked
        succ = successor(A);
        res = tritwise_min(A, succ);
        A = succ;
    }
    return res;
}

vector<int> f_eff(vector<int> &A, vector<int> &B) {
    if(!leq(A, B)) return {-1}; 
    int N = min(A.size(), B.size()); int i=N-2;
    vector<int> res(N); 
    res[N-1] = min(A[N-1], B[N-1]);

    for(i; i>=0; i--) {
        if(A[i+1]<B[i+1]) break;
        res[i] = min(A[i], B[i]);
    }

    for(i; i>=0; i--) res[i] = 0;
    return res;
}

int main() {
    freopen("C:\\repos\\c++\\github\\OII\\output.txt", "w", stdout);
    freopen("C:\\repos\\c++\\github\\OII\\input.txt", "r", stdin);

    vector<int> res;
    vector<int> lis{2, 0, 1};
    res = successor(lis);
    for(int i=0; i<res.size(); i++) cout<< res[i] << " ";
    cout << endl;
    vector<int> succ{1, 1, 1};
    cout << leq(lis, succ) << endl;

    
    res = tritwise_min(lis, succ);
    for(int i=0; i<res.size(); i++) cout<< res[i] << " ";
    cout << endl;

    res = f(lis, succ);
    for(int i=0; i<res.size(); i++) cout<< res[i] << " ";
    cout << endl;

    vector<int> lis1{0, 1};
    vector<int> succ1{1, 2, 1};
    res = f_eff(lis1, succ1);
    for(int i=0; i<res.size(); i++) cout<< res[i] << " ";
    cout << endl;
}