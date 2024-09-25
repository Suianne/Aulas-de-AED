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

#endif
