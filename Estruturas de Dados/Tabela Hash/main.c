#include <stdio.h>
#include <stdlib.h>
#include "tabela_hash.h"

int main() {
    No *tabela[TAMANHO];
    int k, x, op = -1;
    inicializar_tabela(tabela);
    while (op != 0) {
        printf("1. Adicionar a tabela\n2. Buscar na tabela\n0. Encerrar a operacao\nInsira a opcao desejada: ");
        scanf("%d", &op);
        while (op < 0 || op > 2) {
            printf("Opcao invalida!\nInsira a opcao desejada: ");
            scanf("%d", &op);
        }
        switch (op) {
            case 1:
                printf("Insira os valores naturais da chave e do dado de um elemento a ser inserido na tabela: ");
                if (scanf("%d %d", &k, &x) != 2) {
                    printf("Leitura nao suportada!\n(Operacao abortada)\n");
                    break;
                }
                if (k < 0 || x < 0) {
                    printf("Valor(es) ");
                    if (k < 0) printf("%d (valor da chave) ", k);
                    if (x < 0) printf("%d (valor do dado) ", x);
                    printf("invalido(s)!\n(Operacao abortada)\n");
                    break;
                }
                inserir(tabela, k, x);
                printf("Elemento [%d: %d] inserido com sucesso!\n", k, x);
                break;
            case 2:
                printf("Insira a chave de um elemento que deseja encontrar na tabela: ");
                scanf("%d", &k);
                int valor = buscar(tabela, k);
                (valor != -1) ? printf("[Elemento de chave %d: %d]\n", k, valor) : printf("Nao ha elemento com chave %d na tabela!\n", k);
                break;
            default: break;
        }
    }
    imprimir("Tabela final:", tabela);
    liberar(tabela);
    return 0;
}