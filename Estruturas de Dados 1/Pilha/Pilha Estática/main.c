#include <stdio.h>
#include <stdlib.h>
#include "pilha_estatica.h"

int main() {
    Pilha p;
    int x, op = -1, checkup = 1;
    inicializa_pilha(&p);
    while (op != 0) {
        menu();
        scanf("%d", &op);
        while (op < 0 || op > 3) {
            printf("Opcao invalida!\nInsira a opcao desejada: ");
            scanf("%d", &op);
        }
        switch (op) {
            case 1:
                if (!checkup) {
                    printf("Pilha cheia!\n");
                    break;
                }
                printf("Insira um valor a ser acrescentado a pilha: ");
                scanf("%d", &x);
                checkup = push(&p, x);
                if (checkup) printf("Elemento %d acrescentado com sucesso!\n", x);
                break;
            case 2:
                int removido;
                (!pop(&p, &removido)) ? printf("Pilha vazia!\n") : printf("Elemento %d removido da pilha\n", removido);
                break;
            case 3:
                printf("Topo da pilha: %d\n", peek(&p));
                break;
            default: break;
        }
    }
    imprime_pilha("Pilha final:", &p);
    return 0;
}