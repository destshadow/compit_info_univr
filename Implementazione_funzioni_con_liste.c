#include <stdio.h>
#include <stdlib.h>

/*definizione della struttura per la lista concatenata*/
struct elem_{
  int num;
  struct elem_ *next;
};

struct node_t {
    char value;
    struct node_t *next;
};

struct letter_t {
    char letter;
    struct letter_t *next;
};

typedef struct elem_ elem;

/*prototipi delle funzioni*/
elem* inserisciInCoda(elem*, int);
elem* inserisciInTesta(elem*, int);
elem* inserisciOrdinato(elem*, int);
elem* rimuovi(elem*, int);
void visualizza(elem*);
elem* distruggiLista(elem*);
int esisteElemento(elem*, int);
int massimoLista(elem*);

/*inserisce un nuovo numero in coda alla lista*/
elem* inserisciInCoda(elem* lista, int num){
  elem *prec; //puntatore a tipo elem prec
  elem *tmp;  //puntatore a tipo elem tmp

  tmp = (elem*) malloc(sizeof(elem)); //alloco lo spazio per un nuovo elemento e lo salvo su tmp
	if(tmp != NULL){                    //se timp e diverso da null quindi l'allocazione di un nuovo elemento è andato a buon fine
		tmp->next = NULL;                 //il prossimo sarà null
		tmp->num = num;                   //gli do il valore attuale passatomi dalla funzione
		if(lista == NULL){                //se la lista è vuota
			lista = tmp;                    //la lista attuale(NULL) diventa tmp quindi come ultimo valore ha tmp
		}else{                            //altrimenti  (quindi ci sono elementi dentro)
		/*raggiungi il termine della lista*/
		for(prec=lista;prec->next!=NULL;prec=prec->next);   //assegno a prec la lista attuale(così scalo prec e non lista), se il prossimo di prec è diverso da null, scalo avanti
		  prec->next = tmp;                                   //per ogni iterazione successiva fino ad arrivare a null assegno a prec->next tmp
		}
    /*
      while(prev->next){     
            prev = prev->next;
        }
        prev->next = tmp;
    */
	}else
      printf("Memoria esaurita!\n");  //se tmp non è allocato ho finito la memoria
  return lista;                       //ritorno la lista con l'ultimo elemento assegnato
}

/*inserisce un nuovo numero in testa alla lista*/
elem* inserisciInTesta(elem* lista, int num){
  elem *tmp;                            //creo un puntatore tmp di elem

  tmp = (elem*) malloc(sizeof(elem));   //alloco tmp con un nuovo spazio di elem
  if(tmp != NULL){                      //se l'allocamento è andato a buon fine
    tmp->num = num;                     //il valore di tmp è num
    tmp->next = lista;                  //il prossimo di tmp è la lista
    lista = tmp;                        //l'intera lista ora è tmp
  } else
      printf("Memoria esaurita!\n");
  return lista;
}

/*inserisce un nuovo numero in testa alla lista*/
elem* inserisciOrdinato(elem* lista, int num){
  elem *tmp, *prec, *prox;

  tmp = (elem*) malloc(sizeof(elem));
  if(tmp != NULL){
    tmp->num = num;
    if(!lista){ /* lista vuota */
    	tmp->next = lista;
	    lista = tmp;    
    } else { 
    	if(tmp->num <= lista->num){ /* nuovo primo elemento della lista */
    		tmp->next = lista;
    		lista = tmp;
    	} else if (!lista->next) {
    		tmp->next = lista->next;
    		lista->next = tmp;
    	} else {
    		for(prox = lista; prox->next && tmp->num > prox->next->num; prox = prox->next)
	    		;
    		tmp->next = prox->next;
    		prox->next = tmp;
    	}
    }
  } else
      printf("Memoria esaurita!\n");
  return lista;
}

