#include <stdio.h>
#ifndef PILHA_H
#define PILHA_H
#define MAX 100

typedef int 
    type_item;


typedef struct {
    int top;
    type_item item[MAX];

} type_stack;

void initializeStack(type_stack *p){
    p->top = -1; //para inicializar a pilha
}

int stackEmpty(type_stack *p){
    return p->top == -1; //aqui ele retorna 1 que representa "true" 
}

int stackFull(type_stack *p){
    return p->top == MAX-1;
}

int push(type_stack *p, type_item e){
    if(stackFull(p)) return 0; //a pilha tá cheia e eu não posso empilhar mais
    p->item[++p->top] = e;
    return 1;
}

int pop(type_stack *p, type_item *e){
    if(stackEmpty(p)) return 0; //verifica se a pilha está vazia, se estiver vazia (1 - true), aborta e não retirar 
    *e = p->item[p->top--];
    return 1;
}

int top (type_stack *p, type_item *e){
    if(stackEmpty(p)) return 0;
    *e = p->item[p->top];
    return 1;
}

void printStack(type_stack p){
    type_item e;
    printf("\n");

    //impressão da cópia da pilha
    while(!stackEmpty(&p)){
        pop(&p, &e);
        printf("%d ", e);
    }
}


int lenStack(type_stack *p){
    return p->top+1;
}


void withoutOdd (type_stack *p){

    type_stack sAux;
    type_item e;
    initializeStack(&sAux);

    while (!stackEmpty(p)){
        pop(p, &e);
        if (e%2 == 0){
            push(&sAux, e);
        }
    }

    while(!stackEmpty(&sAux)){
        pop(&sAux, &e);
        push(p, e);
    }
}


#endif