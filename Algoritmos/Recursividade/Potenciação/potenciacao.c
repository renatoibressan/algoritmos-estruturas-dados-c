#include "potenciacao.h"

long potenciacao(int n, int x) {
    if (x == 0) return 1;
    return n * potenciacao(n, x - 1);
}