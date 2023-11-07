#ifndef RADIXSORT_P
#define RADIXSORT_P

#include <iostream>
#include <algorithm>
#include <cmath>
#include <climits>

constexpr int decimal_p = 10;

void counting_sort_p(int* arr, int size, int* output, int k) {

    int pos[decimal_p] = {};

    for(int incr_elem = 0; incr_elem < size; ++incr_elem) {
        pos[arr[incr_elem]/k%10] += 1;
    }

    for(int add_elem = 1; add_elem < decimal_p; ++add_elem) {
        pos[add_elem] += pos[add_elem-1];
    }

    for(int i = size-1; i >= 0; --i) {
        pos[arr[i]/k%10] -= 1;
        output[pos[arr[i]/k%10]] = arr[i];
    }

    for(int count = 0; count < size; ++count) {
        arr[count] = output[count];
    }

}



void radixsort_p(int* arr, int size) {

    int* output = new int[size];

    int max_elem = *(std::max_element(arr, arr+size));

    int div = 1;
    while(max_elem > 0) {
        counting_sort_p(arr, size, output, div);

        div *= 10;
        max_elem /= 10;
    }


    delete [] output;
}



#endif

