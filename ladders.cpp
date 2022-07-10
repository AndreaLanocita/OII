#include <iostream>

using namespace std;

int main() 
{
    int N;
    cin >> N;
    int C[N];

    long long differenza;


    //N = 4;
    cin >> C[0];
    long long massimo = C[0];
 

    for (int i = 1; i < N; i++)
    {
        int a;
        cin >> a;
        C[i] = a;
        //cout << C[i] << a;
        differenza = C[i] - C[i-1];
        if (differenza > massimo)
        {
            massimo = differenza;
        }
        //cout << massimo;

    }
    cout << massimo;
}