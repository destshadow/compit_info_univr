#include <stdio.h>

#define STRING_S 5
#define PROVA 5
#define N 50

//creo struttura di tipo stringa
struct string {
    char stringa[STRING_S + STRING_S];
};

//definisco struct string come stringt_
typedef struct string stringt_;

//creo la struttura My_String
struct My_String{
    stringt_ My_String[PROVA];
};

//definisco struct My_String come My_String_t
typedef struct My_String My_String_t;

//creo la funzione My_atoi simile ad atoi nella libreria
int My_atoi(char *str){
    int res = 0;

    for (int i = 0; str[i] != '\0'; ++i){
        res = res * 10 + str[i] - '0';
    }

    return res;
}

//creo la funzione per inserire dati nell'array
void Rimepi(My_String_t *array){

    for(int i = 0; i < PROVA; i++){
        scanf("%s", array->My_String[i].stringa);
    }

}

//creao una funzione che copia le stringhe da una parte all'altra
void string_cp(char dest[], char src[]){
    int i = 0;
    do{
        dest[i] = src[i];
    }while(src[i++] != '\0');
}

//creo la funzione che controlla il carattere e vedere se è un tipo valido se è 0 o > N è errato
void Sostituisci(My_String_t *array){
    int a;
    for(int i = 0; i < PROVA; i++){
        //a = atoi(array->My_String[i].stringa);
        a = My_atoi(array->My_String[i].stringa);
        //printf("%i, ", a);  debug
        if(a == 0 || a > N){
            printf("\nERRORE\n");
            //exit(-1);
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

//funzione per stampare l'array
void Stampa(My_String_t *array){
    for(int i = 0; i < PROVA; i++){
        printf("%s ", array->My_String[i].stringa);
    }
}

int main(){
    //creo variabile puntatore array di tipo My_string_t
    My_String_t *array;

    //richiamo funzioni principali
    Rimepi(array);
    Sostituisci(array);
    Stampa(array);

    return 0;
}