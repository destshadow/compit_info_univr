#include <stdio.h>
#include <stdbool.h>
#define DIM 8

int main(){
    int array1[DIM];
    int array2[DIM];
    int resto = 0;
    int array3[DIM] = {0};
    

    for(int i = DIM - 1; i >= 0; i--){
        scanf("%i", &array1[i]);
    }

    printf("ciao\n");

    for (int i = DIM - 1; i >= 0; i--){
        scanf(" %i", &array2[i]);
    }

    for(int i = 0; i < DIM; i++){
        if(array1[i] != 0 && array1[i] != 1){
            return 0;
        }
        if(array2[i] != 0 && array2[i] != 1){
            return 0;
        }
    }

    for(int i = DIM; i > 0; i--){
        if(array2[i] == 1 && array2[i] == 1){
            array3[i] = 0;
            resto++;
        }
        array3[i] = array1[i] + array2[i] + resto;
    }

    for(int i = 0; i < DIM; i++){
        printf("%i ", array3[i]);
    }
    printf("resto: %i", resto);



    return 0;
}