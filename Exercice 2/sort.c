#include "sort.h"
#include "utils.h"
#include <stdlib.h>

// ------------------------
// Tri itératifs simples
// ------------------------

// Selection Sort
void selection_sort(int A[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++)
            if (A[j] < A[min_idx])
                min_idx = j;
        swap_int(&A[i], &A[min_idx]);
    }
}

// Insertion Sort
void insertion_sort(int A[], int n) {
    for (int i = 1; i < n; i++) {
        int key = A[i];
        int j = i - 1;
        while (j >= 0 && A[j] > key) {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = key;
    }
}

// Bubble Sort
void bubble_sort(int A[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (A[j] > A[j + 1])
                swap_int(&A[j], &A[j + 1]);
        }
    }
}

// ------------------------
// Tri récursifs complexes
// ------------------------

// Merge Sort helper
void merge(int A[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int *L = (int*)malloc(n1 * sizeof(int));
    int *R = (int*)malloc(n2 * sizeof(int));

    for (int i = 0; i < n1; i++) L[i] = A[left + i];
    for (int i = 0; i < n2; i++) R[i] = A[mid + 1 + i];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) A[k++] = L[i++];
        else A[k++] = R[j++];
    }
    while (i < n1) A[k++] = L[i++];
    while (j < n2) A[k++] = R[j++];

    free(L);
    free(R);
}

void merge_sort(int A[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        merge_sort(A, left, mid);
        merge_sort(A, mid + 1, right);
        merge(A, left, mid, right);
    }
}

// Quick Sort helper
int partition(int A[], int low, int high) {
    int pivot = A[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (A[j] <= pivot) {
            i++;
            swap_int(&A[i], &A[j]);
        }
    }
    swap_int(&A[i + 1], &A[high]);
    return i + 1;
}

void quick_sort(int A[], int low, int high) {
    if (low < high) {
        int pi = partition(A, low, high);
        quick_sort(A, low, pi - 1);
        quick_sort(A, pi + 1, high);
    }
}
