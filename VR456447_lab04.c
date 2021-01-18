/*
Sottoprogramma 1: riceve come parametro una matrice quadrata NxN (con N definito staticamente, ma ipotizzando che potrebbe cambiare) di caratteri, di cui individuarne il carattere che compare con maggiore frequenza e lo restituisce (in caso di molteplici caratteri, si tenga il primo trovato);

Sottoprogramma 2: riceve come parametri un carattere e una matrice quadrata NxN di caratteri, visualizzando su terminale la stessa matrice però con uno spazio al posto di tutti i caratteri uguali al carattere passato come parametro;

In fine si scriva un programma main che, utilizzando i sottoprogrammi 1 e 2, individua il carattere che compare più frequentemente in una matrice NxN di caratteri, riempita dall'utente, per poi stamparla a schermo mostrando però uno spazio al posto dei caratteri uguali al carattere individuato.

*/

#include <stdio.h>
#define DIM 5

//riempio la matrice con i caratteri in input

void Riempi(char matrix[][DIM]){      //parametri formali
    for(int i = 0; i < DIM; i++){     //ROW
        for(int j = 0; j < DIM; j++){ //COL
            scanf(" %c", &matrix[i][j]);  //se non funziona e' perchè si creano errori nel buffer della tastiera per questo metto lo spazio prima di %c
        }
    }
}

//stampo la matrice

void Stampa(char matrix[][DIM]){
    for (int i = 0; i < DIM; i++){ //ROW
        for (int j = 0; j < DIM; j++){ //COL
            printf("%c", matrix[i][j]);
        }
        printf("\n");
    }
}

//riordino l'array

void BubbleSort(int array[]){
    int tmp = 0;
    for(int i = 0; i < DIM * DIM; i++){
        for(int j = 0; j < ((DIM * DIM) - 1); j++){
            if(array[j] > array[j + 1]){
                tmp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = tmp;
            }
        }
    }
}

//trovo la moda

char TrovaMax(char matrix[][DIM]){
    int array[DIM * DIM] = {0};     //creo un array di dimenzione DIM * DIM
    int index = 0;

    for(int i = 0; i < DIM; i++){
        for(int j = 0; j < DIM; j++){
            array[index] = matrix[i][j];
            index++;
        }
    }

    BubbleSort(array);
    int temp = 0;
    int tempCount; 
    int count = 1;
    int popular;

    for(int i = 0; i < DIM * DIM; i++){
        tempCount = 0;
        temp = array[i];
        tempCount++;
        for (int j = i + 1; j < DIM * DIM; j++){
            if (array[j] == temp){
                tempCount++;
                if (tempCount > count)
                {
                    popular = temp;
                    count = tempCount;
                }
            }
        }
    }
    return popular;
}

//stampo la matrice senza il carattere

void StampaSenzaValore(char matrix[][DIM], int valore){
    for(int i = 0; i < DIM; i++){
        for(int j = 0; j < DIM; j++){
            if(matrix[i][j] == valore){
                matrix[i][j] = ' ';
            }
        }
    }
    Stampa(matrix);
}

//main in cui richiamo le funzioni principali
int main(){
    char matrix[DIM][DIM];
    int valore;

    Riempi(matrix);     //parametri attuali
    printf("\n");
    //Stampa(matrix);
    valore = TrovaMax(matrix);
    StampaSenzaValore(matrix, valore);

    return 0;
}