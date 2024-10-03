#include <stdio.h>
#include <string.h>
#include "fila.h"
#include "pilha.h"

int main(){
	char exp[30];
	
	printf("Informe a expressao: ");
	scanf(" %s", &exp);
	
	int len = strlen(exp);
	
	expression(exp, len);
	
	printf("%d", expression(exp, len));
		
	return 0;
}