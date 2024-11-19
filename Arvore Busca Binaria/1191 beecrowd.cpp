#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 27

int indprefixa;

typedef char tp_item;

typedef struct tp_no{
	struct tp_no *esq;
	tp_item info;
	struct tp_no *dir;
} tp_no;

typedef tp_no *tp_arvore;

tp_arvore inicializa_arvore()
{
	return NULL;
}

tp_no *aloca_no() //aloca e retorna o endereço
{
	tp_no *no;
	no = (tp_no*) malloc(sizeof(tp_no));
	return no;
}

void pos_ordem (tp_no *p) { //imprime os elementos em pós-ordem
	if (p != NULL) {
	pos_ordem (p->esq);
	pos_ordem (p->dir);
	printf("%c",p->info);
	}
}

int busca_infixa(char *infixa, int esq, int dir, tp_item info)
{
	int i;
	for (i = esq; i <= dir; i++)
	if (infixa[i] == info)
		return i;
	return -1;
}

//OCI
tp_arvore monta_arvore(char prefixa[], char infixa[], int esq, int dir)
{
	if (esq > dir)
		return NULL;

//Aloca memória para um nó, preenche com o nó raiz
	tp_no *no = aloca_no();
	no->info = prefixa[indprefixa];
	no->dir = no->esq = NULL;
	indprefixa++;

	if (esq == dir) // Se nó folha, retorna o end. do nó para a chamada anterior
		return no;

	int indinfixa = busca_infixa(infixa, esq, dir, no->info);
	no->esq = monta_arvore(prefixa, infixa, esq, indinfixa-1);
	no->dir = monta_arvore(prefixa, infixa, indinfixa+1, dir);

	return no;
}

int main ()
{
	tp_arvore raiz;
	raiz=inicializa_arvore();
	char prefixa[MAX];
	char infixa[MAX];

	while (scanf("%s %s", prefixa, infixa) != EOF) {
		indprefixa = 0;
		raiz = monta_arvore(prefixa, infixa, 0, strlen(prefixa)-1);
		pos_ordem(raiz);
		printf("\n");
	}
	return 0;
}