/*Implementar uma função que receba uma pilha como parâmetro e retire todos os
elementos ímpares dessa pilha.*/

#include "pilha.h"
#include <stdio.h>

int main(){
    type_stack stack;
    initializeStack(&stack);
    
    for(type_item i = 7; i< 20; i++){
        push(&stack, i);
    }

    printf("Essa e a pilha antes da retirada dos impares\n");

    printStack(stack);

    //aplica a função que retira ímpares na pilha
    withoutOdd(&stack);

    printf("\nA pilha depois de tirar os impares\n");
    printStack(stack);


    return 0;
}