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
    if(p->top == -1) return 1; //aqui, 1 representa "true"
    return 0; //aqui, o retorno do número 0 "false"
}

int fullStack(type_stack *p){
    if(p->top == MAX-1){
        return 1;
    } else {
        return 0;
    }
}

int push(type_stack *p, type_item e){
    if(stackEmpty(p)==1) return 0; //a pilha tá cheia e eu não posso empilhar mais
    p->top++;
    p->item[p->top] = e;
    return 1;
}

int pop(type_stack *p, type_item *e){

    if(stackEmpty(p)) //verifica se a pilha está vazia, se estiver vazia (1 - true), aborta e não retirar
        return 0; 
    *e = p->item[p->top];
    return 1;
}

int top (type_stack *p, type_item *e){
    if(stackEmpty(p)) return 0;
    *e = p->item(p->top);
    return 1;
}

void printStack(type_stack p){
    type_item e;
    printf("\n");

    //impressão da cópia da pilha
    while(!stackEmpty){
        pop(&p, &e);
        printf("%d", e);
    }
}


#endif