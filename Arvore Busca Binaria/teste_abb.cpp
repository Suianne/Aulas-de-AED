#include <stdio.h>
#include "arvorebb.h"

int main(){
	tp_arvore raiz = incializa_arvore();
	
	insere_no(&raiz, 10);
	insere_no(&raiz, 7);
	insere_no(&raiz, 15);
	insere_no(&raiz, 3);
	insere_no(&raiz, 1);
	insere_no(&raiz, 8);
	insere_no(&raiz, 14);
	insere_no(&raiz, 20);
	

	int nivelArvore = nivel_arvore(raiz);
	
	printf("O nivel da arvore e: %d", nivelArvore);
	
	printf("\n");
	
	int altArvore = altura_arvore(raiz);
	
	printf("A altura da arvore e: %d", altArvore);
	
	printf("A quantidade de nos na arvore e: %d", qt_nos(raiz));

//	tp_no *resultado = busca_no(raiz, 8);
//	if(resultado != NULL && resultado->info == 8){
//		printf("O no foi encontrado");
//	} else {
//		printf("O no nao existe");
//	}
	
//	tp_no *resultado = busca_no(raiz, 25);
//	if(resultado != NULL && resultado->info == 8){
//		printf("O no foi encontrado");
//	} else {
//		printf("O no nao existe");
//	}
//	pre_ordem(raiz);
//	em_ordem(raiz);
//	pos_ordem(raiz);
	
	return 0;
}