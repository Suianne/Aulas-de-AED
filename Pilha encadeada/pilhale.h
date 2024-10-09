#ifndef "PILHALSE_H"
#define "PILHALSE_H"
#include <stdio.h>
#include <stdlib.h>

typedef int tp_item;

typedef struct tp_no_aux {
	
	tp_item info;
	struct tp_no_aux *prox;
	
}tp_no; 

typedef struct {
	tp_no *topo; //a variável que vai ajudar a manipular a pilha na mesma mecânica da pilha estática
}tp_pilha;


tp_pilha *inicializa_pilha (){ //função do tipo pilha que retorna um ponteiro do tipo pilha
	tp_pilha pilha = (tp_pilha) malloc(sizeof(tp_pilha));
	pilha->topo = NULL; //inicializa a pilha fazendo com que o ponteiro do topo seja nulo
	return pilha;
}

int pilha_vazia(tp_pilha *pilha){
	if(pilha->topo == NULL) return 1; //se o topo da pilha não está apontando para nada, ela está vazia
	return 0;
}

tp_no *aloca(){
	tp_no *pt = (tp_no *) malloc(sizeof(tp_no));
	return pt;
}

int push (tp_pilha *pilha, tp_item e){
	
	//alocação de um novo nó
	tp_no *novo;
	novo = *aloca();
	if(!novo) return 0; //aqui verifica se ele conseguiu alocar o nó ou não
	
	//povoamento do nó com o item que foi passado
	novo->info = e;
	
	if(pilha_vazia(pilha)){ //avalia se é o primeiro elemento que está sendo inserido
		novo->prox = NULL; //se é primeiro nó, não há um elemento acima para que ele aponte
	} else {
		novo->prox = pilha->topo; //se não for o primeiro, o elemento que está acima, tem que apontar para o que está embaixo, que antes era apontado pelo topo da pilha (essa troca se torna mais fácil justamente por causa dessa variável topo)
	}
	
	pilha->topo = novo; 
	return 1; //empilhou com sucesso
	
}

int pop(tp_pilha *pilha, tp_item *e){
	tp_no *aux;
	
	if(pilha_vazia(pilha)) return 0; //não é possível retirar porque não tem nada
	
	*e=pilha->topo->info; //atribui ao e a informação que está no info do último elemento da pilha
	
	//manipulação da pilha
	
	aux=pilha->topo; //o ponteiro auxiliar recebe o topo da pilha (a posição em que estava o elemento que foi retirado)
	pilha->topo=pilha->topo->prox; //atualiza o topo da pilha para o no que era aponta pelo prox do no que foi retirado, é um tipo de bypass
	
	//liberação do espaço de memória
	free(aux);
	aux=NULL;
	
	return 1;
	
}

int top (tp_pilha *pilha, tp_item *e){
	tp_no *aux;
	
	if(pilha_vazia(pilha)) return 0;
	
	*e=pilha->topo->info;
	return 1;
}

tp_pilha *destroi_pilha(tp_pilha *pilha){
	tp_no *atu = pilha->topo, *aux; //cria um ponteiro com a localização atual do topo da pilha e um ponteiro auxiliar
	tp_item e;
	
	while(atu!=NULL){ //enquanto atual não for nulo, percorre a lista, tirando os últimos elementos que foram empilhados
		aux = atu->prox;
		pop(pilha, &e);
		atu = aux;
	}
	
	pilha->topo=NULL; //depois de tirar todos os elemtnos da pilha, fazer com pilha seja nula
	free(pilha); //liberando a pilha
	return NULL; //retorna nulo para o tipo pilha
}

void imprime_pilha(tp_pilha *pilha){
	tp_pilha *pilha_aux; //criação de uma pilha auxiliar para o processor de desimpilhar
	tp_item e;
	
	//inicializando a pilha auxiliar
	pilha_aux = inicializa_pilha();
	
	while(!pilha_vazia(pilha)){ //enquanto a pilha principal não estiver vazia, desimpilha, printa e depois empilha na pilha auxiliar
		pop(pilha, &e);
		printf("%d", e);
		push(pilha_aux, e);
	}
	
	while(!pilha_vazia(pilha_aux)){ //faz o mesmo processo de cima, mas invertendo as pilhas 
		pop(pilha_aux, &e);
		printf("%d", e);
		push(pilha, e);
	}
	
	pilha_aux = destroi_pilha(pilha_aux);

}

#endif