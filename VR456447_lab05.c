#include <stdio.h>

#define MAX_STR 30
#define MAX_TRG 7
#define MAX_AUTO_CONCE 50
        
typedef struct automobile {
    char modello[MAX_STR + 1];
    char targa[MAX_TRG + 1];
    int  mese_immatricolazione;
    int  anno_immatricolazione;
} auto_t;

typedef struct persona {
    char piva[MAX_STR + 1];
    char nome[MAX_STR + 1];
    char cognome[MAX_STR + 1];
} persona_t;

typedef struct concessionario{
    int codice_concessionario;
    persona_t gestore;
    auto_t automobili[MAX_AUTO_CONCE];    
    int num_auto; // Numero auto inizializzate nel array automobili. 
} concessionario_t;

void Stampa(concessionario_t array[], int dim){
    for(int i = 0; i < dim; i++){
        printf("Conc. %i, codice %i: gestore %s %s", i, array[i].codice_concessionario, array[i].gestore.nome, array[i].gestore.cognome);
        for(int j = 0; j < array[i].num_auto; j++){
            if(array[i].automobili[j].anno_immatricolazione == 2015){
                printf("\n");
                printf("Immatricolazioni 2015:\n");
                printf("mese %i: %s, %s\n", array[i].automobili[j].mese_immatricolazione, array[i].automobili[j].modello, array[i].automobili[j].targa);
            }
        }
        printf("\n");
    }

}

int main(){
    concessionario_t a[2];

    a[0].codice_concessionario = 12345;
    a[0].gestore.nome[MAX_STR + 1] = "Paolo";
    a[0].gestore.cognome[MAX_STR + 1] = "Rossi";
    a[0].num_auto = 3;

    a[0].automobili[0].anno_immatricolazione = 2015;
    a[0].automobili[0].mese_immatricolazione = 9;
    a[0].automobili[0].modello[MAX_STR + 1] = "Punto";
    a[0].automobili[0].targa[MAX_TRG + 1] = "MI80980";

    a[0].automobili[1].anno_immatricolazione = 2015;
    a[0].automobili[1].mese_immatricolazione = 6;
    a[0].automobili[1].modello[MAX_STR + 1] = "Marea";
    a[0].automobili[1].targa[MAX_TRG + 1] = "TO12567";

    a[0].automobili[2].anno_immatricolazione = 2013;
    a[0].automobili[2].targa[MAX_TRG + 1] = "B00B666";
    a[0].automobili[2].mese_immatricolazione = 6;
    a[0].automobili[2].modello[MAX_STR + 1] = "Sium";

    a[1].codice_concessionario = 23456;
    a[1].gestore.nome[MAX_STR + 1] = "Luca";
    a[1].gestore.cognome[MAX_STR + 1] = "Bianchi";
    a[1].num_auto = 1;

    a[1].automobili[0].anno_immatricolazione = 2015;
    a[1].automobili[0].mese_immatricolazione = 2;
    a[1].automobili[0].modello[MAX_STR + 1] = "Panda";
    a[1].automobili[0].targa[MAX_TRG + 1] = "VE85980";

    printf("%s \n", a[0].gestore.nome);

    Stampa(a,2);

    return 0;
}