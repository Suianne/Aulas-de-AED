#include <stdio.h>

int fibonacci(int n){
	
	if (n == 1 || n == 2){
		return 1;
	} else {
		return fibonacci(n-2) + fibonacci(n-1);
		
	}
}

int main(){
	int n;
	printf("informe um numero: ");
	scanf("%d", &n);
	
	printf("%d", fibonacci(n));
		
	return 0;
}