#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(){
	
	srand(time(NULL));
	int j = rand() % (3);
	
	printf("%d", j);
	
	return 0;
}