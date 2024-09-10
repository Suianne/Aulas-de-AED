#include <stdio.h>
#include "fila.h"
#include "pilha.h"

int main (){
	type_line train;
	type_item e;
	
	initializeLine(&train);
	
	insertLine(&train, 1);
	insertLine(&train, 2);
	insertLine(&train, 2);
	insertLine(&train, 1);
	insertLine(&train, 3);
	insertLine(&train, 1);
	insertLine(&train, 3);
	insertLine(&train, 2);
	
	printf("A fila antes da alteracao: ");
	
	printLine(train);
	
	organizeTrain(&train);
	
	printf("A fila depois da alteracao: ");
	
	printLine(train);
	
	
	return 0;
}