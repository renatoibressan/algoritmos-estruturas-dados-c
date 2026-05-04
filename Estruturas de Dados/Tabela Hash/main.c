#include <stdio.h>
#include <stdlib.h>
#include "tabela_hash.h"

int main() {
    No *tabela[TAMANHO];
    int x, y, op = -1, key = 0;
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
                if (scanf("%d %d", &x, &y) != 2) {
                    printf("Leitura nao suportada!\n(Programa abortado)\n");
                    break;
                }
                if (x < 0 || y < 0) {
                    printf("Valor(es) ");
                    if (x < 0) printf("%d (valor da chave) ", x);
                    if (y < 0) printf("%d (valor do dado) ", y);
                    printf("invalido(s)!\n(Operacao abortada)\n");
                    break;
                }
                inserir(tabela, x, y);
                printf("Elemento [%d: %d] inserido com sucesso!\n", x, y);
                break;
            case 2:
                printf("Insira a chave de um elemento que deseja encontrar na tabela: ");
                scanf("%d", &x);
                int resultado = buscar(tabela, x);
                (resultado != -1) ? printf("[Elemento de chave %d: %d]\n", x, resultado) : printf("Nao ha elemento com chave %d na tabela!\n", x);
                break;
            default: break;
        }
    }
    imprimir("Tabela final:", tabela);
    return 0;
}