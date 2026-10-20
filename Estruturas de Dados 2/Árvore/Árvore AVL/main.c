#include <stdio.h>
#include <stdlib.h>
#include "arvore_avl.h"

int main() {
    No *raiz = NULL;
    int x = 0;
    while (1) {
        printf("Insira um elemento natural a ser acrescentado a arvore (ou valor invalido para encerrar o programa): ");
        if (scanf("%d", &x) != 1) {
            printf("Valor invalido!\n(Operacao encerrada)\n");
            break;
        }
        if (x < 0) {
            printf("Valor invalido!\n(Operacao encerrada)\n");
            break;
        }
        raiz = inserir(raiz, x);
        printf("Elemento %d acrescentado com sucesso!\n", x);
    }
    printf("Arvore final:\n");
    percursos(raiz);
    printf("\n");
    liberar(&raiz);
    return 0;
}