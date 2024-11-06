#ifndef AROVREBB_H
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

void pre_ordem(tp_no *p){
	
	if(p != NULL){
		printf("\n%d\n", p->info);
		pre_ordem(p->esq);
		pre_ordem(p->dir);
	}
	
}

void ordem(tp_no *p){
	if(p != NULL){
		ordem(p->esq);
		printf("\n%d\n", p->info);
		ordem(p->dir);
	}
}

void pos_ordem(tp_no *p){
	if(p != NULL){
		pos_ordem(p->esq);
		pos_ordem(p->dir);
		pos_ordem("\n%d\n", p->info);
	}
}
#endif