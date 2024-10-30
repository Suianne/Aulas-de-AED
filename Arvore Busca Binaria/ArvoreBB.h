#ifndef AROVREBB_H
#define ARVOREBB_H
#include <stdio.h>

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

#endif