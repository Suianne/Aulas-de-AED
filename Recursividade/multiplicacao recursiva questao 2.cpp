#include <stdio.h>


int mult(int n1, int n2){
	if(n2==1){
		return n1;
	} else {
		return n1 + mult(n1, n2-1);
	}
	
}
int main(){
	int n1, n2;
	
	printf("Informe dois numeros para multiplicar: ");
	
	scanf("%d %d", &n1, &n2);
	
	printf("O produto e: %d", mult(n1, n2));
	
	return 0;
}