/*visualizza i numeri contenuti nella lista*/
void visualizza(elem* lista){
  while(lista != NULL){
    printf("%d ", lista->num);
    lista = lista->next;
  }
  printf("\n");  
}

/*libera la memoria allocata per una lista*/
elem* distruggiLista(elem* lista){
  elem* tmp;
  while(lista!= NULL){
    tmp = lista;
    lista = lista->next;
    free(tmp);
  }
  return NULL;
}

int esisteElemento(elem* lista, int num){
	int flag=0;
	for(;lista;lista=lista->next)
	  if(lista->num==num)
		  flag=1;
  
  return (flag);
}

elem* rimuovi(elem* lista, int num){
  elem *curr, *prec, *canc;
  int found;

  found=0;
  curr = lista;
  prec = NULL;      
  while(curr && ! found){
    if(curr->num==num){
      found=1;
      canc = curr;
      curr = curr->next;     
      if(prec!=NULL)
        prec->next = curr;
      else
        lista = curr;
      free(canc);
    }
    else{
      prec=curr;
      curr = curr->next;     
    }
  }
  return lista;

}


int massimoLista(elem* lista){
	int x;
	elem* current;
	x=0;
	
	current=lista;
	while(current!=NULL)
	{	
		if(current->num>x)
			x=current->num;
		current=current->next;	
	}
	return x;
}


//nuovo
struct node_t *create_node(char value) {
    struct node_t *new = (struct node_t *)malloc(sizeof(struct node_t));

    if (new == NULL){
		printf("Memory allocation failed\n");
		exit(EXIT_FAILURE);
	}
	
    new->value = value;
    new->next = NULL;
    return new;
}


//creo una struttura con le stringhe
struct node_t *create_list(const char *s) {
    struct node_t *head = NULL;
    struct node_t *prev;

    while (*s) {
        struct node_t *new = create_node(*s);
        //struct node_t *new = (struct node_t *) malloc(sizeof(struct node_t)); è la riga sopra ma fatta in una riga
        //new->value = *s;
        //new->next = NULL;
        if (head == NULL) {
            head = new;
        } else {
            prev->next = new;
        }
        prev = new;
        s++;
    }
    return head;
}
//stampa caratteri di un array di strutture
void print_phrase(struct letter_t *phrase[], int length, char sep) {
    
    for(int i = 0; i < length; i++){
        struct letter_t *current = phrase[i];
        
        while (current){
            printf("%c", current->letter);
            current = current->next;
        }
        printf("%c", sep);
    }
}
//creazione lista ricorsvia a = const(1,cost(2,const(3,const(NULL))));
elem *ConstructList(int head, elem *tail){
    elem *this = (elem *) malloc(sizeof(elem));
    this->num = head;
    this->next = tail;

    return this;
}


//end nuovo




int main(int argc, char* argv[]){
  int val;
  int r;
  elem* listav=NULL; 
  
  do
  {
	scanf("%d", &val);
    if(val!=-1)
    listav=inserisciInCoda(listav, val);
  }while(val!=-1);
  
  visualizza(listav);
  r=massimoLista(listav);
  printf("%d\n",r);
  
  printf("\nQuale elemento vuoi cercare?\n");
  scanf("%d", &val);
  r=esisteElemento(listav,val);
  printf("Esito %d",r);
  
  listav=distruggiLista(listav);


  return 0;
}


