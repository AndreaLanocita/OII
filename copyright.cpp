#include <bits/stdc++.h>


using namespace std;

int main() 
{
    int N;
    cin >> N;

    char testo[N];

    for (int t = 0; t < N; t++)
    {
        cin >> testo[t];
    }


    int numeroCaratteri;


    for (int i = 0; i < N; i++)
    {
        if (testo[i] == '(' && testo[i+1] == 'C' && testo[i+2] == ')')
        {
            int posizione = i;
            int q = i+2;
            int z = 0;

            while (z == 0)
            {
                q++;
                if (testo[q] == '.')
                {
                    break;
                }
            }
            char annoFinale[4];
            annoFinale[0] = testo[q-4];
            annoFinale[1] = testo[q-3];
            annoFinale[2] = testo[q-2];
            annoFinale[3] = testo[q-1];

            if (testo[q-4] == '2' && testo[q-3] == '0' && testo[q-2] == '1' && testo[q-1] == '7')
            {
                testo[q-1] = '8';
                numeroCaratteri = N;
                break;
            }
            else
            {
                numeroCaratteri = N + 6;
                testo.std::vector::insert(q,", 2018");
                break;
            }


        }

    }
    cout << numeroCaratteri << "\n";
    cout << testo;

