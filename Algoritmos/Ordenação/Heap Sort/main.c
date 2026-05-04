#include <stdio.h>
#include <stdlib.h>
#include "heap_sort.h"
#define N 1000000

int main() {
    int *v = NULL, n;
    printf("Insira o tamanho do vetor: ");
    scanf("%d", &n);
    if (n < 0 || n > N) {
        printf("Tamanho invalido!\n(Programa abortado)\n");
        return 1;
    }
    v = (int *)malloc(n*sizeof(int));
    if (!v) {
        printf("Erro ao alocar memoria!\n(Programa abortado)\n");
        return 1;
    }
    for (int i = 0; i < n; i++) {
        printf("Insira o %d-esimo valor do vetor: ", i + 1);
        scanf("%d", &v[i]);
    }
    imprime_vetor("Vetor desordenado:", v, n);
    heap_sort(v, n);
    imprime_vetor("Vetor ordenado com Heap Sort:", v, n);
    free(v);
    return 0;
}