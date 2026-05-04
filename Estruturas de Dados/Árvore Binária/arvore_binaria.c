#include <stdio.h>
#include <stdlib.h>
#include "arvore_binaria.h"

No* criar(int val) {
    No *novo = malloc(sizeof(No));
    novo->dado = val;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}

No* inserir(No *raiz, int val) {
    if (!raiz) {
        No *novo = malloc(sizeof(No));
        novo->dado = val;
        novo->esq = novo->dir = NULL;
        return novo;
    }
    if (val < raiz->dado) raiz->esq = inserir(raiz->esq, val);
    else if (val > raiz->dado) raiz->dir = inserir(raiz->dir, val);
    return raiz;
}

No* buscar(No *raiz, int val) {
    if (!raiz || raiz->dado == val) return raiz;
    if (val > raiz->dado) return buscar(raiz->dir, val);
    return buscar(raiz->esq, val);
}

No* minimo(No *no) {
    No *atual = no;
    while (atual && atual->esq) atual = atual->esq;
    return atual;
}

No* remover(No *raiz, int val) {
    if (!raiz) return raiz;
    if (val < raiz->dado) raiz->esq = remover(raiz->esq, val);
    else if (val > raiz->dado) raiz->dir = remover(raiz->dir, val);
    else {
        if (!raiz->esq) {
            No *temp = raiz->dir;
            free(raiz);
            return temp;
        } else if (!raiz->dir) {
            No *temp = raiz->esq;
            free(raiz);
            return temp;
        }
        No *temp = minimo(raiz->dir);
        raiz->dado = temp->dado;
        raiz->dir = remover(raiz->dir, temp->dado);
    }
    return raiz;
}

void percursos(No *raiz) {
    if (!raiz) return;
    percursos(raiz->esq);
    printf("%d ", raiz->dado);
    percursos(raiz->dir);
}

void liberar(No *raiz) {
    if (!raiz) return;
    liberar(raiz->esq);
    liberar(raiz->dir);
    free(raiz);
    raiz = NULL;
}