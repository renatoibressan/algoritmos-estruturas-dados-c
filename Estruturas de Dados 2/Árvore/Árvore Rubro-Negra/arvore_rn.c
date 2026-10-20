#include <stdio.h>
#include <stdlib.h>
#include "arvore_rn.h"

No* criar(int val) {
    No *novo = malloc(sizeof(No));
    novo->dado = val;
    novo->cor = VERMELHO;
    novo->esquerda = NULL;
    novo->direita = NULL;
    novo->pai = NULL;
    return novo;
}

void rotacionar_esquerda(No **raiz, No *x) {
    No *y = x->direita;
    x->direita = y->esquerda;
    if (y->esquerda) y->esquerda->pai = x;
    y->pai = x->pai;
    if (!x->pai) *raiz = y;
    else if (x == x->pai->esquerda) x->pai->esquerda = y;
    else x->pai->direita = y;
    y->esquerda = x;
    x->pai = y;
}

void rotacionar_direita(No **raiz, No *y) {
    No *x = y->esquerda;
    y->esquerda = x->direita;
    if (x->direita) x->direita->pai = y;
    x->pai = y->pai;
    if (!y->pai) *raiz = x;
    else if (y == y->pai->esquerda) y->pai->esquerda = x;
    else y->pai->direita = x;
    x->direita = y;
    y->pai = x;
}

void corrigir_insercao(No **raiz, No *z) {
    while (z != *raiz && z->pai->cor == VERMELHO) {
        if (z->pai == z->pai->pai->esquerda) {
            No *y = z->pai->pai->direita;
            if (y && y->cor == VERMELHO) {
                z->pai->cor = PRETO;
                y->cor = PRETO;
                z->pai->pai->cor = VERMELHO;
                z = z->pai->pai;
            } else {
                if (z == z->pai->direita) {
                    z = z->pai;
                    rotacionar_esquerda(raiz, z);
                }
                z->pai->cor = PRETO;
                z->pai->pai->cor = VERMELHO;
                rotacionar_direita(raiz, z->pai->pai);
            }
        } else {
            No *y = z->pai->pai->esquerda;
            if (y && y->cor == VERMELHO) {
                z->pai->cor = PRETO;
                y->cor = PRETO;
                z->pai->pai->cor = VERMELHO;
                z = z->pai->pai;
            } else {
                if (z == z->pai->esquerda) {
                    z = z->pai;
                    rotacionar_direita(raiz, z);
                }
                z->pai->cor = PRETO;
                z->pai->pai->cor = VERMELHO;
                rotacionar_esquerda(raiz, z->pai->pai);
            }
        }
    } 
    (*raiz)->cor = PRETO;
}

void inserir(No **raiz, int val) {
    No *z = criar(val);
    No *y = NULL;
    No *x = *raiz;
    while (x) {
        y = x;
        if (z->dado < x->dado) x = x->esquerda;
        else x = x->direita;
    }
    z->pai = y;
    if (!y) *raiz = z;
    else if (z->dado < y->dado) y->esquerda = z;
    else y->direita = z;
    corrigir_insercao(raiz, z);
}

void percursos(No *raiz) {
    if (!raiz) return;
    percursos(raiz->esquerda);
    printf("%d(%s) ", raiz->dado, raiz->cor == VERMELHO ? "V" : "P");
    percursos(raiz->direita);
}

void liberar(No **raiz) {
    if (!raiz || !(*raiz)) return;
    liberar(&((*raiz)->esquerda));
    liberar(&((*raiz)->direita));
    free(*raiz);
    *raiz = NULL;
}