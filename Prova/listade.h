
// Nesta lista duplamente encadeada usamos um descritor (struct de nome
//tp_listad) um dado estruturado que tem como objetivo melhorar a manipulação e o acesso aos nós da lista. Este
//descritor é alocado na memória dinamicamente e possui 2 (ou 3) membros. Um ponteiro (*ini) que vai apontar para
//o primeiro nó (tp_no) da lista,
//outro ponteiro (*fim) que vai apontar para o último nó da lista e, opcionalmente, o tamanho da lista (tamanho)
// é importante difernciar as estruturas nesta biblioteca. Temos dois dados estruturados: a descritor e o nó da lista

  
#ifndef LISTADE_H
#define LISTADE_H
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

  
typedef int tp_item;

//dados estruturados que representa
typedef struct tp_no_aux{
	struct tp_no_aux *ant;
	tp_item info;
	struct tp_no_aux *prox;
}tp_no;

//dados estruturados que representam o descritor
typedef struct{
	tp_no *ini;
	tp_no *fim;
	//int tam;
}tp_listade; 

tp_listade *inicializa_listade(){
	tp_listade *lista = (tp_listade*) malloc(sizeof(tp_listade));
	lista->ini = NULL;
	lista->fim = NULL;
	//lista->tam = 0;
	return lista;
}
  
int listade_vazia(tp_listade *lista) {
  if  (lista->ini == NULL) return 1; 
  return 0;
}
  
//Aloca um nó da lista
tp_no *aloca() {
  tp_no *pt=(tp_no*) malloc(sizeof(tp_no));
  return pt;
}


int insere_listade_inicio(tp_listade *lista, tp_item e){
	tp_no *novo;
	novo = aloca();
	if (!novo) return 0;
	
	novo->info = e;
	novo->ant = NULL;
	novo->prox = lista->ini;
	lista->ini = novo;
	return 1;
}

int insere_listade(tp_listade *lista, tp_item e){
	tp_no *novo;
	novo = aloca();
	if (!novo) return 0;
	
	novo->info = e;
	novo->ant = NULL;
	
	if(listade_vazia(lista)){
		lista->ini = novo;
		lista->fim = novo;
	} else {
		novo->ant = lista->fim;
		lista->fim->prox = novo;
		lista->fim = novo;
	}
	
	//lista->tam++;
	return 1;
}

int insere_listade_meio(tp_listade *lista, tp_item e){
	tp_no *novo;
	novo = aloca();
	if (!novo) return 0;
	
	novo->info = e;
	
	tp_no *atu;
	tp_no *ant = NULL;
	int tam = 0;
	while (atu != NULL) {
        tam++;
        atu=atu->prox;
    }
    
    if(tam % 2 == 0){
    	int nTam = tam/2;
    	while (atu != NULL && nTam > 0) {
    		tam--;
        	ant = atu;
        	atu=atu->prox;
    	}
    	
    	novo->ant = ant;
    	novo->prox = atu;
    	
	} else{
		int nTam = (int) tam/2;
    	while (atu != NULL && nTam > 0) {
    		tam--;
        	ant = atu;
        	atu=atu->prox;
    	}
    	
    	novo->ant = ant;
    	novo->prox = atu;	
	}
	
	return 1;
}


//imprime os conteudos da lista (de frente para tras ou de tras pra frente)
void imprime_listade(tp_listade *lista, int ordem) {
  if (lista==NULL) {
  	printf("Lista inicializada");
  } else {
  	tp_no *atu;
  	switch (ordem) {
    	case 1: atu = lista->ini;
      	while (atu != NULL) {
        	printf("%d ", atu->info);
          	atu=atu->prox;
      		}
    		break;
    		
    	case 2: atu = lista->fim;
      	while (atu != NULL) {
        	printf("%d ", atu->info);
          	atu=atu->ant;
      		}
    		break;
    		
    	default: printf("codigo invalido");
  		}
  	}
	    
  printf("\n");
}

  
  
//Com base em um conteudo, retorna-se o endereço do nó que contém o conteudo
tp_no * busca_listade(tp_listade *lista, tp_item e){
  tp_no *atu;
  atu = lista->ini;
  while ( (atu != NULL) && (atu->info != e) ) {
    atu=atu->prox;}
    return atu;
}

  
//Retira da memória todos os nós da lista e também o descritor
tp_listade * destroi_listade (tp_listade *lista){
  tp_no *atu;
  atu = lista->ini;
  while (atu != NULL) {
    lista->ini = atu->prox;
    free(atu);
    atu=lista->ini;
  }
  free(lista);
  return NULL;
}

int insere_media(tp_listade *lista){
	int soma = 0;//variavel para guardar os infos
	int tamanho = 0;//para saber o tamanho da lista
	
	//pegando a soma dos numeros e o tamanho da lista
	if (lista==NULL) {
  		soma = 0;
  		tamanho = 0;
  	} else {
  		tp_no *atu;
    	while (atu != NULL) {
    		soma += atu->info;
    		tamanho++;
        	atu=atu->prox;
      	}
    
  	}
	
	int media;
	media = (int) soma/tamanho;
	
	//fazendo o sorteio do numero
	srand(time(NULL));
	int j = rand() % (3);
	
	//determinando as condições
	switch(j){
		case 1:
			insere_listade_inicio(lista, media);
			break;
		case 2:
			insere_listade_meio(lista, media);
			break;
		case 3:
			insere_listade(lista, media);
			break;
		default:
			return 0;
			break;
	}
	
	
	imprime_listade(lista, 1);
	return 1;
}

#endif

