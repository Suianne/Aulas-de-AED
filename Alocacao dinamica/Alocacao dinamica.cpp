#include <stdio.h>
#include <stdlib.h>

int main(){
	
	char *pc;
	pc = (char *) malloc(1);
	*pc = '@';
	printf("...%c.", *pc);
	free(pc);
	pc = NULL;
	
	return 0;
	
	
}