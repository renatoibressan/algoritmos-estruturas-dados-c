#include <stdio.h>
#include <stdlib.h>
#include "tabela_hash.h"

int hash(int chave) {
    return chave % TAMANHO;
}

void inicializar_tabela(No *tabela[]) {
    for (int i = 0; i < TAMANHO; i++) tabela[i] = NULL;
}

void inserir(No *tabela[], int chave, int val) {
    int idx = hash(chave);
    No *novo = malloc(sizeof(No));
    novo->chave = chave;
    novo->dado = val;
    novo->prox = tabela[idx];
    tabela[idx] = novo;
}

int buscar(No *tabela[], int chave) {
    int idx = hash(chave);
    No *temp = tabela[idx];
    while (temp) {
        if (temp->chave == chave) return temp->dado;
        temp = temp->prox;
    }
    return -1;
}

void imprimir(const char *mensagem, No *tabela[]) {
    printf("%s\n", mensagem);
    for (int i = 0; i < TAMANHO; i++) {
        printf("Balde %d: ", i);
        No *atual = tabela[i];
        while (atual) {
            printf("[%d: %d] -> ", atual->chave, atual->dado);
            atual = atual->prox;
        }
        printf("NULL\n");
    }
}