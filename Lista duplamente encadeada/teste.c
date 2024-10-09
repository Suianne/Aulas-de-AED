#include <stdio.h>
#include "listade.h"

int main(){
	tp_listade *lista;
	lista = incializa_listade();
	
	printf("%d", listade_vazia(lista));
	
	return 0;
}