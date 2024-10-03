#include <stdio.h>

// Função para verificar se é seguro colocar a rainha na posição (l, c)
int verificaSeguranca(int tab[4][4], int l, int c) {
    int i, j;

    // Verificar a linha à esquerda
    for (i = 0; i < c; i++) {
        if (tab[l][i] == 1)
            return 0;
    }

    // Verificar a diagonal superior esquerda
    for (i = l, j = c; i >= 0 && j >= 0; i--, j--) {
        if (tab[i][j] == 1)
            return 0;
    }

    // Verificar a diagonal inferior esquerda
    for (i = l, j = c; i < 4 && j >= 0; i++, j--) {
        if (tab[i][j] == 1)
            return 0;
    }

    return 1; // Se nenhuma verificação falhou, é seguro colocar a rainha
}

// Função recursiva para resolver o problema das 4 rainhas
int resolve4Rainhas(int tab[4][4], int c) {
    if (c >= 4) // Base: Se todas as rainhas forem colocadas, retorna sucesso
        return 1;

    for (int i = 0; i < 4; i++) {
        // Verifica se é seguro colocar a rainha na posição (i, c)
        if (verificaSeguranca(tab, i, c)) {
            tab[i][c] = 1; // Coloca a rainha

            // Tenta colocar a próxima rainha na próxima coluna
            if (resolve4Rainhas(tab, c + 1))
                return 1; // Se der certo, retorna sucesso

            // Se colocar a rainha não levar à solução, remove a rainha (backtracking)
            tab[i][c] = 0;
        }
    }

    return 0; // Se não for possível colocar a rainha, retorna fracasso
}

int main() {
    int tab[4][4];

    // Inicializa a matriz com zeros
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            tab[i][j] = 0;
        }
    }

    // Tenta resolver o problema das 4 rainhas
    if (resolve4Rainhas(tab, 0)) {
        // Imprime a matriz com a solução
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                printf("%d ", tab[i][j]);
            }
            printf("\n");
        }
    } else {
        printf("Solução não encontrada.\n");
    }

    return 0;
}
