#include <stdio.h>
#include "mdc.h"

int main() {
    int a, b, gcd;
    unsigned long int lcm;
    printf("Insira dois numeros naturais: ");
    if (scanf("%d %d", &a, &b) != 2) {
        printf("Leitura nao suportada!\n(Programa abortado)\n");
        return 1;
    }
    if (a < 0 || b < 0) {
        printf("Valor(es) ");
        if (a < 0) printf("%d ", a);
        if (b < 0) printf("%d ", b);
        printf("invalido(s)!\n(Programa abortado)\n");
        return 1;
    }
    gcd = mdc(a, b);
    lcm = mmc(a, b);
    printf("mdc(%d, %d) = %d\n", a, b, gcd);
    printf("mmc(%d, %d) = %lu\n", a, b, lcm);
    return 0;
}