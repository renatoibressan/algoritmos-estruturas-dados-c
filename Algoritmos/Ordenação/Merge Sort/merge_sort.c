#include <stdio.h>
#include "merge_sort.h"

void imprime_vetor(const char *mensagem, int v[], int n) {
    printf("%s\n[", mensagem);
    for (int i = 0; i < n; i++) {
        if (i > 0) printf(", ");
        printf("%d", v[i]);
    }
    printf("]\n");
}

void merge(int v[], int aux[], int inicio, int meio, int fim) {
    int k, j;
    for (k = inicio; k <= fim; k++) {
        aux[k] = v[k];
    }
    j = meio + 1;
    for (k = inicio; k <= fim; k++) {
        if (inicio > meio) v[k] = aux[j++];
        else if (j > fim) v[k] = aux[inicio++];
        else if (aux[inicio] <= aux[j]) v[k] = aux[inicio++];
        else v[k] = aux[j++];
    }
}

void merge_sort(int v[], int aux[], int inicio, int fim) {
    if (fim > inicio) {
        int meio = (inicio + fim) / 2;
        merge_sort(v, aux, inicio, meio);
        merge_sort(v, aux, meio + 1, fim);
        merge(v, aux, inicio, meio, fim);
    }
    return;
}