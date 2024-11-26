#ifndef ARQUIVO_H
#define ARQUIVO_H

#include <stdio.h>
#include <string.h>
#include <locale.h>

//vou precisar adicionar uma variável para a pontuação do jogador na struct dele

//funções para manipulação de arquivos



int gravar(FILE *arq, char nomearq[]){
	char mensagem[50];
	arq = fopen(nomearq, "w");
	if (!arq) return 0;
	printf("Digite o nome do jogador ");
	fflush(stdin);
	gets(mensagem);
	fprintf(arq, strcat(mensagem,":"));
	printf("Digite a pontuacao do jogador");
	fflush(stdin);
	gets(mensagem);
	fputs(mensagem, arq);
	fclose(arq);
	return 1;
}

int ler(FILE *arq, char nomearq[]){
	char registro[50];
	arq = fopen(nomearq,"r");
	if(!arq) return 0;
	while (fgets(registro, sizeof(registro), arq)){
		printf("%s", registro);
	
	}
	
	fclose(arq);
	return 1;
}

int editar (FILE *arq, char nomearq[]){
	char mensagem[50];
	arq = fopen(nomearq, "a");
	if(!arq) return 0;
	
	
	printf("Digite o nome do jogador ");
	fflush(stdin);
	gets(mensagem);
	fprintf(arq, strcat(mensagem,":"));
	
	printf("Digite a pontuacao do jogador: ");
	fflush(stdin);
	gets(mensagem);
	fputs(mensagem, arq);
	
	fclose(arq);
	
	return 1;
	
}

int resgatar_informacoes(FILE *arq, char nomearq[], char* nome, int* pontuacao){
	char linha[100];
	arq = fopen(nomearq, "r");
	if (!arq) return 0;
	
	while(fgets(linha, sizeof(linha), arq)){
		
		if(sscanf(linha, "%[^:]:%d", nome, pontuacao) == 2){
			fclose(arq);
			return 1;
		}
		
	}
	
	fclose(arq);
	return 0;
}

int inserir_em_ordem(FILE *arq, char nomearq[], char* nome, int *pontuacao){
	FILE *tempArq; //arquivo temporário para que sejam salvas as novas informações
	char linha[100];
	char nome2[50];
	int pontuacao2;
	int inserido = 0;
	
	arq = fopen(nomearq, "r");
	if(!arq) return 0;
	
	temArq = fopen("temp.txt", "w");
	if(!tempArq){
		fclose(arq);
		return 0;
	}
	
	//verificando a inserção do jogador
	while(fgets(linha, sizeof(linha), arq)){
		sscanf(linha, "%[^:]:%d", nome2, pontuacao2);
		
		
		if(!inserido && pontuacao > pontuacao2){
			fprintf(tempArq, "%s:%d\n", nome, pontuacao);
			inserido = 1;
		}
		
		fprintf(tempArq, "%s:%d\n", nome2, pontuacao2);
	}
	
	if (!inserido){
		fprintf(tempArq, "%s:%d\n", nome, pontuacao);
	}
	
	fclose(arq);
	fclose(tempArq);
	
	remove(nomearq);
	rename("temp.txt", nomearq);
}

#endif