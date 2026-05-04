#include <stdio.h>
#include "bubble_sort.h"

void imprime_vetor(const char *mensagem, int v[], int n) {
    printf("%s\n[", mensagem);
    for (int i = 0; i < n; i++) {
        if (i > 0) printf(", ");
        printf("%d", v[i]);
    }
    printf("]\n");
}

void bubble_sort(int v[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (v[j] > v[j + 1]) {
                int temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
            }
        }
    }
}