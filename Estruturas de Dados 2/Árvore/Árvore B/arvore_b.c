#include <stdio.h>
#include <stdlib.h>
#include "arvore_b.h"

No* criar(int folha) {
    No *novo = malloc(sizeof(No));
    novo->m = 0;
    novo->folha = folha;
    for (int i = 0; i < 2 * T; i++) {
        novo->filhos[i] = NULL;
    }
    return novo;
}

void dividir_filho(No *pai, int i, No *filho_cheio) {
    No *novo_irmao = criar(filho_cheio->folha);
    novo_irmao->m = T - 1;
    for (int j = 0; j < T - 1; j++) {
        novo_irmao->chaves[j] = filho_cheio->chaves[j + T];
    }
    if (!filho_cheio->folha) {
        for (int j = 0; j < T; j++) {
            novo_irmao->filhos[j] = filho_cheio->filhos[j + T];
        }
    }
    filho_cheio->m = T - 1;
    for (int j = pai->m; j >= i + 1; j--) {
        pai->filhos[j + 1] = pai->filhos[j];
    }
    pai->filhos[i + 1] = novo_irmao;
    for (int j = pai->m - 1; j >= i; j--) {
        pai->chaves[j + 1] = pai->chaves[j];
    }
    pai->chaves[i] = filho_cheio->chaves[T - 1];
    pai->m++;
}

void inserir_nao_cheio(No *no, int k) {
    int i = no->m - 1;
    if (no->folha) {
        while (i >= 0 && no->chaves[i] > k) {
            no->chaves[i + 1] = no->chaves[i];
            i--;
        }
        no->chaves[i + 1] = k;
        no->m++;
    } else {
        while (i >= 0 && no->chaves[i] > k) i--;
        i++;
        if (no->filhos[i]->m == 2 * T - 1) {
            dividir_filho(no, i, no->filhos[i]);
            if (no->chaves[i] < k) i++;
        }
        inserir_nao_cheio(no->filhos[i], k);
    }
}

No *inserir(No *raiz, int k) {
    if (!raiz) {
        raiz = criar(1);
        raiz->chaves[0] = k;
        raiz->m = 1;
        return raiz;
    }
    if (raiz->m == 2 * T - 1) {
        No *nova_raiz = criar(0);
        nova_raiz->filhos[0] = raiz;
        dividir_filho(nova_raiz, 0, raiz);
        int i = (nova_raiz->chaves[0] < k) ? 1 : 0;
        inserir_nao_cheio(nova_raiz->filhos[i], k);
        return nova_raiz;
    } else {
        inserir_nao_cheio(raiz, k);
        return raiz;
    }
}

void percursos(No *raiz) {
    if (!raiz) return;
    int i;
    for (i = 0; i < raiz->m; i++) {
        if (!raiz->folha) percursos(raiz->filhos[i]);
        printf("%d ", raiz->chaves[i]);
    }
    if (!raiz->folha) percursos(raiz->filhos[i]);
}

void liberar(No **raiz) {
    if (!raiz || !(*raiz)) return;
    if (!(*raiz)->folha) {
        for (int i = 0; i <= (*raiz)->m; i++) {
            liberar(&((*raiz)->filhos[i]));
        }
    }
    free(*raiz);
    *raiz = NULL;
}