#ifndef "PILHALSE_H"
#define "PILHALSE_H"
#include <stdio.h>
#include <stdlib.h>

typedef int tp_item;

typedef struct tp_no_aux {
	
	tp_item info;
	struct tp_no_aux *prox;
	
}tp_no; 

typedef struct {
	tp_no *topo; //a variável que vai ajudar a manipular a pilha na mesma mecânica da pilha estática
}tp_pilha;

tp_pilha *inicializa_pilha (){
	tp_pilha pilha = (tp_pilha) malloc(sizeof(tp_pilha));
	pilha->topo = NULL;
	return pilha;
}

