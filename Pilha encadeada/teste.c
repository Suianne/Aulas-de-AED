#include <stdio.h>
#include "pilhalse.h"

int main(){
	tp_pilha *pilha;
	
	pilha = inicializa_pilha();
	
	push(pilha, 10);
	push(pilha, 20);
	push(pilha, 30);
	
	imprime_pilha(pilha);
	
	
	
	
	return 0;
}