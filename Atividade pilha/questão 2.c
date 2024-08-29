#include <stdio.h>
#include "pilha.h"

int main(){
    type_stack stackOne, stackTwo;
    initializeStack(&stackOne);
    initializeStack(&stackTwo);

    for(type_item i = 7; i <10; i++){
        push(&stackOne, i);
        //push(&stackTwo, i); quando forem iguais
    }

    //usar a função de comparar pilhas
    if(compareStacks(stackOne, stackTwo)){
        printf("Sao iguais");
    } else {
        printf("Sao diferentes");
    }

    return 0;
}