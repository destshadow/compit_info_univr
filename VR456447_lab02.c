/*
Scrivere un programma in C (matricola_lab02.c, sostituendo "matricola" col proprio numero di matricola universitaria) per calcolare la somma di due valori binari.

I due valori binari dovranno essere inseriti dall'utente e si dovrà controllare se i due valori inseriti sono effettivamente nella forma binaria (ovvero un numero formato solo da 0 e 1).
Nel caso in cui si dovessero rilevare valori con dei digit diversi da 0 e 1, viene stampato un messaggio di errore e si termina il programma.

*/

#include <stdio.h>
#define DIM 4

int main(){
    //dichiarazione variabili
    int array1[DIM];
    int array2[DIM];
    int resto = 0;
    int array3[DIM] = {0};

    //inserimento primi n bit
    for (int i = DIM - 1; i >= 0; i--){
        scanf("%i", &array1[i]);
    }

    //inserimento secondi n bit
    for (int i = DIM - 1; i >= 0; i--){
        scanf(" %i", &array2[i]);
    }

    //controllo errori
    for (int i = 0; i < DIM; i++){
        if (array1[i] != 0 && array1[i] != 1)
        {
            printf("Errore nell'inserimento dei valori!\n");
            return 0;
        }
        if (array2[i] != 0 && array2[i] != 1)
        {
            printf("Errore nell'inserimento dei valori!\n");
            return 0;
        }
    }

    //somma delle variabili
    for (int i = DIM - 1; i >= 0; i--){
        if (array1[i] == 1 && array2[i] == 1){
            if (resto == 0){
                array3[i] = 0;
                resto++;
            }
            else{
                array3[i] = 1;
                resto = 0;
            }
        }
        else{
            if (resto == 0){
                array3[i] = array1[i] + array2[i];
                resto = 0;
            }
            else if (resto == 1 && (array1[i] == 1 || array2[i] == 1)){
                array3[i] = 1;
                resto = 0;
            }
        }
    }

    printf("\n");

    printf("riscultato: ");

    //stampa risultato
    for (int i = DIM - 1; i >= 0; i--){
        printf("%i ", array3[i]);
    }

    return 0;
}