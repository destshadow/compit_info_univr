#include <stdio.h>
#include <stdbool.h>
#define DIM 4

int main(){
    int array1[DIM];
    int array2[DIM];
    int resto = 0;
    int array3[DIM] = {0};
    

    for(int i = DIM - 1; i >= 0; i--){
        scanf("%i", &array1[i]);
    }

    for (int i = DIM - 1; i >= 0; i--){
        scanf(" %i", &array2[i]);
    }

    for(int i = 0; i < DIM; i++){
        if(array1[i] != 0 && array1[i] != 1){
            printf("Errore nell'inserimento dei valori!\n");
            return 0;
        }
        if(array2[i] != 0 && array2[i] != 1){
            printf("Errore nell'inserimento dei valori!\n");
            return 0;
        }
    }

    for(int i = DIM - 1; i >= 0; i--){
        if(array1[i] == 1 && array2[i] == 1){
            if(resto == 0){
                array3[i] = 0;
                resto++;
            }else{
                array3[i] = 1;
                resto++;
            }
        }else{
            if(resto == 0){
                array3[i] = array1[i] + array2[i];
            }else if(array1[i] == 1 || array2[i] == 1){
                array3[i] = 1;
                resto = 0;
            }
        }
    }

    for(int i = 0; i < 7; i++){
        printf("%c", '-');
    }

    printf("\n");

    for(int i = 0; i < DIM; i++){
        printf("%i ", array3[i]);
    }

    return 0;
}