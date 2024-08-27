#ifndef PILHA_H
#define PILHA_H
#define MAX 100

typedef int 
    type_item;


typedef struct {
    int top;
    type_item item[MAX];

} type_stack;


#endif