#ifndef ARVORE_B_H
#define ARVORE_B_H

#define T 3

typedef struct no {
    int m;
    int chaves[2 * T - 1];
    struct no *filhos[2 * T];
    int folha;
} No;

No* criar(int folha);
void dividir_filho(No *pai, int i, No *filho_cheio);
void inserir_nao_cheio(No *no, int k);
No *inserir(No *raiz, int k);
void percursos(No *raiz);
void liberar(No **raiz);

#endif