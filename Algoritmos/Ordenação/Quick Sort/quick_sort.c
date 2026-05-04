#include <stdio.h>
#include <stdlib.h>
#include "quick_sort.h"

void imprime_vetor(const char *mensagem, int v[], int n) {
    printf("%s\n[", mensagem);
    for (int i = 0; i < n; i++) {
        if (i > 0) printf(", ");
        printf("%d", v[i]);
    }
    printf("]\n");
}

void troca(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int particao_lomuto(int v[], int inicio, int fim) {
    int pivo = v[fim];
    int i = inicio - 1;
    for (int j = inicio; j < fim; j++) {
        if (v[j] < pivo) {
            i++;
            troca(&v[i], &v[j]);
        }
    }
    troca(&v[i + 1], &v[fim]);
    return (i + 1);
}

int particao_random(int v[], int inicio, int fim) {
    int p = (rand() % (fim - inicio + 1)) + inicio;
    troca(&v[p], &v[fim]);
    return particao_lomuto(v, inicio, fim);
}

void quick_sort(int v[], int inicio, int fim) {
    if (inicio < fim) {
        int p = particao_random(v, inicio, fim);
        quick_sort(v, inicio, p - 1);
        quick_sort(v, p + 1, fim);
    }
}