#include <stdio.h>
#include <stdlib.h>
#include "lista_estatica.h"

void inicializa_lista(Lista *l) {
    l->qtd = 0;
}

int insere_final(Lista *l, int val) {
    if (l->qtd >= MAX) return 0;
    l->dados[l->qtd] = val;
    l->qtd++;
    return 1;
}

void imprime_lista(const char *mensagem, Lista *l) {
    printf("%s\n[", mensagem);
    for (int i = 0; i < l->qtd; i++) {
        if (i > 0) printf(", ");
        printf("%d", l->dados[i]);
    }
    printf("]\n");
}