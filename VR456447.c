#include <stdio.h>

int main(){
    int numero;
    int min = 0;
    int max = 0;
    int sommatore = 0;
    int iterator = 0;

    printf("inserisci i voti: ");
    scanf("%i", &numero);
    sommatore += numero;
    max = numero;
    min = numero;
    iterator++;

    if(numero < 18 || numero > 30){
        printf("\nErrore\n");
        return 0;
    }

    do{
        printf("inserisci i voti: ");
        scanf(" %i", &numero);
        if(numero < 18 || numero > 30){  //rende il while superfluo
            break;
        }
        sommatore += numero;
        if(numero > max){
            max = numero;
        }
        if(numero < min){
            min = numero;
        }
        iterator++;
    }while(numero >= 18 && numero <= 30);
    printf("media:%f \nmassimo:%i \nminimo:%i \nnumero di voti:%i\n",(float)sommatore / (float)iterator,max,min,iterator);

    return 0;
}