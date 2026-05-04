#include <stdio.h>
#include "busca_ternaria.h"

int main() {
    int v[10000], n, x, idx;
    printf("Insira o tamanho do vetor: ");
    scanf("%d", &n);
    if (n < 0 || n > 10000) {
        printf("Tamanho invalido!\n(Programa abortado)\n");
        return 1;
    }
    for (int i = 0; i < n; i++) {
        printf("Insira o %d-esimo valor do vetor: ", i + 1);
        scanf("%d", &v[i]);
    }
    bubble_sort(v, n);
    printf("Insira o valor para ser encontrado: ");
    scanf("%d", &x);
    idx = busca_ternaria(v, 0, n - 1, x);
    (idx != -1) ? printf("O valor %d se encontra no indice %d do vetor\n", x, idx) : printf("O valor %d nao se encontra no vetor\n", x);
    return 0;
}