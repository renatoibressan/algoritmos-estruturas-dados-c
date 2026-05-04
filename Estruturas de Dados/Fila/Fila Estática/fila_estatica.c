#include <stdio.h>
#include <stdlib.h>
#include "fila_estatica.h"

void inicializa_fila(Fila *f) {
    f->inicio = f->fim = f->tam = 0;
}

int esta_cheia(Fila *f) {
    return (f->tam == MAX);
}

int esta_vazia(Fila *f) {
    return (f->tam == 0);
}

int enqueue(Fila *f, int val) {
    if (esta_cheia(f)) return 0;
    f->dados[f->fim] = val;
    f->fim = (f->fim + 1) % MAX;
    f->tam++;
    return 1;
}

int dequeue(Fila *f, int *val) {
    if (esta_vazia(f)) return 0;
    *val = f->dados[f->inicio];
    f->inicio = (f->inicio + 1) % MAX;
    f->tam--;
    return 1;
}

void imprime_fila(const char *mensagem, Fila *f) {
    printf("%s\n{", mensagem);
    int idx = f->inicio;
    for (int i = 0; i < f->tam; i++) {
        if (i > 0) printf(" -- ");
        printf("%d", f->dados[idx]);
        idx = (idx + 1) % MAX;
    }
    printf("}\n");
}