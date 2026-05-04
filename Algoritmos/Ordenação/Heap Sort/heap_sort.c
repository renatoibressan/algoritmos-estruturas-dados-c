#include <stdio.h>
#include "heap_sort.h"

void imprime_vetor(const char *mensagem, int v[], int n) {
    printf("%s\n[", mensagem);
    for (int i = 0; i < n; i++) {
        if (i > 0) printf(", ");
        printf("%d", v[i]);
    }
    printf("]\n");
}

void heapify(int v[], int n, int i) {
    int largo = i;
    int esq = 2 * i + 1;
    int dir = 2 * i + 2;
    if (esq < n && v[esq] > v[largo]) largo = esq;
    if (dir < n && v[dir] > v[largo]) largo = dir;
    if (largo != i) {
        int temp = v[i];
        v[i] = v[largo];
        v[largo] = temp;
        heapify(v, n, largo);
    }
}

void heap_sort(int v[], int n) {
    int i;
    for (i = n / 2 - 1; i >= 0; i--) {
        heapify(v, n, i);
    }
    for (i = n - 1; i > 0; i--) {
        int temp = v[0];
        v[0] = v[i];
        v[i] = temp;
        heapify(v, i, 0);
    }
}