#include <stdio.h>
#include "fila.h"
#define number 15

int main(){
	type_line dados;
	type_item nLine, nAux;
	int n, cont=1;
	
	//inicializando a fila de dados 
	initializeLine(&dados);
	
	while(cont<=number){
		printf("Informe um numero: ");
		scanf("%d", &n);
		
		if(n%2 == 0){
			nLine = n;
			if (insertLine(&dados, nLine)){
//				printf("\nNumero inserido par inserido\n");
			} else {
				removeLine(&dados, &nAux);
				insertLine(&dados, nLine);
				
			}
		} else {
			
			if(removeLine(&dados, &nAux)){
//				printf("Numero impar informado, retiramos um impar\n");
			} else {
				printf("A fila esta vazia, nao podemos retirar nada\n");
			}
		}
		
		cont++;
	}
	
	printLine(dados);
	
	
	return 0;
}