#include <stdio.h>

int fatorialr(int num){
	
	if (num==0){
		return 1;
	} else {
		return num * fatorialr(num-1);
	}
}

int main(){
	int num;
	printf("Informe um numero: ");
	scanf("%d", &num);
	
	printf("%d", fatorialr(num));
	
	return 0;
}