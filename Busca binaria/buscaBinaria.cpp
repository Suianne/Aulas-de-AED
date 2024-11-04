#include <stdio.h>
#define TAM 10

int busca_binaria(int *v, int k, int b){
	
	int esq, dir, meio;
	esq=0;
	dir = k-1;
	
	while(esq<=dir){
		meio = (esq+dir)/2;
		if (b==v[meio])
			return meio;
		else 
			if(b<v[meio])
				dir = meio - 1;
			else 
				esq = meio + 1;
	}
	
	return -1;
}


int busca_binariaRecursiva(int *v, int esq, int dir, int b){
	
	int meio = (esq+dir)/2;
	
	if(esq > dir){
		return -1;
	} else if (b == v[meio]){
		return meio;
	} else {
		if(b < v[meio]){
			return busca_binariaRecursiva(v, esq, meio-1, b);
		} else {
			return busca_binariaRecursiva(v, meio+1, dir, b);
		}
	}
	
	
}

int main(){
	
	int vet[TAM], n = 1;
	
	for (int i = 0; i < TAM; i++){
		vet[i] = n;
		n++;
	}
	
	for (int i = 0; i < TAM; i++){
		printf("%d ", vet[i]);
	}
	
//	printf("%d", busca_binaria(vet, sizeof()))
	
	
	printf("\nPosicao do vetor onde esta 5: ");
	printf("%d", busca_binariaRecursiva(vet, 0, TAM-1, 5));
	
	
	return 0;
}