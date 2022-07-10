#include <bits/stdc++.h>

using namespace std;

forward_list<int> adj[500000];
int cambiamenti;

int cmb_lst(int x, int y) {
    if(find(adj[x].begin(), adj[x].end(), y) != adj[x].end()) {
        adj[x].remove(y); 
        adj[y].remove(x);
        cambiamenti += 1;
        return 0;
    }
    adj[x].push_front(y); 
    adj[y].push_front(x); 
    cambiamenti -= 1;
    return 0;
}

int pth_fdr(int N, int inizio, int fine, vector<int> visitato) {
    int temp;
    visitato[inizio] = 1;
    for(forward_list<int>::iterator i = adj[inizio].begin(); i != adj[inizio].end(); i++) {
        if(*i == fine) return 1;
        if(visitato[*i] == 1) continue;

        temp = (int) *i;
        if (pth_fdr(N, temp, fine, visitato)==1) return 1;
    }
    return 0;
}

int main() {
    int N, Q, sum, temp, temp1, evento, inizio, fine;
    vector<int> visitato;

    cin >> N >> Q;

    for(int i=0; i<N-1; i++) {
        cin >> temp >> temp1;

        adj[temp].push_front(temp1);
        adj[temp1].push_front(temp);
    }

    sum = 0; 
    for(int i=0; i<Q; i++) {
        cin >> evento >> temp >> temp1;
        if(evento==1) cmb_lst(temp, temp1);

        else if(evento==2) {
            inizio = (temp+sum) % N + 1;
            fine = (temp1+sum) % N + 1;
            if(inizio==fine || cambiamenti==0) {  
                cout << 1 << endl;
                sum += 1;
                continue;
            }

            visitato.assign(N+1, 0);
            temp = pth_fdr(N, inizio, fine, visitato);
            cout << temp << endl;
            sum += temp;
        }
    }
}