#include <stdio.h>
#include "radix_sort.h"
#define N 100000

int main() {
    int v[N], n;
    printf("Insira o tamanho do vetor: ");
    scanf("%d", &n);
    if (n < 0 || n > N) {
        printf("Tamanho invalido!\n(Programa abortado)\n");
        return 1;
    }
    for (int i = 0; i < n; i++) {
        printf("Insira o %d-esimo valor do vetor: ", i + 1);
        scanf("%d", &v[i]);
    }
    imprime_vetor("Vetor desordenado:", v, n);
    radix_sort(v, n);
    imprime_vetor("Vetor ordenado com Radix Sort:", v, n);
    return 0;
}