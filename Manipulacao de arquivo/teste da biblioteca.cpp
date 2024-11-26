#include <stdio.h>
#include <string.h>
#include <locale.h>
#include "arquivo.h"


int main(){
	int i, n, x=0;
	setlocale(LC_ALL, "portuguese");
	char opcao, nomearq[50], nome[50];
	int pontuacao;
	FILE *arq;
	
	
	printf("Digite a opcao desejada:\n");
	printf("1 - Abrir um arquivo para gravacao \n");
	printf("2 - Ler um arquivo \n");
	printf("3 - Editar um arquivo\n");
	printf("4 - Retirar informacoes do arquivo\n");
	
	scanf(" %c", &opcao);
	printf("Digite o nome do arquivo: ");
	scanf(" %[^\n]s", nomearq);
	
	
	switch(opcao){
		case '1': gravar(arq, nomearq);
				break;
		case '2': ler(arq, nomearq);
				break;
		case '3': editar(arq, nomearq);
				break;
		case '4': if(resgatar_informacoes(arq, nomearq, nome, &pontuacao)){
				printf("Informacoes do arquivo: ");
				printf("Nome: %s\n", nome);
				printf("Pontuacao: %d\n", pontuacao);	
			} else {
				printf("Erro!");
			}
				break;
	}
	return 0;
}