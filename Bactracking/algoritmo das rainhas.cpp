#include <stdio.h>

int verificaRainhas(int tab[4][4], int l, int c){
	//verificando a linha antes, fixando a linha em que está e mexendo a coluna
	
	for (int i = 0; i < c; i++){ 
		if(tab[l][i]==1){
			return 0;
		}
	}
	
	//verificando a diagonal superior, decrescendo a linha e coluna
	for (int i = l, j = c; i >= 0 && j >= 0; i--, j--){
		if(tab[i][j]==1){
			return 0;
		}
	}
	
	
	//verficando a diagonal inferior, crescendo a linha e diminuindo a coluna
	for (int i = l, j = c; i<4 && j >=0; i++, j--){
		if(tab[i][j] == 1){
			return 0;
		}
	}
	
	return 1;
	
}

//função recursiva
int tabuleiroRainhas(int tab[4][4], int c){
	if (c>= 4){ //passo base, se ele já estiver na coluna 4 ou mais, retorna positivo
		return 1;
	} 
	

	for (int i = 0; i <4; i++){
		if(verificaRainhas(tab, i, c)){ //verificando a cada loop se a posição da linha sendo mexida com as alterações é válida 
			tab[i][c] = 1; //colocando a rainha
				
				
			if(tabuleiroRainhas(tab, c+1)){//chamada recursiva da função, avançando na próxima coluna
				return 1;
			}
			
			tab[i][c]= 0;
			
			}
		
		
		}
	
		return 0;//caso de jeito nenhum caibam as rainhas

}



int main(){
	int tab[4][4];
	
	
	for (int i = 0; i<4; i++){
		for (int j = 0; j <4; j++){
			tab[i][j] = 0;
		}
	}
	
	if(tabuleiroRainhas(tab, 0)){
		for (int i = 0; i<4; i++){
			for (int j = 0; j <4; j++){
				printf("%d ", tab[i][j]);
			}
			
		printf("\n");
		}
	
	}
	
	return 0;
}
