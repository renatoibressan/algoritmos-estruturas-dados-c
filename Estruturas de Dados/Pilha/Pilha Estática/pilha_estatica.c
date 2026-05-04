#include <stdio.h>
#include <stdlib.h>
#include "pilha_estatica.h"

void inicializa_pilha(Pilha *p) {
    p->topo = -1;
}

int esta_cheia(Pilha *p) {
    return (p->topo == MAX - 1);
}

int esta_vazia(Pilha *p) {
    return (p->topo == -1);
}

int push(Pilha *p, int val) {
    if (esta_cheia(p)) return 0;
    p->dados[++(p->topo)] = val;
    return 1;
}

int pop(Pilha *p, int *val) {
    if (esta_vazia(p)) return 0;
    *val = p->dados[p->topo];
    p->topo--;
    return 1;
}

int peek(Pilha *p) {
    return p->dados[p->topo];
}

void imprime_pilha(const char *mensagem, Pilha *p) {
    printf("%s\n", mensagem);
    for (int i = p->topo; i >= 0; i--) {
        printf("[%d]\n", p->dados[i]);
    }
}