#include <stdio.h>

int numMaior(int vetor [], int len){
	
	if(len == 1){
		return vetor[0];
	} else {
		
		int maior = numMaior(vetor, len-1);//chamada recursiva
		
		if(vetor[len-1]> maior){
			return vetor[len-1];
		} else {
			return maior;
		}
	}
	
}

int main(){
	int len;
	printf("Informe a quantidade de valores no vetor: ");
	scanf("%d", &len);
	
	int vetor[len];
	
	for (int i = 0; i < len; i++){
		scanf("%d", &vetor[i]);
	}
	
	printf("O maior numero do vetor e: %d", numMaior(vetor, len));
	
	return 0;
}