#include <stdio.h>
#include "listase.h"

int main(){
	tp_listase *lista, *lista2;
	lista = inicializa_listase();
	lista2 = inicializa_listase();
	
	insere_listase_no_fim(&lista, 1);
	insere_listase_no_fim(&lista, 2);
	insere_listase_no_fim(&lista, 3);
	insere_listase_no_fim(&lista, 5);
	insere_listase_no_fim(&lista, 6);
	insere_listase_no_fim(&lista, 7);


	imprime_listase(lista);
	
	printf("\n");
	
	ordemNumerica(&lista, 5);
	
	printf("\n");
	
	imprime_listase(lista);
	
	
	
	return 0;
}