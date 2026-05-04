#include <stdio.h>
#include "potenciacao.h"

int main() {
    int n, x;
    long resultado;
    printf("Insira um numero inteiro e um expoente natural: ");
    if (scanf("%d %d", &n, &x) != 2) {
        printf("Leitura nao suportada!\n(Programa abortado)\n");
        return 1;
    }
    if (x < 0) {
        printf("Valor %d invalido!\n(Programa abortado)\n", x);
        return 1;
    }
    resultado = potenciacao(n, x);
    printf("%d ^ %d = %ld\n", n, x, resultado);
    return 0;
}