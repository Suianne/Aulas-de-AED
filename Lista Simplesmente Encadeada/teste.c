#include <stdio.h>
#include "listase.h"

int main(){
	tp_listase *lista;
	lista = inicializa_listase();
	
	insere_listase_no_fim(&lista, 10);
	insere_listase_no_fim(&lista, 20);
	insere_listase_no_fim(&lista, 30);
	
	imprime_listase(lista);
	
	remove_listase(&lista, 40);
	remove_listase(&lista, 20);
	remove_listase(&lista, 10);
	
	imprime_listase(lista);
	
	return 0;
}