#ifndef FILA_H
#define FILA_H
#include <stdio.h>
#include "pilha.h"
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

int next(int pos){
	if(pos == MAX-1){
		return 0;
	} else {
		pos++;
		return pos;
	}
}

int lineFull (type_line *l){
	if(next(l->end)==l->start){
		return 1;
	} else {
		return 0;
	}
}

int insertLine(type_line *l, type_item e){
	if(lineFull(l)){
		return 0;
	} else {
		l->end = next(l->end);
		l->item[l->end] = e;
		return 1;
	}
}

int removeLine(type_line *l, type_item *e){
	if(lineEmpty(l)){
		return 0;
	} else {
		l->start = next(l->start);
		*e = l->item[l->start];
		return 1;
	}
}

void printLine(type_line l){
	type_item e;
	while(!lineEmpty(&l)){
		removeLine(&l, &e);
		printf("%d\n", e);
	}
}

int lenghtLine (type_line *l){
	if(lineEmpty(l)) {
		return 0;
	} else if (l->start < l->end){
		return l->end - l->start;
	} else {
		return MAX -1 - l->start + l->end + 1;
	}
}

int lenghtLine2 (type_line l){
	int cont=0;
	type_item e;
	
	while(!lineEmpty(&l)){
		removeLine(&l, &e);
		cont++;
	}
	
	return cont;
}

void inverseLine(type_line l){
	type_stack pilha;
	type_item e;
	initializeStack(&pilha);
	
	while(!lineEmpty(&l)){
		removeLine(&l, &e);
		push(&pilha, e);
	}
	
	while(!stackEmpty(&pilha)){
		pop(&pilha, &e);
		insertLine(&l, e);
	}
	
	printLine(l);
	
}

#endif