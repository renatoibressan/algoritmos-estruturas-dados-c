#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "quick_sort.h"
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
    srand(time(NULL));
    imprime_vetor("Vetor desordenado:", v, n);
    quick_sort(v, 0, n - 1);
    imprime_vetor("Vetor ordenado com Quick Sort:", v, n);
    free(v);
    return 0;
}