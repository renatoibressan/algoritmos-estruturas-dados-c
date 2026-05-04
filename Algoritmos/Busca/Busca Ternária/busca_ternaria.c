#include "busca_ternaria.h"

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

int busca_ternaria(int v[], int inicial, int final, int x) {
    if (final >= inicial) {
        int m1 = inicial + (final - inicial) / 3;
        int m2 = final - (final - inicial) / 3;
        if (v[m1] == x) return m1;
        if (v[m2] == x) return m2;
        if (x < v[m1]) return busca_ternaria(v, inicial, m1 - 1, x);
        else if (x > v[m2]) return busca_ternaria(v, m2 + 1, final, x);
        else return busca_ternaria(v, m1 + 1, m2 - 1, x);
    }
    return -1;
}