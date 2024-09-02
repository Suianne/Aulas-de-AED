#include <stdio.h>
#include <string.h>
#include "pilhachar.h"

int main(){
	char exp[1001];
	int n, diamantes=0, tam;
	type_stack p;
	type_item e;
	
	scanf("%d", &n);
	
	for (int i = 1; i <= n; i++){
		initializeStack(&p);
		scanf(" %s", &exp);
		tam = strlen(exp);
		diamantes=0;
		
		for (int j = 0; j < tam; j++){
			if (exp[j] == '<'){
				push(&p, exp[i]);
			}
			if(exp[j] == '<'){
				if(pop(&p,&e)){
					diamantes++;
				}
			}
		}
		printf("\n %d\n", diamantes);
	}
	
	
	return 0;
}