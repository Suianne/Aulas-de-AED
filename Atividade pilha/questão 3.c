#include <stdio.h>
#include "pilha.h"

int main(){
	type_stack stackOne, stackTwo;
	initializeStack(&stackOne);
	initializeStack(&stackTwo);
	
	for (type_item i = 0; i < 5; i++){
		push(&stackOne, i);
	}
	
	for(type_item i = 9; i < 14; i++){
		push(&stackTwo, i);	
	}
	
	printStack(stackOne);
	printf("\n");
	printStack(stackTwo);
	printf("\n");
	
	stackStacks(&stackOne, &stackTwo);
	
	printStack(stackOne);
	
	
	return 0;
}