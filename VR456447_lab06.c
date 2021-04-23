#include <stdio.h>
#include <string.h>

void Modifica(char stringa[50], char c, char output[50]){
    int i = 0;
    int j = 0;

    for(int x = 0; x < strlen(stringa); x++){
        //printf("%c",stringa[x]);
        if(stringa[x] == c){
            //se la stringa supera o è uguale a questi paramentri la interrompo
            if(stringa[x] == '\0'){
                break;
            }
            if(x > strlen(stringa)){
                break;
            }
            
        }else{
            output[j++] = stringa[x];  // faccio j++ solo quando inserisco il carattere e non sempre senno la stringa è errata
        }
    }

    output[j] = '\0';  // devo aggiungere il carattere di terminazione della stringa alla fine

    printf("\nStringa = %s; Carattere da rimuovere = %c; => ", stringa, c);


    while(output[i] != '\0'){
        printf("%c", output[i++]);
    }
    printf("\n");
}

int main(){
    //dichiarazione delle variabili
    char input[50] = "pazzo";
    char carattere;
    char output[50];

    //input[] = "pazzo";          // non posso assegnare una stringa ad un array dopo la dichiarazione
                                  // non supporta l'assegnamento dopo che è stato dichiaratp
   

    carattere = 'z';
    Modifica(input, carattere, output);

    printf("Inserisci frase da modificare: ");
    scanf(" %50s", input);
    //assegnamento variabili
    printf("\nInserisci carattere da togliere: ");
    scanf(" %c", &carattere);

    Modifica(input, carattere, output);

    return 0;
}
