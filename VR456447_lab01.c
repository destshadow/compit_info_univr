#include <stdio.h>

int main(){
    //dichiarazione delle variabili
    int numero;
    int min;
    int max;
    int sommatore = 0;
    int iterator = 0;

    //inserisco il primo voto e controllo che i parametri siano corretti
    //inizializzo il massimo e il minimo
    printf("inserisci i voti: ");
    scanf("%i", &numero);
    sommatore += numero;
    max = numero;
    min = numero;
    iterator++;

    if(numero < 18 || numero > 30){
        printf("\nErrore\n");
        return 0; // faccio terminare il programma se il primo numero inserito non è corretto
    }

    do{
        printf("inserisci i voti: ");
        scanf(" %i", &numero);
        if(numero < 18 || numero > 30) { //condizione che fa finire il ciclo
            break;
        }
        sommatore += numero;  //sommo tutti i voti
        if(numero > max){  //controllo il massimo
            max = numero;
        }
        if(numero < min){ //controllo il minimo
            min = numero;
        }
        iterator++;
    }while(1); //loop infinito

    //print stato voti
    printf("media:%.2f \nmassimo:%i \nminimo:%i \nnumero di voti:%i\n",(float)sommatore / (float)iterator,max,min,iterator);

    return 0;
}