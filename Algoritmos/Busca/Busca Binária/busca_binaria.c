#include "busca_binaria.h"

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

int busca_binaria(int v[], int n, int x) {
    int esquerda = 0;
    int direita = n - 1;
    while (esquerda <= direita) {
        int centro = esquerda + (direita - esquerda) / 2;
        if (v[centro] == x) return centro;
        else if (v[centro] < x) esquerda = centro + 1;
        else direita = centro - 1;
    }
    return -1;
}