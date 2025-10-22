#include <stdio.h>
#include <math.h>

int linear_search(int A[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (A[i] == x) {
            return i; 
        }
    }
    return -1; 
}

int jump_search(int A[], int n, int x) {
    int step = (int)sqrt(n); // taille du saut
    int prev = 0;

    // Trouver le bloc où peut se trouver x
    while (A[(step < n ? step : n) - 1] < x) {
        prev = step;
        step += (int)sqrt(n);
        if (prev >= n)
            return -1;
    }

    // Recherche linéaire dans le bloc
    for (int i = prev; i < (step < n ? step : n); i++) {
        if (A[i] == x)
            return i;
    }

    return -1;
}

int binary_search(int A[], int n, int x) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2; // évite overflow
        if (A[mid] == x)
            return mid;
        else if (A[mid] < x)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1; // élément non trouvé
}