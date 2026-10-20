#include <stdio.h>
#include <stdlib.h>
#include "arvore_avl.h"

int altura(No *raiz) {
    if (!raiz) return 0;
    return raiz->altura;
}

int maior(int a, int b) {
    return (a > b) ? a : b;
}

No* criar(int val) {
    No *novo = malloc(sizeof(No));
    novo->dado = val;
    novo->esquerda = NULL;
    novo->direita = NULL;
    novo->altura = 1;
    return novo;
}

int fator_balanceamento(No *raiz) {
    if (!raiz) return 0;
    return altura(raiz->esquerda) - altura(raiz->direita);
}

No* rotacionar_esquerda(No *x) {
    No *y = x->direita;
    No *t2 = y->esquerda;
    y->esquerda = x;
    x->direita = t2;
    x->altura = maior(altura(x->esquerda), altura(x->direita)) + 1;
    y->altura = maior(altura(y->esquerda), altura(y->direita)) + 1;
    return y;
}

No* rotacionar_direita(No *y) {
    No *x = y->esquerda;
    No *t2 = x->direita;
    x->direita = y;
    y->esquerda = t2;
    y->altura = maior(altura(y->esquerda), altura(y->direita)) + 1;
    x->altura = maior(altura(x->esquerda), altura(x->direita)) + 1;
    return x;
}

No* inserir(No *raiz, int val) {
    if (!raiz) return criar(val);
    if (val < raiz->dado) raiz->esquerda = inserir(raiz->esquerda, val);
    else if (val > raiz->dado) raiz->direita = inserir(raiz->direita, val);
    else return raiz;
    raiz->altura = 1 + maior(altura(raiz->esquerda), altura(raiz->direita));
    int balance = fator_balanceamento(raiz);
    if (balance > 1 && val < raiz->esquerda->dado) return rotacionar_direita(raiz);
    if (balance < -1 && val > raiz->direita->dado) return rotacionar_esquerda(raiz);
    if (balance > 1 && val > raiz->esquerda->dado) {
        raiz->esquerda = rotacionar_esquerda(raiz->esquerda);
        return rotacionar_direita(raiz);
    }
    if (balance < -1 && val < raiz->direita->dado) {
        raiz->direita = rotacionar_direita(raiz->direita);
        return rotacionar_esquerda(raiz);
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