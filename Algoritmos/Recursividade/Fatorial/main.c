#include <stdio.h>
#include "fatorial.h"

int main() {
    int n;
    unsigned long int resultado;
    printf("Insira um numero natural: ");
    if (scanf("%d", &n) != 1) {
        printf("Leitura nao suportada!\n(Programa abortado)\n");
        return 1;
    }
    if (n < 0) {
        printf("Valor %d invalido!\n(Programa abortado)\n", n);
        return 1;
    }
    resultado = fatorial(n);
    printf("%d! = %lu\n", n, resultado);
    return 0;
}