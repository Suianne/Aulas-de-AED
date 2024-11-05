#include <stdio.h>
#include <stdlib.h> //para o sorteio
#include <time.h>
#include "listade.h"

int main(){
	tp_listade *lista;
	lista = inicializa_listade();
	
	insere_listade(lista, 10);
	insere_listade(lista, 15);
	insere_listade(lista, 20);
	insere_listade(lista, 25);
	
	
	insere_media(lista);
	
	
	
	return 0;
}