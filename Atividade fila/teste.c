#include <stdio.h>
#include "fila.h"

int main(){
	type_line line;
	type_item e;
	initializeLine(&line);
	
	if(lineEmpty(&line)){
		printf("A fila esta vazia\n");
		insertLine(&line, 10);
		insertLine(&line, 20);
		insertLine(&line, 30);
	}
	
	printStack(line);
	
	int tam = (lenghtLine(&line) - 1);
	
	for (int i = 0; i < tam; i++){
		removeLine(&line, &e);
	}
	
	
	printf("\nDepois de remover, esse elemento sobrou:\n");
	printStack(line);
		
	return 0;
}