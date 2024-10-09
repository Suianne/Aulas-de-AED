#include <stdio.h>
#include "filalse.h"

int main(){
	tp_fila *fila;
	
	fila = inicializa_fila();
	
	insere_fila(fila, 10);
	insere_fila(fila, 20);
	insere_fila(fila, 30);
	insere_fila(fila, 40);
	
	imprime_fila(fila);
	
	
	return 0;
}