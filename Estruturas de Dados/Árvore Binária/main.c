#include <stdio.h>
#include <stdlib.h>
#include "arvore_binaria.h"

int main() {
    No *raiz = NULL;
    int n, x = 0, op = -1;
    printf("Insira o valor inicial da arvore: ");
    if (scanf("%d", &n) != 1) {
        printf("Leitura nao suportada!\n(Programa abortado)\n");
        return 1;
    }
    if (n < 1) {
        printf("Valor invalido!\n(Programa abortado)\n");
        return 1;
    }
    raiz = criar(n);
    while (op != 0) {
        menu();
        scanf("%d", &op);
        while (op < 0 || op > 3) {
            printf("Opcao invalida!\nInsira a opcao desejada: ");
            scanf("%d", &op);
        }
        switch (op) {
            case 1:
                printf("Insira um elemento natural a ser acrescentado a arvore: ");
                scanf("%d", &x);
                if (x < 0) {
                    printf("Valor invalido!\n(Operacao abortada)\n");
                    break;
                }
                inserir(raiz, x);
                printf("Elemento %d acrescentado com sucesso!\n", x);
                break;
            case 2:
                printf("Insira um elemento a ser encontrado na arvore: ");
                scanf("%d", &x);
                (buscar(raiz, x)) ? printf("O elemento %d se encontra na arvore!\n", x) : printf("O elemento %d nao se encontra na arvore!\n", x);
                break;
            case 3:
                printf("Insira um elemento a ser removido da arvore: ");
                scanf("%d", &x);
                (remover(raiz, x)) ? printf("Elemento %d removido com sucesso!\n", x) : printf("O elemento %d nao se encontra na arvore!\n", x);
                break;
            default: break;
        }
    }
    printf("Arvore final:\n");
    percursos(raiz);
    printf("\n");
    liberar(raiz);
    return 0;
}