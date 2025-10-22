#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

// Échange deux entiers
void swap_int(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

// Vérifie si le tableau est trié
bool is_sorted_nondecreasing(int T[], int n) {
    for (int i = 0; i < n - 1; i++)
        if (T[i] > T[i + 1])
            return false;
    return true;
}

// Copie un tableau src vers dest
void copy_array(int src[], int dest[], int n) {
    for (int i = 0; i < n; i++)
        dest[i] = src[i];
}
