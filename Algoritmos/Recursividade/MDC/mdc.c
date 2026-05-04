#include "mdc.h"

int mdc(int a, int b) {
    if (b == 0) return a;
    return mdc(b, a % b);
}

unsigned long int mmc(int a, int b) {
    if (a == 0 || b == 0) return 0;
    return (a * b) / mdc(a, b);
}