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
  elem *prec;
  elem *tmp;

  tmp = (elem*) malloc(sizeof(elem));
	if(tmp != NULL){
		tmp->next = NULL;
		tmp->num = num;
		if(lista == NULL){
			lista = tmp;
		}else{
		/*raggiungi il termine della lista*/
		for(prec=lista;prec->next!=NULL;prec=prec->next);
		prec->next = tmp;
		}
	}else
      printf("Memoria esaurita!\n");
  return lista;
}

/*inserisce un nuovo numero in testa alla lista*/
elem* inserisciInTesta(elem* lista, int num){
  elem *tmp;

  tmp = (elem*) malloc(sizeof(elem));
  if(tmp != NULL){
    tmp->num = num;
    tmp->next = lista;
    lista = tmp;    
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



struct node_t *create_list(const char *s) {
    struct node_t *head = NULL;
    struct node_t *prev;

    while (*s) {
        struct node_t *new = create_node(*s);

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