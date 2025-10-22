#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "utils.h"
#include "sort.h"

#define SIZE 10000 // taille du tableau

int main() {
    int original[SIZE];
    for (int i = 0; i < SIZE; i++)
        original[i] = rand() % 100000;

    int temp[SIZE];
    clock_t start, end;
    double time_taken;

    // Selection Sort
    copy_array(original, temp, SIZE);
    start = clock();
    selection_sort(temp, SIZE);
    end = clock();
    time_taken = (double)(end - start)/CLOCKS_PER_SEC;
    printf("Selection Sort: %f secondes\n", time_taken);

    // Insertion Sort
    copy_array(original, temp, SIZE);
    start = clock();
    insertion_sort(temp, SIZE);
    end = clock();
    time_taken = (double)(end - start)/CLOCKS_PER_SEC;
    printf("Insertion Sort: %f secondes\n", time_taken);

    // Bubble Sort
    copy_array(original, temp, SIZE);
    start = clock();
    bubble_sort(temp, SIZE);
    end = clock();
    time_taken = (double)(end - start)/CLOCKS_PER_SEC;
    printf("Bubble Sort: %f secondes\n", time_taken);

    // Merge Sort
    copy_array(original, temp, SIZE);
    start = clock();
    merge_sort(temp, 0, SIZE - 1);
    end = clock();
    time_taken = (double)(end - start)/CLOCKS_PER_SEC;
    printf("Merge Sort: %f secondes\n", time_taken);

    // Quick Sort
    copy_array(original, temp, SIZE);
    start = clock();
    quick_sort(temp, 0, SIZE - 1);
    end = clock();
    time_taken = (double)(end - start)/CLOCKS_PER_SEC;
    printf("Quick Sort: %f secondes\n", time_taken);

    return 0;
}
