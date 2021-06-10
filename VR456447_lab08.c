#include <stdio.h>
#include <stdlib.h>

const int PESATE_MAX = 5;

struct Auto{
    float peso;
    struct Auto *next;
};

typedef struct Auto Auto_t;

Auto_t *Pesa(Auto_t *s,float valore){
    static int pesate_avvenute = 0;
    Auto_t *prec;
    Auto_t *tmp;

    tmp = (Auto_t*)malloc(sizeof(Auto_t*));
    if(tmp != NULL && pesate_avvenute <= PESATE_MAX){
        tmp->next = NULL;
        tmp->peso = valore;
        if( s == NULL){
            s = tmp;                //se la lista è al primo valore (NULL) gli assegno tmp ovvero il nuovo primo valore
        }else{
            for(prec = s; prec->next != NULL; prec=prec->next){     //raggiungo il penultimo valore e assegno al valore dopo tmp;
                prec->next = tmp;
            }
        }
    }else{
        printf("\nMemoria esaurita\n");
    }
    return s;
}

void Storico(Auto_t *s){
    while (s != NULL){
        printf("%.2lf Kili\n", s->peso);
        s = s->next;
    }
    //printf("\n");
}

void Menu(){
    printf("\n1) Pesa\n");
    printf("2) Storico\n");
    printf("0) Arrivederci\n");
    printf(":");
}

int main(){
    Auto_t *prova;
    prova = NULL;
    int opzione;
    int opzione2;
    float valore;
    do{
        Menu();
        scanf("%i", &opzione);
        switch (opzione){ 
            case 1:
                    printf("\nPesa cosa? (1 = gomma, 2 = paraurti, 3 = specchietto)\n");
                    scanf("%i", &opzione2);
                    switch (opzione){
                        case 1:
                            valore = 1;
                        break;
                        case 2:
                            valore = 2;
                        break;
                        case 3:
                            valore = 3;
                        break;
                        default:
                            printf("\nRitenta!\n");
                        break;
                    }
                    prova = Pesa(prova, valore);
            break;
            case 2:
                printf("\nPesate finora:\n");
                Storico(prova);
            break;
            case 0:
                printf("\nArrivederci\n");
            break;
            default:
                printf("\nErrore!\n");
            break;
        }
    }while (opzione != 0);
    

    return 0;
}