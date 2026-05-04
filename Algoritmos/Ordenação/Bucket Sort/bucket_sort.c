#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bucket_sort.h"

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

void insertion_sort(int v[], int n) {
    for (int i = 1; i < n; i++) {
        int aux = v[i];
        int j = i - 1;
        while (j >= 0 && v[j] > aux) {
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = aux;
    }
}

void bucket_sort(int v[], int n) {
    int **baldes = calloc(n, sizeof(int *));
    int *tamanhos = calloc(n, sizeof(int));
    int *capacidades = calloc(n, sizeof(int));
    int i;
    for (i = 0; i < n; i++) {
        baldes[i] = malloc(sizeof(int));
        capacidades[i] = 1;
    }
    int maior = maior_elemento_vetor(v, n);
    for (i = 0; i < n; i++) {
        int idx = (int)((long long)v[i] * (n - 1) / maior);
        if (idx >= n) idx = n - 1;
        if (tamanhos[idx] == capacidades[idx]) {
            capacidades[idx] *= 2;
            baldes[idx] = realloc(baldes[idx], capacidades[idx]*sizeof(int));
        }
        baldes[idx][tamanhos[idx]++] = v[i];
    }
    int pos = 0;
    for (i = 0; i < n; i++) {
        insertion_sort(baldes[i], tamanhos[i]);
        memcpy(v + pos, baldes[i], tamanhos[i]*sizeof(int));
        pos += tamanhos[i];
        free(baldes[i]);
    }
    free(baldes);
    free(tamanhos);
    free(capacidades);
}