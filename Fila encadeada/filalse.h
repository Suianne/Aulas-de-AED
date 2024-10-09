#ifndef FILALSE_H
#define FILALSE_H
#include <stdio.h>
#include <stdlib.h>

typedef int tp_item;

typedef struct tp_no_aux {
    tp_item info;
    struct tp_no_aux *prox;
} tp_no;

typedef struct {
    tp_no *ini, *fim; // criação do cabeçalho da fila, que vai ajudar a controlar
} tp_fila;

tp_fila *inicializa_fila() { // inicializa a fila, fazendo com que inicio e fim sejam iguais, apontando para NULL
    tp_fila *fila = (tp_fila *) malloc(sizeof(tp_fila));
    fila->ini = fila->fim = NULL;
    return fila;
}

tp_no *aloca() { // aloca o nó para a fila de forma dinâmica
    tp_no *pt = (tp_no *) malloc(sizeof(tp_no));
    return pt;
}

int fila_vazia(tp_fila *fila) {
    if (fila->ini == NULL && fila->fim == NULL) return 1; // a fila está vazia, pois inicio e fim não apontam para nós
    return 0;
}

int insere_fila(tp_fila *fila, tp_item e) { // função que insere elemento na fila no fim, como a mecânica da fila estática

    tp_no *novo;
    novo = aloca();
    
    // verificar se conseguiu alocar 
    if (!novo) return 0;
    
    // povoando o nó da fila
    novo->info = e;
    novo->prox = NULL;
    
    // verificando se a fila está vazia ou não, para fazer os diferentes tipos de inserção
    if (fila_vazia(fila)) {
        fila->ini = novo; // se for o primeiro nó, o ini aponta para ele
    } else {
        fila->fim->prox = novo; // se for um segundo nó ou quarto, ele se torna o próximo do elemento anterior que era apontado pelo fim
    }
    
    fila->fim = novo; // de qualquer forma, o novo endereço de memória é apontado por fim
    return 1;
}

int remove_fila(tp_fila *fila, tp_item *e) {
    tp_no *aux;
    
    if (fila_vazia(fila)) return 0;
    
    *e = fila->ini->info; // atribuindo o valor do nó removido ao item retornado
    aux = fila->ini;
    
    if (fila->ini == fila->fim) { // se esse for o único nó da lista, ini e fim são setados para NULL
        fila->ini = fila->fim = NULL;
    } else {
        fila->ini = fila->ini->prox; // como o nó que está sendo retirado é o primeiro, o próximo apontado pelo início se torna o novo início
    }
    
    free(aux); // liberar a memória do nó removido
    return 1;
}

void imprime_fila(tp_fila *fila) {
    if (fila_vazia(fila)) {
        printf("A fila está vazia.\n");
        return;
    }

    tp_no *atual = fila->ini;
    while (atual != NULL) {
        printf("%d ", atual->info);
        atual = atual->prox;
    }
    printf("\n");
}
#endif
