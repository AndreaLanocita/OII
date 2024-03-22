// Si consideri una struttura che rappresenta un oggetti di tipo Film,
// caratterizzata da un anno di pubblicazione, un genere, ed un voto
// medio tra 0 e 10 (potrebbe non essere intero).

// Si consideri inoltre una struttura di tipo SalaCinema, caratterizzata
// da una lista di film, dal numero di film in sala e dal prezzo di un biglietto.

// Si scriva un programma in C che:
// legge il numero di film presenti nella sala cinema
// riempie l'array di film della sala cinema con tutte le informazioni necessarie
// calcola il ricavo stimato della sala cinema sapendo che il numero di persone che
// vedranno ciascun film dipende dal suo voto (es. voto 5.7, 570 persone previste)

#include <stdio.h>
#include <string.h>
#define N 3
#define L 20
typedef struct{
        char nome[L];
        int anno;
        char genere[L];
        float voto;
    } Film;

    typedef struct{
        Film films[N];
        int numero_film_in_sala;
        float prezzo_biglietto;
    } SalaCinema;

int main()
{

    int n_f, i;
    char nome[L];
    float ricavo=0;
    SalaCinema Colosseo;
    printf("quanti film ci sono? ");
    scanf("%d", &Colosseo.numero_film_in_sala);
    printf("inserire il prezzo di un biglietto: ");
        scanf("%f", &Colosseo.prezzo_biglietto);

    for(i=0; i<Colosseo.numero_film_in_sala; i++){
        printf("\n");
        printf("inserire le informazioni del film:\n");
        
        printf("nome del film ");        
        scanf("%s", Colosseo.films[i].nome); // così funziona solo se la stringa ha solo una parola 
        // gets(Colosseo.films[i].nome) // così non funziona proprio
        
        printf("anno di pubblicazione ");
        scanf("%d", &Colosseo.films[i].anno);
        printf("genere del film ");
        scanf("%s", Colosseo.films[i].genere);
        printf("voto ");
        scanf("%f", &Colosseo.films[i].voto);
    }

    // controllo se acquisisce bene (spoiler no)
    for(i=0; i<Colosseo.numero_film_in_sala; i++)
    printf("\nrisultato: %d: %s, %3d, %s, %3f, %3f", i+1, Colosseo.films[i].nome, Colosseo.films[i].anno, Colosseo.films[i].genere, Colosseo.films[i].voto, Colosseo.prezzo_biglietto);

    for(i=0; i<Colosseo.numero_film_in_sala; i++){
        ricavo += (Colosseo.films[i].voto)*100*(Colosseo.prezzo_biglietto);
    } printf("\nil ricavo è di: %5f", ricavo);

}