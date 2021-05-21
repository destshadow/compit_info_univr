#include <stdio.h>

struct string {
    char stringa[50];
    int size_attuale;
};

typedef struct string stringt_;


void Rimepi(stringt_ *array){
    int i = 0;
    char a;
    do{
        a = getchar();
        if(a != '\n' || a == " "){
            array->stringa[i++] = a;
        }
    }while (a != '\n');
    array->stringa[i] = '\0';

}


int main(){
    stringt_ *array;

    Rimepi(array);
    
    printf("%s", array->stringa);
    
}