#ifndef LISTASE_H
#define LISTASE_H

#include <stdio.h>
#include <stdlib.h>

typedef int tp_list_item;

typedef struct tp_no{
	tp_list_item info;
	struct tp_no *prox;
}tp_listase;

tp_listase * inicializa_listase(){
		return NULL;
}

int listase_vazia (tp_listase *lista){
	if(lista==NULL) return 1;
	return 0;
}

tp_listase * aloca_listase(){
	tp_listase *novo_no;
	novo_no = (tp_listase *) malloc(sizeof(tp_listase));
	return novo_no;
}

int insere_listase_no_fim(tp_listase **l, tp_item e){
	tp_listase novo_no, atu;
	novo_no = aloca_listase(); //aqui está pegando o novo nó e apontando para o fim
	
	//atribuição dos valores para o novo nó
	novo_no->info = e;
	novo_no->prox=NULL;
	
	//finaliza o encadeamento do nó
	
	if(listase_vazia(*l)){ //se for o primeiro nó entra aqui
		*l=novo_no;
	} else {
		atu = *l;
		while(atu->prox!=NULL){
			atu = atu->prox;
		}
		
		atu->prox = novo_no;
	}
	
	return 1;
}

#endif


