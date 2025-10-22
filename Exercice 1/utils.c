#include <stdio.h>
#include <stdbool.h>

 bool is_sorted_nondecreasing(int T[], int n){
    for (int i = 0; i < n - 1; i++){
        if (T[i+1] < T[i]){
            return false;}
        }
    return true;        
}

int min_int (int T[], int n){ 
    int min = T[0];
    for (int i = 1; i < n; i++){
        if (T[i] < min)
            {int min = T[i];
        }
    }
    return min;
}