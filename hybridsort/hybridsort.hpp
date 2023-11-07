#ifndef HYBRID_SORT
#define HYBRID_SORT


#include <iostream> 
#include "../quicksort/quicksort.hpp"
#include "../radixsort/radixsort.hpp"
#include "../radixsort/radixsort_positive.hpp"


void hybridsort(int* arr, int size) {
    int min = arr[0];
    int max = arr[0];
    bool is_sorted = true;


    for(int i = 0; i < size; ++i) {
        if(arr[i] < min) {
            min = arr[i];
        }
        if(arr[i] > max) {
            max = arr[i];
        }
        if(i < size-1) {
            if(arr[i] > arr[i + 1]) {
                is_sorted = false;
            }
        }
    }

    if(!is_sorted) {
        if((max - min) > 100) {
            quicksort(arr, size);
        }
        else {
            if(min >= 0) {
                radixsort_p(arr, size);
            }
            else {  
                radixsort(arr, size);
            }
        }
    }
}

#endif
