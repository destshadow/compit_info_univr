/*
Scrivere un programma in C (matricola_lab03.c, sostituendo "matricola" col proprio numero di matricola universitaria) che chiede all'utente 5 valori interi non negativi e ne disegna l'istogramma a barre verticali come mostrato nel seguente esempio.
Nel caso di inserimento di valori negativi il programma deve terminare con un messaggio di errore.

Se l'utente inserisce i valori: 1 4 5 2 1, il programma visualizzerà il seguente output:

            *     
          * *     
          * *     
          * * *   
        * * * * * 
        1 4 5 2 1 
    
Si ricorda che verranno considerati nel punteggio anche la presenza di commenti e la corretta indentazione.
*/
#include <stdio.h>
#define DIM 5

int main(){
    //dichiarazione delle variabili
    int array[DIM];
    int max = 0;

    //inserimento dei numeri nell'array
    for(int i = 0; i < DIM; i++){
        printf("inserisci un numero: ");
        scanf(" %i", &array[i]);
        if(array[i] < 0){
            printf("Errore nell'insierimento, numero negativo!\n");
            return 0;
        }
        printf("\n");
    }

    //calcolo del valore massimo inserito
    for(int i = 0; i < DIM; i++){
        if(array[i] > max){
            max = array[i];
        }
    }

    //stampa dei valori '*' e ' '
    for (int i = 0; i < max; i++){
        for (int j = 0; j < DIM; j++){
            if (array[j] >= max - i)
                printf("* ");
            else
                printf("  ");
        }
        printf("\n");
    }

    //stampa dei valori nell'array
    for(int i = 0; i < DIM; i++){
        printf("%i ", array[i]);
    }

    return 0;
}

