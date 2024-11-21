#ifndef ARQUIVO_H
#define ARQUIVO_H

#include <stdio.h>
#include <string.h>
#include <locale.h>

int gravar(FILE *arq, char nomearq[]){
	char mensagem[50];
	arq = fopen(nomearq, "w");
	if (!arq) return 0;
	printf("Digite mensagem 1 para gravar no arquivo ");
	fflush(stdin);
	gets(mensagem);
	fprintf(arq, strcat(mensagem,"\n"));
	printf("Digite a mensagem 2 para gravar no arquivo");
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
	fclose(arq);
	}
	return 1;
}


#endif