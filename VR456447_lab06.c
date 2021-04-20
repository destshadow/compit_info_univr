#include <stdio.h>
#include <string.h>

void Modifica(char stringa[50], char c, char output[50]){
    int i = 0;
    int j = 0;

    while(stringa[i] != '\0'){
        if(stringa[i] == c){
            i++;
        }
        if(i < sizeof(stringa)){
            output[j] = stringa[i];
        }
        j++;
        i++;
    }

    i = 0;

    printf("Stringa = %s; Carattere da rimuovere = %c; => ", stringa, c);

    while(output[i] != '\0'){
        printf("%c", output[i++]);
    }
    printf("\n");
}

// Stringa = "allocazione"; Carattere da rimuovere = 'c'; => "alloazione"

int main(){

    char input[50];
    char carattere;
    char output[50];

    printf("Inserisci frase da modificare: ");
    scanf(" %s", input);

    printf("\nInserisci carattere da togliere: ");
    scanf(" %c", &carattere);
    
    Modifica(input, carattere, output);

    return 0;
}