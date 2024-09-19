#include <stdio.h>

void funcao(int *c, int *d) {
    int a;
    a = *c;
    *c = *d;
    *d = a;
}

int main() {
    int a = 10, b = 30;
    int *p = &a;
    int *q = &b;
    
    funcao(p, q);  // Chama a função com p e q
    
    *q += *p;
    *p = ++*q;

    printf("%d %d", a, b);  // Imprime os valores de a e b

	
    return 0;
}
