#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "arvore_patricia.h"

int get_bit(const char *chave, int bit_idx) {
    int byte_idx = bit_idx / 8;
    int bit_pos = 7 - (bit_idx % 8);
    return (chave[byte_idx] >> bit_pos) & 1;
}

No* criar(int bit_idx, char *chave) {
    No *novo = malloc(sizeof(No));
    novo->bit_idx = bit_idx;
    novo->chave = strdup(chave);
    novo->esquerda = novo;
    novo->direita = NULL;
    return novo;
}

int primeiro_bit_diferente(const char *k1, const char *k2) {
    int i = 0;
    while (k1[i] == k2[i] && k1[i] != '\0' && k2[i] != '\0') i++;
    int bit_idx = i * 8;
    while (get_bit(k1, bit_idx) == get_bit(k2, bit_idx)) bit_idx++;
    return bit_idx;
}

No* inserir(No **raiz, char *chave) {
    if (!(*raiz)) {
        *raiz = criar(-1, "");
        No *novo = criar(0, chave);
        (*raiz)->esquerda = novo;
        novo->esquerda = novo;
        return novo;
    }
    No *pai = *raiz;
    No *filho = (*raiz)->esquerda;
    while (filho->bit_idx > pai->bit_idx) {
        pai = filho;
        filho = (get_bit(chave, filho->bit_idx) == 0) ? filho->esquerda : filho->direita;
    }
    if (strcmp(filho->chave, chave) == 0) return filho;
    int bit_dif = primeiro_bit_diferente(chave, filho->chave);
    pai = *raiz;
    filho = (*raiz)->esquerda;
    while (filho->bit_idx > pai->bit_idx && filho->bit_idx < bit_dif) {
        pai = filho;
        filho = (get_bit(chave, filho->bit_idx) == 0) ? filho->esquerda : filho->direita;
    }
    No *novo = criar(bit_dif, chave);
    if (get_bit(chave, bit_dif) == 0) {
        novo->esquerda = novo;
        novo->direita = filho;
    } else {
        novo->esquerda = filho;
        novo->direita = novo;
    }
    if (pai == *raiz) (*raiz)->esquerda = novo;
    else if (get_bit(chave, pai->bit_idx) == 0) pai->esquerda = novo;
    else pai->direita = novo;
    return novo;
}

No* buscar(No *raiz, const char *chave) {
    if (!raiz) return NULL;
    No *pai = raiz;
    No *filho = raiz->esquerda;
    while (filho->bit_idx > pai->bit_idx) {
        pai = filho;
        filho = (get_bit(chave, filho->bit_idx) == 0) ? filho->esquerda : filho->direita;
    }
    if (strcmp(filho->chave, chave) == 0) return filho;
    return NULL;
}

void percursos(No *atual, int bit_idx_pai) {
    if (!atual || atual->bit_idx <= bit_idx_pai) return;
    percursos(atual->esquerda, atual->bit_idx);
    if (atual->esquerda->bit_idx <= atual->bit_idx) printf("Chave: %s (Endereco %p)\n", atual->esquerda->chave, (void*)atual->esquerda);
    if (atual->direita && atual->direita->bit_idx <= atual->bit_idx) printf("Chave: %s (Endereco %p)\n", atual->direita->chave, (void*)atual->direita);
    if (atual->direita) percursos(atual->direita, atual->bit_idx);
}

void exibir(No *raiz) {
    if (raiz && raiz->esquerda) percursos(raiz->esquerda, raiz->bit_idx);
}

void liberar_nos(No *atual, int bit_idx_pai) {
    if (!atual || atual->bit_idx <= bit_idx_pai) return;
    No *esq = atual->esquerda;
    No *dir = atual->direita;
    int bit_atual = atual->bit_idx;
    liberar_nos(esq, bit_atual);
    if (dir) liberar_nos(dir, bit_atual);
    free(atual->chave);
    free(atual);
}

void liberar(No **raiz) {
    if (*raiz) {
        liberar_nos((*raiz)->esquerda, (*raiz)->bit_idx);
        free((*raiz)->chave);
        free(*raiz);
        *raiz = NULL;
    }
}