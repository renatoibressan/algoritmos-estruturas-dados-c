#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "radix_sort.h"

void imprime_vetor(const char *mensagem, int v[], int n) {
    printf("%s\n[", mensagem);
    for (int i = 0; i < n; i++) {
        if (i > 0) printf(", ");
        printf("%d", v[i]);
    }
    printf("]\n");
}

int maior_elemento_vetor(int v[], int n) {
    int maior = v[0];
    for (int i = 1; i < n; i++) {
        if (v[i] > maior) maior = v[i];
    }
    return maior;
}

void digit_sort(int v[], int n, int exp) {
    int *saida = malloc(n*sizeof(int));
    int count[10] = {0};
    int i;
    for (i = 0; i < n; i++) {
        count[(v[i] / exp) % 10]++;
    }
    for (i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }
    for (i = n - 1; i >= 0; i--) {
        int digit = (v[i] / exp) % 10;
        saida[--count[digit]] = v[i];
    }
    memcpy(v, saida, n*sizeof(int));
    free(saida);
}

void radix_sort(int v[], int n) {
    int maior = maior_elemento_vetor(v, n);
    for (int exp = 1; (maior / exp) > 0; exp *= 10) {
        digit_sort(v, n, exp);
    }
}