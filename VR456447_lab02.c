#include <stdio.h>
#include <stdbool.h>
#define DIM 8

int main(){
    int array1[DIM];
    int array2[DIM];
    

    for(int i = DIM - 1; i >= 0; i--){
        scanf("%i", &array1[i]);
    }

    printf("ciao\n");

    for (int i = DIM - 1; i >= 0; i--){
        scanf(" %i", &array2[i]);
    }

    for(int i = 0; i < DIM; i++){
        if(array1[i] != 0 || array1[i] != 1){
            return 0;
        }
        if(array2[i] != 0 || array2[i] != 1){
            return 0;
        }
    }




    return 0;
}