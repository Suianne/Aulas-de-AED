#include <stdio.h>
#include "fila.h"

int main(){
	type_line linha;
	type_item e;
	initializeLine(&linha);
	
	if(lineEmpty(&linha)){
		printf("A fila esta vazia\n");
		insertLine(&linha, 10);
		insertLine(&linha, 20);
		insertLine(&linha, 30);
	}
	
	printLine(linha);
	printf("\n");
	inverseLine(linha);
	
	return 0;
}