#include <bits/stdc++.h>

using namespace std;


int main() {
    random_device dev;
    mt19937 rng(dev());
    uniform_int_distribution<mt19937::result_type> dist3(1,3); 

    int totali = 0, corretti = 0;
    for(int i=0; i<100000000; i++) {
        int porta_corretta = dist3(rng);
        int porta_indovinata = dist3(rng);
        int porta_rimossa = porta_indovinata;
        while(porta_rimossa == porta_indovinata || porta_rimossa == porta_corretta) porta_rimossa = dist3(rng);
        
       int secondo_tentativo = porta_rimossa;
       while(secondo_tentativo == porta_rimossa) secondo_tentativo = dist3(rng);

        totali++;
        if(porta_corretta == secondo_tentativo) corretti++;
    }

    printf("Casi totali: %d\n", totali);
    printf("Casi corretti: %d\n", corretti);
    printf("Probailità di trovare la porta corretta: %f%", ((float) corretti)/totali);
    return 0;
}


// int main() {
//     random_device dev;
//     mt19937 rng(dev());
//     uniform_int_distribution<mt19937::result_type> dist3(1,3); 

//     int totali = 0, corretti = 0;
//     for(int i=0; i<1000000000; i++) {
//         int porta_corretta = dist3(rng);
//         int porta_indovinata = dist3(rng);
//         int porta_rimossa = porta_indovinata;
//         while(porta_rimossa == porta_indovinata || porta_rimossa == porta_corretta) porta_rimossa = dist3(rng);
        
//         for(int j=1; j<=3; j++) {
//             if(j==porta_rimossa || j==porta_indovinata) continue;
//             porta_indovinata = j;
//             break;
//         }

//         totali++;
//         if(porta_corretta == porta_indovinata) corretti++;
//     }

//     printf("Casi totali: %d\n", totali);
//     printf("Casi corretti: %d\n", corretti);
//     printf("Probailità di trovare la porta corretta: %f%", ((float) corretti)/totali);
//     return 0;
// }