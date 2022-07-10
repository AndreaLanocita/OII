#include <bits/stdc++.h>

using namespace std;


struct Missione {
 int durata, fine;
};


Missione missioni[101];
int soluzioni[366];


int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");
    int n;
    in >> n;
    for (int i=0; i<n; i++)
        in >> missioni[i].durata >> missioni[i].fine;
        
    for (int i=0; i<n; i++)
        for (int j=missioni[i].fine - missioni[i].durata; j>=0; j--)
            if (soluzioni[j] + 1 > soluzioni[j+missioni[i].durata])
                soluzioni[j+missioni[i].durata] = soluzioni[j]+1;
    
    int max = soluzioni[0];
    for (int i=0; i<366; i++)
        if (soluzioni[i] > max) max = soluzioni[i];
    out << max;
}