#include <stdio.h>
#include <string.h>
#include "pilhachar.h"

int main(){
	type_item e;
	int correct, tam;
	char exp[1001];
	type_stack p;
	
	while(scanf("%s", &exp) != EOF){
		correct = 1; // correct está definido como verdadeiro
		initializeStack(&p); //top vira -1
		tam = strlen(exp);
		
		for (int i = 0; i < tam; i++){
			if (exp[i] == '('){
				e = exp[i];
				push(&p, e);
			}
			
			if (exp[i] == ')'){
				if (!pop(&p, &e)){
				correct = 0; //define correto como falso
				break;
				}
			}
		}
		
		if(!stackEmpty(&p) || correct==0){
			printf("incorrect\n");
		} else {
			printf("correct\n");
		}
	}
	
	
	
	
	return 0;
}