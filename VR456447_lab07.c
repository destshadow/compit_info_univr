#include <stdio.h>
#include <stdlib.h>

#define STRING_S 5
#define PROVA 50
#define N 50

struct string {
    char stringa[STRING_S + STRING_S];
};

typedef struct string stringt_;

struct My_String{
    stringt_ My_String[PROVA];
};

typedef struct My_String My_String_t;



void Rimepi(My_String_t *array){

    for(int i = 0; i < PROVA; i++){
        scanf("%s", array->My_String[i].stringa);
    }

}

void string_cp(char dest[], char src[]){
    int i = 0;
    do{
        dest[i] = src[i];
    }while(src[i++] != '\0');
}

void Sostituisci(My_String_t *array){
    int a;
    for(int i = 0; i < PROVA; i++){
        a = atoi(array->My_String[i].stringa);
        //printf("%i, ", a);  debug
        if(a == 0 || a > N){
            printf("\nERRORE\n");
            exit(-1);
        }
        if(a % 3 == 0){
            //array->My_String[i].stringa = "CIP\0";
            string_cp(array->My_String[i].stringa, "CIP\0");
        }
        if(a % 7 == 0){
            //array->My_String[i].stringa = "CIOP\0";
            string_cp(array->My_String[i].stringa, "CIOP\0");
        }

        if(a % 3 == 0 && a % 7 == 0){
            //array->My_String[i].stringa = "CIPCIOP\0";
            string_cp(array->My_String[i].stringa, "CIPCIOP\0");
        }
    }
}

void Stampa(My_String_t *array){
    for(int i = 0; i < PROVA; i++){
        printf("%s ", array->My_String[i].stringa);
    }
}

int main(){
    My_String_t *array;

    Rimepi(array);
    Sostituisci(array);
    Stampa(array);

    return 0;
}