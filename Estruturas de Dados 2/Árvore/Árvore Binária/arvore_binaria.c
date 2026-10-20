#include <stdio.h>
#include <stdlib.h>
#include "arvore_binaria.h"

void menu() {
    printf("1. Adicionar a arvore\n");
    printf("2. Buscar na arvore\n");
    printf("3. Remover da arvore\n");
    printf("0. Encerrar o programa\n");
    printf("Insira a opcao desejada: ");
}

No* criar(int val) {
    No *novo = malloc(sizeof(No));
    novo->dado = val;
    novo->esquerda = NULL;
    novo->direita = NULL;
    return novo;
}

No* inserir(No *raiz, int val) {
    if (!raiz) {
        No *novo = malloc(sizeof(No));
        novo->dado = val;
        novo->esquerda = novo->direita = NULL;
        return novo;
    }
    if (val < raiz->dado) raiz->esquerda = inserir(raiz->esquerda, val);
    else if (val > raiz->dado) raiz->direita = inserir(raiz->direita, val);
    return raiz;
}

No* buscar(No *raiz, int val) {
    if (!raiz || raiz->dado == val) return raiz;
    if (val > raiz->dado) return buscar(raiz->direita, val);
    return buscar(raiz->esquerda, val);
}

No* minimo(No *no) {
    No *atual = no;
    while (atual && atual->esquerda) atual = atual->esquerda;
    return atual;
}

No* remover(No *raiz, int val) {
    if (!raiz) return raiz;
    if (val < raiz->dado) raiz->esquerda = remover(raiz->esquerda, val);
    else if (val > raiz->dado) raiz->direita = remover(raiz->direita, val);
    else {
        if (!raiz->esquerda) {
            No *temp = raiz->direita;
            free(raiz);
            return temp;
        } else if (!raiz->direita) {
            No *temp = raiz->esquerda;
            free(raiz);
            return temp;
        }
        No *temp = minimo(raiz->direita);
        raiz->dado = temp->dado;
        raiz->direita = remover(raiz->direita, temp->dado);
    }
    return raiz;
}

void percursos(No *raiz) {
    if (!raiz) return;
    percursos(raiz->esquerda);
    printf("%d ", raiz->dado);
    percursos(raiz->direita);
}

void liberar(No **raiz) {
    if (!raiz || !(*raiz)) return;
    liberar(&((*raiz)->esquerda));
    liberar(&((*raiz)->direita));
    free(*raiz);
    *raiz = NULL;
}