/*

Si completi il file ESA 13072021 A 1.c scrivendo le funzioni:
• colonna(conta) che data una matrice rettangolare 7x6 composta di soli numeri 0 e 1 restituisce l’indice della
prima colonna con la pi`u lunga sequenza di valori 1 consecutivi, −1 se nella matrice non sono presenti
valori 1.
• percorso che data una matrice rettangolare 7x6 composta di soli numeri 0 e 1 verifica se esiste una
sequenza di elementi di valore 1 adiacenti tali che si possa individuare un percorso sulla matrice dalla
prima all’ultima riga, spostandosi sempre da un elemento di valore 1 ad un altro adiacente, senza mai
tornare su righe gi`a percorse in precedenza (la funzione restituisce 1 se il percorso esiste, 0 altrimenti).
La funzione percorso sar`a valutata con un punteggio maggiore, se implementata in modo ricorsivo.
Ad esempio, se la matrice in ingresso fosse la seguente, colonna restituirebbe come indice di colonna 1 (la
colonna di indice 1 ha 4 valori 1 consecutivi e la risposta di percorso sarebbe 1 (infatti esiste anche pi`u di un
percorso di 1 adiacenti dalla prima all’ultima riga – uno di questi `e stato evidenziato in grassetto):

0 1 0 0 0 0
0 0 1 0 0 0
0 1 1 0 0 0
0 1 1 0 0 0
1 1 1 0 0 0
1 1 0 0 0 0
1 0 0 0 0 0

Se la matrice in ingresso fosse invece la seguente, colonna restituirebbe come indice di colonna 2 e la risposta
di percorso sarebbe 0 (nella seconda riga non esiste un 1 adiacente all’unico 1 della prima riga):

0 1 0 0 0 0
0 0 0 1 0 0
0 1 1 0 0 0
0 1 1 0 0 0
1 1 1 0 0 0
1 1 1 0 0 0
1 0 1 0 0 0



//prototipi
int conta(int mat[][COL]);
int percorso(int mat[][COL], int, int);



int main(void) {
  int i, M[RIGHE][COL]={{0,1,0,0,0,0},{0,0,1,0,0,0},{0,1,1,0,0,0},{0,1,1,0,0,0},{1,1,1,0,0,0},{1,1,0,0,0,0},{1,0,0,0,0,0}};
  int N[RIGHE][COL]={{0,1,0,0,0,0},{0,0,0,1,0,0},{0,1,1,0,0,0},{0,1,1,0,0,0},{1,1,1,0,0,0},{1,1,1,0,0,0},{1,0,1,0,0,0}};
  int c;
  c=conta(M);
  printf("\n Indice di colonna con maggior numero di 1 consecutivi: %d\n", c);
  i=0;
  while (i<COL && !percorso(M, 0, i))
    i++;
  if (i==COL)
    printf("Il percorso NON esiste.\n");
  else
    printf("Il percorso esiste.\n");
  
  c=conta(N);
  printf("\n Indice di colonna con maggior numero di 1 consecutivi: %d\n ", c);
  i=0;
  while (i<COL && !percorso(N, 0, i))
    i++;
  if (i==COL)
    printf("Il percorso NON esiste.\n");
  else
    printf("Il percorso esiste.\n");
  return(0); 
  
  
  return(0);
  
}

// la funzione restituisce l'indice della prima colonna con il maggior numero di 1 consecutivi, -1 se non esiste 

int conta(int mat[RIGHE][COL]){
	int i,j,maxval,max_c;
	int val;
	maxval=0;
	max_c=-1;
	for(i=0;i<COL;i++)
	{	
		j=0;
		val=0;
		while(j<RIGHE){
			while(mat[j][i]==1 && j<RIGHE){
				val++;
				j++;
			}
			if(val>maxval){
				maxval=val;
				max_c=i;
			}
			val=0;
			j++;
		}
	}
				
	return max_c;		
}


// la funzione restituisce 1 se un percorso di 1 adiacenti esiste a partire dalla riga i colonna j 
int percorso(int mat[RIGHE][COL], int i, int j) {
    int risp;

    if (mat[i][j] == 1) {
      if (i==RIGHE-1) {
        risp = 1;
      } else {
        if ((j>0 && percorso(mat, i+1, j-1)) || percorso(mat, i+1, j) || (j<COL-1 && percorso(mat, i+1, j+1)))
          risp = 1;
        else
          risp = 0;
      }
    } 
	else 
 		 risp = 0;
    
    return(risp);
}


*/