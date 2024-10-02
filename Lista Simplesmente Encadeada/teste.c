#include <stdio.h>
#include "listase.h"

int main(){
	tp_listase *lista, *lista2;
	lista = inicializa_listase();
	lista2 = inicializa_listase();
	
	insere_listase_no_fim(&lista, 10);
	insere_listase_no_fim(&lista, 20);
	insere_listase_no_fim(&lista, 30);
	insere_listase_no_fim(&lista, 30);
	insere_listase_no_fim(&lista, 30);
	
	insere_listase_no_fim(&lista2, 10);
	insere_listase_no_fim(&lista2, 20);
	insere_listase_no_fim(&lista2, 40);
	insere_listase_no_fim(&lista2, 30);
	
	
	printf("\n");
	
	printf("%d", compara_listas(lista, lista2));
	
	return 0;
}