#include <stdio.h>
#include "selection_sort.h"

void imprime_vetor(const char *mensagem, int v[], int n) {
    printf("%s\n[", mensagem);
    for (int i = 0; i < n; i++) {
        if (i > 0) printf(", ");
        printf("%d", v[i]);
    }
    printf("]\n");
}

void selection_sort(int v[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int idx_min = i;
        for (int j = i + 1; j < n; j++) {
            if (v[j] < v[idx_min]) idx_min = j;
        }
        if (idx_min != i) {
            int temp = v[i];
            v[i] = v[idx_min];
            v[idx_min] = temp;
        }
    }
}