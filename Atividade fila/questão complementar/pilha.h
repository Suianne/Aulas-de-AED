#include <stdio.h>
#ifndef PILHA_H
#define PILHA_H
#define MAX 100

typedef char 
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
        printf("%c ", e);
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

int compareStacks(type_stack p1, type_stack p2){
    if(lenStack(&p1) != lenStack(&p2)) 
        return 0; //falso, são diferentes

    type_item e1, e2;
    while(!stackEmpty(&p1)){
        pop(&p1, &e1);
        pop(&p2, &e2);

        if(e1 != e2){
            return 0;
        }
    }

    return 1;

}

int stackStacks(type_stack *p1, type_stack *p2){
	if(lenStack(p1) + lenStack(p2) > MAX){
		return 0;
	} else {
		type_stack sAux;
		initializeStack(&sAux);
		
		type_item e;
		
		while(!stackEmpty(p2)){
			pop(p2, &e);
			push(&sAux, e);
		}
		
		while(!stackEmpty(&sAux)){
			pop(&sAux, &e);
			push(p1, e);
		}
		
		return 1;
	}
}

void inverseStack(type_stack *s){
	type_item e;
	type_stack sAux;
	initializeStack(&sAux);
	
	while(!stackEmpty(s)){
		pop(s, &e);
		push(&sAux, e);
	} 
	
	while(!stackEmpty(&sAux)){
		pop(&sAux, &e);
		push(s, e);
	}
}

int expression(char exp[], int len){
	type_stack pilha;
	initializeStack(&pilha);
	type_item e, e2;
	int num;
	
	for (int i = 0; i < len; i++){
		if(exp[i] != '/' && exp[i] != '*'){
			e = exp[i];
			push(&pilha,e);
		} else {
			if(exp[i] == '*'){
				// retira o valor anterior que estava na pilha
				pop(&pilha, &e2);
				num = (exp[i+1]-48) * (e2-48); // faz a conta 
				
				
				e = (num+48);
				push(&pilha, e);
				
				//passa pelo valor da expressão que seria o próximo
				i++;
			} else if (exp[i] == '/'){
				pop(&pilha, &e2);
				num = (e2-48) / (exp[i+1]-48);
				
				e = (num+48);
				push(&pilha, e);
				
				i++;
			}
		}
	}
	
	printStack(pilha);
	
	type_item e4, e5, e6, e7;
	type_stack sAux;
	initializeStack(&sAux);
	int res=0;
	

	
	while(!stackEmpty(&pilha)){
		pop(&pilha, &e4);
		
		if(e4 != '+' || e4 != '-'){
			push(&sAux, e4);
		} else {
			if(e4 == '+'){
				pop(&sAux, &e5);
				pop(&pilha, &e6);
				res = (e5 - 48) + (e6-48);
				e7 = (res+48);
				push(&sAux, e7);
			} else if(e4 == '-'){
				pop(&sAux, &e5);
				pop(&pilha, &e6);
				res = (e5 - 48) - (e6 - 48);
				e7 = (res+48);
				push(&sAux, e7);
			}
		}
	}
	
	pop(&sAux, &e7);
	res = (e7-48);
	
	return res;
}

#endif