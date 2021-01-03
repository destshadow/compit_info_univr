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
        printf("\n");
    }

    //calcolo del valore massimo inserito
    for(int i = 0; i < DIM; i++){
        if(array[i] > max){
            max = array[i];
        }
    }
    //dichiarazione di una matrice con righe pari a DIM e colonne pari al massimo valore inserito nell'array
    char matrix[DIM][max];

    /*se il valore nell'array in posizione i e' minore del valore di j assegna alla matrice il carattere vuoto/spazio -> ' ',
    se invece il valore nell'array in posizione i e' maggiore di j allora assegno il carattere asterisco -> '*' */
    for(int i = 0; i < DIM; i++){
        for(int j = 0; j < max; j++){
            if(array[i] <= j){
                matrix[i][j] = ' ';
            }else{
                matrix[i][j] = '*';
            }
        }
    }
    //stampa della matrice specchiata
    for (int i = DIM-1; i >= 0; i--){
        for (int j = 0; j < max; j++){
            printf("%c ", matrix[j][i]);
        }
        printf("\n");
    }
    //stampa dei valori nell'array
    for(int i = 0; i < DIM; i++){
        printf("%i ", array[i]);
    }

    return 0;
}