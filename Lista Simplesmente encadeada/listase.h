#ifndef LISTASE_H
#define LISTASE_H

#include <stdio.h>
#include <stdlib.h>

typedef int tp_item;

typedef struct tp_no{
	tp_item info;
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
	tp_listase *novo_no, *atu;
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


void imprime_listase(tp_listase *lista){
	tp_listase *atu;
	atu=lista;
	
	while(atu!=NULL){
		printf("%d\n", atu->info);
		atu=atu->prox;
	}
}

int remove_listase(tp_listase **lista, tp_item e){
	tp_listase *ant, *atu;
	atu = *lista;
	ant = NULL;
	while((atu!=NULL)&&(atu->info != e)){
		ant = atu;
		atu = atu->prox;
	}
	
	if(atu==NULL) return 0; //nao foi encontrado o elemento
	if(ant==NULL){ ///se for retirado o primeiro termo
		*lista=atu->prox; //fazendo a lista apontar para o termo
	} else {
		ant->prox = atu->prox; 
	}
	
	
	free(atu);
	atu=NULL;
	return 1;
}

tp_listase *busca_listase(tp_listase *lista, tp_item e){
	tp_listase *atu;
	atu=lista;
	while((atu != NULL)&&(atu->info != e)){
		atu=atu->prox;
	}
	if (atu==NULL) return NULL;
	return atu;
}

int tamanho_listase(tp_listase *lista){
	int cont=0;
	tp_listase *atu;
	atu=lista;
	
	while(atu!=NULL){
		cont++;
		atu=atu->prox;
	}
	
	return cont;
}

void destroi_listase(tp_listase **l){
	tp_listase *atu;
	atu=*l;
	while(atu!=NULL){
		*l=atu->prox;
		free(atu);
		atu=*l;
	}
	
	*l=NULL;
}

int qtd_nos_maiores(tp_listase *l, tp_item e){
	int cont=0;
	tp_listase *atu;
	atu=l;
	
	while(atu!=NULL){
		if(atu->info > e){
			cont++;
		}
		
		atu=atu->prox;
	}
	
	return cont;
}

int compara_listas(tp_listase *l, tp_listase *l2){
	if(tamanho_listase(l) != tamanho_listase(l2)) return 0;
	
	tp_listase *atu, *atu2;
	atu=l;
	atu2=l2;
	
	while(atu!=NULL){
		if(atu->info != atu2->info){
			return 0;
		}
		
		atu=atu->prox;
		atu2=atu2->prox;
	}
	
	return 1;
}

int ordemNumerica(tp_listase **l, tp_item e){
	tp_listase *atu, *ant, *novo_no;
	atu=*l;
	ant = NULL;
	
	novo_no = aloca_listase();
	
	if(novo_no == NULL){
		return -1;
	}
	
	novo_no->info = e;
	
	while((atu!=NULL)&&(atu->info <= e)){
		ant = atu;
		atu = atu->prox;
	}
	
	if(ant==NULL){
		novo_no->prox = *l;
		*l = novo_no;
	} else {
		ant->prox = novo_no;
		novo_no->prox = atu;
	}
	
	return 0;
	
	
}

void destroi_impares(tp_listase **l){
	tp_listase *atu, *ant, *temp; //o temp vai guardar o ponteiro temporário para eu poder dar free nele depois
	atu=*l;
	ant=NULL;
	
	
	while((atu!=NULL)){
		if(atu->info % 2 != 0){
			if(ant==NULL){ //quando esse for o primeiro nó da lista
				temp=atu;
				*l=atu->prox;
				atu=atu->prox;
				free(temp);
			} else{
				ant->prox = atu->prox;
				temp = atu;
				atu=atu->prox;
				free(temp);
			}
		} else {
			ant = atu;
			atu = atu->prox;
		}
	}
	
}

void juntar_listas(tp_listase *l1, tp_listase *l2, int tam){
	tp_listase *atu;
	atu = l1;
	int cont=0;
	
	while (atu->prox!=NULL){
		atu=atu->prox;
	}
	
	atu->prox=l2;
	
	atu=l2;
	
	while(atu->prox!=NULL){
		atu=atu->prox;
	}
	
	atu->prox=l1;
	
	atu=l1;
	
	while((cont<tam)&&(atu->prox!=NULL)){
		printf("%d\n", atu->info);
		atu=atu->prox;
		cont++;
	}
	
}




#endif
