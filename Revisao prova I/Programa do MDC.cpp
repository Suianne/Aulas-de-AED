#include <stdio.h>

int mdc(int maior, int menor){
	
	if (maior % menor == 0){
		return menor;
	} else {
		for (int i = menor; i > 1; i--){
			if (menor%i == 0){
				menor = i;
			}
		}
		
		return mdc(maior, menor);
	}
}


int main (){
	int n1, n2, maior, menor;
	
	
	printf("Informe dois numeros inteiros: ");
	scanf("%d %d", &n1, &n2);
	
	if (n1>n2){
		maior = n1;
		menor = n2;
	} else if (n2>n1){
		maior = n2;
		menor = n1;
	}
	
	printf("O mdc de %d e %d e: %d", n1, n2, mdc(maior, menor));
	
	
	
	
	return 0;
}