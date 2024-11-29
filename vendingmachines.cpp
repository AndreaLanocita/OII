#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t; cin >> t;
    int n,q;
    int tr,conto;
    for(int i = 0; i < t; i++)
    {
        cin >> n >> q; // n numero di oggetti, q numero di transazioni
        int p[n+1];
        for(int j=1; j < n+1; j++) cin >> p[j];
        conto=0;
        for(int a =0; a < q; a++)
        {
            cin >> tr;
            if(tr>0) conto+=tr;
            else if(tr<0) conto-=p[abs(tr)];
            if(conto <0)
            {
                cout << "HACKER" << endl;
                break;
            }
        }    
        if(conto >=0) cout << "OK" << endl;
       
    }
    return 0;
}