#ifndef FILA_H
#define FILA_H
#include <stdio.h>
#define MAX 100

typedef int type_item;

typedef struct{
	type_item item[MAX];
	int start, end;
	// int len;
}type_line;

void initializeLine(type_line *l){ //inicio e fim passam a ocupar a mesma posição física do vetor
	l->start = l->end = MAX-1;
	//l->tam = 0;
}

int lineEmpty(type_line *l){
	if(l->start == l->end) return 1;
	return 0;
}