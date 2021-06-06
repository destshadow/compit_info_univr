#include <stdio.h>
#define pesate 5

void Menu(){
    printf("1) Quale pezzo pesare\n");
    printf("2) Storico Pesate\n");
    printf("0) Esci\n");
}

struct Storico{
    int Peso;
    struct Storico *tail;
};

typedef struct Storico Storico_t;

void Pesa(){
    static int N_pesate = 0;
}

int main(){
    int option;
    Storico_t s;

    do{
        Menu();
        scanf("%i", &option);

    } while (option != 0);

    return 0;
}