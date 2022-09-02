#include <bits/stdc++.h> 
#include <climits>

using namespace std;

#define vi vector<int>
#define pi pair<int, int>
#define vp vector<pi>
#define ll long long int
#define omap map<int, int>
#define umap unordered_map<int, int>

#define INF INT_MIN

vi st;
int real_size = 1;
void build(vi& Pd) {
    int n = Pd.size();
    while(real_size<n) real_size *= 2;

    st.assign(2*real_size, 0);

    for(int i=0; i<n; i++) st[i+real_size] = Pd[i] + i;
    for(int i=real_size-1; i>0; i--) st[i] = max(st[2*i], st[2*i+1]);
}

int query(int u, int l, int r, int x, int y) {
    if(l>=y || r<=x) return INF;
    if(l>=x && r<=y) return st[u];
    return max(
        query(2*u, l, (r+l)/2, x, y),
        query(2*u+1, (r+l)/2, r, x, y)
    );
}

void visita(vi& v, umap& mappa, int& end_v) {
    for(int i=0; i<v.size(); i++) {
        if(mappa.count(v[i]) != 0) {
            end_v = i+1;
            break;
        } 
        else mappa[v[i]] = i+1;
    } 
    if(end_v==-1) end_v = v.size()+1;
}

void make_array(vi& v, int end_v, umap& mappa, vi& p, int end_p) {
    // ne prendo zero
    p.push_back(end_p-1);
    for(int i=0; i<end_v-1; i++) {
        if(mappa.count(v[i]) == 0) p.push_back(p[i]);
        else p.push_back(min(mappa[v[i]]-1, p[i]));
    }
}

int conta(int N, vector<int> &A, vector<int> &P, vector<int> &D) {
    umap visto_a, visto_p, visto_d; // salvo valore: index
    int end_a = -1, end_p = -1, end_d = -1, res = 0;    // last element (excluded)
    visita(A, visto_a, end_a);
    visita(P, visto_p, end_p);
    visita(D, visto_d, end_d);

    // for each element of the first letter, prefix of the second | no repetition
    vi Ap, Pd, Ad;  
    make_array(A, end_a, visto_p, Ap, end_p);
    make_array(A, end_a, visto_d, Ad, end_d);
    make_array(P, end_p, visto_d, Pd, end_d);

    // brute force
    // for(int i=0; i<end_a; i++) {
    //     for(int j=0; j<=Ap[i]; j++) {
    //         res = max(res, i+j+min(Pd[j], Ad[i])); 
    //     }
    // }
    build(Pd);

    int l, r, mid;
    for(int ka=0; ka<end_a; ka++) {
        l = 0; r = Ap[ka]+1;
        while(l<r) {
            mid = (l+r)/2;
            // condizione rispettata --> aumento kp
            if(Pd[mid] >= Ad[ka]) l = mid+1;
            else r = mid;
        }
        // r = L, il primo a non rispettare la proprietà
        // posso sempre prendere l'ultimo che rispetta la condizione
        res = max(res, ka+r-1+Ad[ka]);
        res = max(res, ka+query(1, 0, real_size, r, Ap[ka]+1));
    }
    
    return res;
}

int main() {
    // Input da file:
    freopen("input.txt", "r", stdin);

    // Output su file:
    // freopen("output.txt", "w", stdout);

    int N;
    assert(scanf("%d", &N) == 1);

    vector<int> A(N), P(N), D(N);
    for (int &a : A)
        assert(scanf("%d", &a) == 1);
    for (int &p : P)
        assert(scanf("%d", &p) == 1);
    for (int &s : D)
        assert(scanf("%d", &s) == 1);

    printf("%d\n", conta(N, A, P, D));
    return EXIT_SUCCESS;
}