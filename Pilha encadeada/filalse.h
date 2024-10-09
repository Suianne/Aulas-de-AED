#ifndef FILALSE_H
#define FILALSE_H
#include <stdio.h>
#include <stdlib.h>

typedef int tp_item;

typedef struct tp_no_aux {
	tp_item info;
	struct tp_no_aux *prox;
} tp_no;

typedef struct {//criação do cabeçalho da fila, que vai ajudar a controlar
	tp_no *ini, *fim;
	
}tp_fila;

tp_fila *inicializa_fila(){ //inicializa a fila, fazendo com inicio e fim seja iguais, apontando para nulo
	tp_fila *fila = (tp_fila *) malloc(sizeof(tp_fila));
	fila->ini=fila->fim = NULL;
	return fila;
}

tp_no *aloca(){ //aloca o no para a fila de forma dinâmica
	tp_no *pt = (tp_no *) malloc(sizeof(tp_no));
	return pt;
}

int fila_vazia(tp_fila *fila){
	if(fila->ini == NULL && fila->fim == NULL) return 1; //a fila está vazia, porque inicio e fim não apontam para nós
	return 0;
}

int insere_fila(tp_fila *fila, tp_item e){//função que insere elemento da fila no fim, assim como a mecânica da fila estática

	tp_no *novo;
	novo = aloca();
	
	//verificar se conseguiu alocar 
	if(!novo) return 0;
	
	//povoando o nó da fila
	novo->info = e;
	novo->prox = NULL;
	
	//verificando se fila está vazia ou não, para fazer os diferentes tipos de inserção
	if(fila_vazia(fila)){
		fila->ini = novo; //se for o primeiro nó, o ini aponta para ele
	} else {
		fila->fim->prox = novo; //se for um segundo nó, ou quarto... enfim, ele se torna o próximo do elemnto anterior que era apontado pelo fim
	}
	
	fila->fim=novo; //de qualquer forma, o novo enderço de memória é apontado por fim
	return 1;
	
}

int remove_fila(tp_fila *fila, tp_item *e){
	tp_no *novo, *aux;
	novo = aloca();
	
	if(fila_vazia(fila)) return 0;
	
	*e=fila->ini->info;
	aux=fila->ini;
	
	if(fila->ini == fila->fim){ //se esse for o único nó da lista, ini e fim tem que ser manipulados de um jeito diferente
		fila->ini=fila->fim=NULL;
	} else {
		fila->ini=fila->ini->prox; //como o nó que está sendo retirado é o primeiro, é preciso que o próximo apontado pelo início seja o novo nó
	}
	
	free(aux);
	return 1;
}

tp_fila *destroi_fila(tp_fila *fila){
	tp_no *atu = fila->ini;
	tp_item e;
	
	while(atu!=NULL){
		remove_fila(fila, &e);
		atu=atu->prox;
		
	}
	
	fila->ini=fila->fim=NULL;
	free(fila);
	return NULL;
}

void imprime_fila(tp_fila *fila){
	tp_fila *fila_aux; //criação de uma fila auxiliar
	tp_item e;
	
	// inicialização da fila auxiliar
	fila = inicializa_fila();
	
	while(!fila_vazia(fila)){
		remove_fila(fila, &e);
		printf("%d ", e);
		insere_fila(fila_aux, e);
	}
	
	fila->ini = fila_aux->ini;
	fila->fim = fila_aux->fim;
	fila_aux->ini = NULL;
	fila_aux->fim = NULL;
	fila_aux = destroi_fila(fila_aux);
	printf("\n");
	
}