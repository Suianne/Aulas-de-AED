#include <stdio.h>
#include <string.h>
#include <locale.h>
#include "arquivo.h"


int main(){
	int i, n, x=0;
	setlocale(LC_ALL, "portuguese");
	char opcao, nomearq[50];
	FILE *arq;
	
	
	printf("Digite a opcao desejada:\n");
	printf("1 - Abrir um arquivo para gravação \n");
	
	scanf(" %c", &opcao);
	printf("Digite o nome do arquivo: ");
	scanf(" %[^\n]s", nomearq);
	
	
	switch(opcao){
		case '1': gravar(arq, nomearq);
				break;
	}
	return 0;
}