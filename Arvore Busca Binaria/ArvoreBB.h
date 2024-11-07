#ifndef ARVOREBB_H
#define ARVOREBB_H
#include <stdio.h>
#include <stdlib.h>


typedef int tp_item_a;

typedef struct tp_no{
	struct tp_no *esq;
	tp_item_a info;
	struct tp_no *dir;
} tp_no;

typedef tp_no * tp_arvore;

tp_arvore incializa_arvore(){
	return NULL;
}

int arvore_vazia(tp_arvore raiz){
	if(raiz == NULL) return 1;
	else return 0;
}

tp_no *aloca_no(){
	
	tp_no *no;
	no = (tp_no*) malloc(sizeof(tp_no));
	return no;
	
}

int insere_no(tp_arvore *raiz, tp_item e){
	tp_no *pai=NULL, *novo, *p=*raiz;
	novo = aloca_no();
	if(!novo) 
		return 0;
	
	novo->info = e;
	novo->dir = NULL;
	novo->esq = NULL;
	
	while(p != NULL){
		pai=p;
		
		if(e < p->info){
			p=p->esq;
		} else {
			p=p->dir;
		}
	}
	
	if(pai != NULL){
		
		if(e < pai->info){
			pai->esq = novo;
		} else {
			pai->dir = novo;
		}
	}
	
	else
		*raiz = novo;
	
	
	return 1;
}

//função de percurso
void pre_ordem(tp_no *p){
	
	if(p != NULL){
		printf("\n%d\n", p->info);
		pre_ordem(p->esq);
		pre_ordem(p->dir);
	}
	
}

//função de percurso
void em_ordem(tp_no *p){
	if(p != NULL){
		em_ordem(p->esq);
		printf("\n%d\n", p->info);
		em_ordem(p->dir);
	}
}

//função de percurso
void pos_ordem(tp_no *p){
	if(p != NULL){
		pos_ordem(p->esq);
		pos_ordem(p->dir);
		pos_ordem("\n%d\n", p->info);
	}
}

tp_no* busca_no (tp_no *p, tp_item e){
	while(p != NULL){
		if(e < p->info){
			p = p->esq;
		} else  {
			if(e > p->info){
				p = p->dir;
			} else{
				return p;
				}
			}
		}
		
		return NULL;
	}
	
int nivel_arvore(tp_arvore raiz){
	if(raiz == NULL) return 0;
	int nivel_esq = nivel_arvore(raiz->esq);
	int nivel_dir = nivel_arvore(raiz->dir);
	
	if(alt_esq > alt_dir){
		return nivel_esq + 1;
	} else {
		return nivel_dir + 1;
	}
}

int altura_arvore(tp_arvore raiz){
	return nivel_arvore(raiz) - 1;
}

tp_no* busca_no_rec(tp_no *p, tp_item e){
	
	if(p == NULL || p->info == e){//passo base 
		return p;
	} else {//passo recursivo
		if(e < p->info){
			return busca_no_rec(p->esq, e);
		} else if (e > p->info){
			return busca_no_rec(p->dir, e);
		}
	}
	
}	

//fila de ponteiros tipo no
/***** Fila *****/

typedef struct tp_fila {
	tp_no *no;
	struct tp_fila *prox;	
} tp_fila;

tp_fila * inicia_fila() {
	return NULL;
}

int fila_vazia(tp_fila **fila) {
	if(*fila == NULL) return 1;
	return 0;
}

tp_fila * aloca_fila(tp_no *no) {
	tp_fila *no_fila = (tp_fila*) malloc(sizeof(tp_fila));
	no_fila->no = no;
	no_fila->prox = NULL;
	return no_fila;
}

int insere_fila(tp_fila **fila, tp_no *no) {
	tp_fila *no_fila = aloca_fila(no), *atu = *fila;
	if(no_fila == NULL) return 0;
	
	if(fila_vazia(fila)) *fila = no_fila;
	else {
		while(atu->prox != NULL) {
			atu = atu->prox;
		}
		atu->prox = no_fila;
	}
	return 1;
}

tp_no * remove_fila(tp_fila **fila) {
	tp_fila *atu = *fila;
	*fila = atu->prox;
	tp_no *no = atu->no;
	free(atu);
	atu = NULL;
	return no;
}

void imprime_fila(tp_fila **fila) {
	tp_fila *atu = *fila;
	while(atu != NULL) {
		printf("%d ", atu->no->info);
		atu = atu->prox;
	}
	printf("\n");
}

void destroi_fila(tp_fila **fila) {
	tp_fila *atu = *fila;
	while(atu != NULL) {
		*fila = atu->prox;
		free(atu);
		atu = *fila;
	}
	*fila = NULL;
}




#endif