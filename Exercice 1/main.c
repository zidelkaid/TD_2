#include <stdio.h>
#include <time.h>
#include "utils.h"
#include "search.h"

int main() {
    int T[] = {1, 2, 3, 4, 5};
    int n = 5;

    printf("Tableau trié ? %s\n", is_sorted_nondecreasing(T, n) ? "Oui" : "Non");
    printf("Valeur minimale : %d\n", min_int(T, n));

    int A[] = {1, 3, 5, 7, 9, 11, 13, 15};
    int nA = sizeof(A) / sizeof(A[0]);
    int x = 7;

    printf("Recherche du nombre %d dans le tableau.\n", x);

    printf("Linear Search: index = %d\n", linear_search(A, nA, x));
    printf("Jump Search: index = %d\n", jump_search(A, nA, x));
    printf("Binary Search: index = %d\n", binary_search(A, nA, x));

clock_t start, end;
double cpu_time_used;
// Exemple pour Linear Search
start = clock();
int idx = linear_search(A, nA, x);
end = clock();
cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
printf("Linear Search: index = %d, temps = %f secondes\n", idx, cpu_time_used);

start = clock();
idx = jump_search(A, nA, x);
end = clock();
cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
printf("Jump Search: index = %d, temps = %f secondes\n", idx, cpu_time_used);

start = clock();
idx = binary_search(A, nA, x);
end = clock();
cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
printf("Binary Search: index = %d, temps = %f secondes\n", idx, cpu_time_used);


    return 0;
}